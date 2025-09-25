
int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  EVP_MD_CTX *out;
  int iVar1;
  EVP_MD *pEVar2;
  int iVar3;
  BIO *pBVar4;
  PKCS7_SIGNER_INFO *si;
  int iVar5;
  uchar *md;
  ASN1_TYPE *pAVar6;
  long lVar7;
  pkcs7_st *ppVar8;
  stack_st_PKCS7_SIGNER_INFO *psVar9;
  ASN1_OCTET_STRING *local_78;
  EVP_MD_CTX *local_70;
  uint local_6c;
  void *local_68 [17];
  
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x80,0x8f,"crypto/pkcs7/pk7_doit.c",0x291);
    return 0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x80,0x7a,"crypto/pkcs7/pk7_doit.c",0x296);
    return 0;
  }
  out = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (out == (EVP_MD_CTX *)0x0) {
    ERR_put_error(0x21,0x80,0x41,"crypto/pkcs7/pk7_doit.c",0x29c);
    return 0;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar1) {
  case 0x15:
    local_78 = (p7->d).data;
    break;
  case 0x16:
    ppVar8 = ((p7->d).sign)->contents;
    psVar9 = ((p7->d).sign)->signer_info;
    iVar1 = OBJ_obj2nid(ppVar8->type);
    if (iVar1 == 0x15) {
      local_78 = (ppVar8->d).data;
    }
    else {
      iVar1 = OBJ_obj2nid(ppVar8->type);
      if (iVar1 - 0x15U < 6) {
LAB_001443d8:
        local_78 = (ASN1_STRING *)0x0;
      }
      else {
        local_78 = (ppVar8->d).data;
        if (local_78 != (ASN1_OCTET_STRING *)0x0) {
          if (local_78->length != 4) goto LAB_001443d8;
          local_78 = (ASN1_OCTET_STRING *)local_78->type;
        }
      }
    }
    iVar1 = OBJ_obj2nid(((p7->d).sign)->contents->type);
    if ((iVar1 == 0x15) && (p7->detached != 0)) {
      ASN1_OCTET_STRING_free(local_78);
      local_78 = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    goto LAB_001442f0;
  case 0x17:
    local_78 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (local_78 == (ASN1_STRING *)0x0) {
      local_78 = ASN1_OCTET_STRING_new();
      if (local_78 == (ASN1_OCTET_STRING *)0x0) {
        iVar3 = 0x2ba;
LAB_00144628:
        iVar1 = 0;
        ERR_put_error(0x21,0x80,0x41,"crypto/pkcs7/pk7_doit.c",iVar3);
        goto LAB_001442aa;
      }
      ((p7->d).enveloped)->enc_data->enc_data = local_78;
    }
    break;
  case 0x18:
    psVar9 = ((p7->d).sign)->signer_info;
    local_78 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (local_78 == (ASN1_OCTET_STRING *)0x0) {
      local_78 = ASN1_OCTET_STRING_new();
      if (local_78 == (ASN1_OCTET_STRING *)0x0) {
        iVar3 = 0x2ae;
        goto LAB_00144628;
      }
      ((p7->d).signed_and_enveloped)->enc_data->enc_data = local_78;
    }
LAB_001442f0:
    if (psVar9 != (stack_st_PKCS7_SIGNER_INFO *)0x0) {
      iVar1 = 0;
      while (iVar3 = OPENSSL_sk_num(psVar9), iVar1 < iVar3) {
        si = (PKCS7_SIGNER_INFO *)OPENSSL_sk_value(psVar9,iVar1);
        if (si->pkey == (EVP_PKEY *)0x0) {
LAB_00144412:
          iVar1 = iVar1 + 1;
        }
        else {
          iVar3 = OBJ_obj2nid(si->digest_alg->algorithm);
          pBVar4 = bio;
          while( true ) {
            pBVar4 = BIO_find_type(pBVar4,0x208);
            if (pBVar4 == (BIO *)0x0) goto LAB_00144366;
            BIO_ctrl(pBVar4,0x78,0,&local_70);
            if (local_70 == (EVP_MD_CTX *)0x0) goto LAB_0014446c;
            pEVar2 = EVP_MD_CTX_md(local_70);
            iVar5 = EVP_MD_type(pEVar2);
            if (iVar3 == iVar5) break;
            pBVar4 = BIO_next(pBVar4);
          }
          iVar3 = EVP_MD_CTX_copy_ex(out,local_70);
          if (iVar3 == 0) goto LAB_00144372;
          iVar3 = OPENSSL_sk_num(si->auth_attr);
          if (iVar3 < 1) {
            local_68[0] = (void *)EVP_PKEY_size(si->pkey);
            md = (uchar *)CRYPTO_malloc((int)local_68[0],"crypto/pkcs7/pk7_doit.c",0x2fc);
            if (md != (uchar *)0x0) {
              iVar3 = EVP_SignFinal(out,md,(uint *)local_68,si->pkey);
              if (iVar3 != 0) {
                ASN1_STRING_set0(si->enc_digest,md,(int)local_68[0]);
                goto LAB_00144412;
              }
              CRYPTO_free(md);
              ERR_put_error(0x21,0x80,6,"crypto/pkcs7/pk7_doit.c",0x302);
            }
            goto LAB_00144372;
          }
          pAVar6 = PKCS7_get_signed_attribute(si,0x34);
          if ((pAVar6 == (ASN1_TYPE *)0x0) &&
             (iVar3 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0), iVar3 == 0)) {
            iVar1 = 0x26f;
LAB_00144498:
            ERR_put_error(0x21,0x88,0x41,"crypto/pkcs7/pk7_doit.c",iVar1);
            goto LAB_00144372;
          }
          iVar3 = EVP_DigestFinal_ex(out,(uchar *)local_68,&local_6c);
          if (iVar3 == 0) {
            ERR_put_error(0x21,0x88,6,"crypto/pkcs7/pk7_doit.c",0x276);
            goto LAB_00144372;
          }
          iVar3 = PKCS7_add1_attrib_digest(si,(uchar *)local_68,local_6c);
          if (iVar3 == 0) {
            iVar1 = 0x27a;
            goto LAB_00144498;
          }
          iVar3 = PKCS7_SIGNER_INFO_sign(si);
          if (iVar3 == 0) goto LAB_00144372;
          iVar1 = iVar1 + 1;
        }
      }
    }
    break;
  case 0x19:
    ppVar8 = ((p7->d).digest)->contents;
    iVar1 = OBJ_obj2nid(ppVar8->type);
    if (iVar1 == 0x15) {
      local_78 = (ppVar8->d).data;
    }
    else {
      iVar1 = OBJ_obj2nid(ppVar8->type);
      if (iVar1 - 0x15U < 6) {
LAB_001443d2:
        local_78 = (ASN1_STRING *)0x0;
      }
      else {
        local_78 = (ppVar8->d).data;
        if (local_78 != (ASN1_OCTET_STRING *)0x0) {
          if (local_78->length != 4) goto LAB_001443d2;
          local_78 = (ASN1_OCTET_STRING *)local_78->type;
        }
      }
    }
    iVar1 = OBJ_obj2nid(((p7->d).digest)->contents->type);
    if ((iVar1 == 0x15) && (p7->detached != 0)) {
      ASN1_OCTET_STRING_free(local_78);
      local_78 = (ASN1_STRING *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    iVar1 = OBJ_obj2nid(((p7->d).digest)->md->algorithm);
    pBVar4 = bio;
    while (pBVar4 = BIO_find_type(pBVar4,0x208), pBVar4 != (BIO *)0x0) {
      BIO_ctrl(pBVar4,0x78,0,&local_70);
      if (local_70 == (EVP_MD_CTX *)0x0) goto LAB_0014446c;
      pEVar2 = EVP_MD_CTX_md(local_70);
      iVar3 = EVP_MD_type(pEVar2);
      if (iVar1 == iVar3) {
        iVar1 = EVP_DigestFinal_ex(local_70,(uchar *)local_68,&local_6c);
        if ((iVar1 == 0) ||
           (iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)((p7->d).sign)->crl,local_68,local_6c),
           iVar1 == 0)) goto LAB_00144372;
        goto LAB_0014428a;
      }
      pBVar4 = BIO_next(pBVar4);
    }
LAB_00144366:
    ERR_put_error(0x21,0x7f,0x6c,"crypto/pkcs7/pk7_doit.c",600);
    goto LAB_00144372;
  default:
    iVar1 = 0;
    ERR_put_error(0x21,0x80,0x70,"crypto/pkcs7/pk7_doit.c",0x2d6);
    goto LAB_001442aa;
  }
LAB_0014428a:
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) || (lVar7 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar7 == 0)) {
    if (local_78 == (ASN1_STRING *)0x0) {
LAB_00144372:
      iVar1 = 0;
      goto LAB_001442aa;
    }
    if ((local_78->flags & 0x10U) == 0) {
      pBVar4 = BIO_find_type(bio,0x401);
      if (pBVar4 == (BIO *)0x0) {
        ERR_put_error(0x21,0x80,0x6b,"crypto/pkcs7/pk7_doit.c",800);
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
        lVar7 = BIO_ctrl(pBVar4,3,0,local_68);
        BIO_set_flags(pBVar4,0x200);
        BIO_ctrl(pBVar4,0x82,0,(void *)0x0);
        ASN1_STRING_set0(local_78,local_68[0],lVar7);
      }
      goto LAB_001442aa;
    }
  }
  iVar1 = 1;
LAB_001442aa:
  EVP_MD_CTX_free(out);
  return iVar1;
LAB_0014446c:
  ERR_put_error(0x21,0x7f,0x44,"crypto/pkcs7/pk7_doit.c",0x25d);
  goto LAB_00144372;
}



int PKCS7_dataFinal(PKCS7 *p7,BIO *bio)

{
  int iVar1;
  int iVar2;
  PKCS7_SIGNER_INFO *si;
  int iVar3;
  uchar *md;
  ASN1_OBJECT *b;
  undefined4 *puVar4;
  void *pvVar5;
  BIO *pBVar6;
  long lVar7;
  EVP_MD *pEVar8;
  _STACK *p_Var9;
  pkcs7_st *ppVar10;
  _STACK *p_Var11;
  ASN1_OCTET_STRING *local_94;
  EVP_MD_CTX *local_8c;
  void *local_88;
  uint local_84;
  EVP_MD_CTX EStack_80;
  uchar auStack_68 [68];
  
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x80,0x8f,"pk7_doit.c",0x2f2);
    return 0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x80,0x7a,"pk7_doit.c",0x2f7);
    return 0;
  }
  EVP_MD_CTX_init(&EStack_80);
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  switch(iVar1) {
  case 0x15:
    local_94 = (p7->d).data;
    break;
  case 0x16:
    ppVar10 = ((p7->d).sign)->contents;
    p_Var11 = &((p7->d).sign)->signer_info->stack;
    iVar2 = OBJ_obj2nid(ppVar10->type);
    if (iVar2 == 0x15) {
      local_94 = (ppVar10->d).data;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar10->type);
      if (iVar2 - 0x15U < 6) {
        local_94 = (ASN1_STRING *)0x0;
      }
      else {
        local_94 = (ppVar10->d).data;
        if (local_94 != (ASN1_OCTET_STRING *)0x0) {
          if (local_94->length == 4) {
            local_94 = (ASN1_OCTET_STRING *)local_94->type;
          }
          else {
            local_94 = (ASN1_STRING *)0x0;
          }
        }
      }
    }
    iVar2 = OBJ_obj2nid(((p7->d).sign)->contents->type);
    if ((iVar2 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free(local_94);
      local_94 = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).sign)->contents->d).ptr = (char *)0x0;
    }
    goto LAB_001710ca;
  case 0x17:
    local_94 = (ASN1_OCTET_STRING *)(((p7->d).sign)->cert->stack).sorted;
    if (local_94 == (ASN1_OCTET_STRING *)0x0) {
      local_94 = ASN1_STRING_type_new(4);
      if (local_94 == (ASN1_STRING *)0x0) {
        iVar2 = 0x316;
        local_94 = (ASN1_STRING *)0x0;
LAB_0017145a:
        ERR_put_error(0x21,0x80,0x41,"pk7_doit.c",iVar2);
        goto LAB_00171064;
      }
      ((p7->d).enveloped)->enc_data->enc_data = local_94;
    }
    break;
  case 0x18:
    p_Var11 = &((p7->d).sign)->signer_info->stack;
    local_94 = (ASN1_OCTET_STRING *)((p7->d).sign)->contents->state;
    if (local_94 == (ASN1_OCTET_STRING *)0x0) {
      local_94 = ASN1_STRING_type_new(4);
      iVar2 = 0x30a;
      if (local_94 == (ASN1_STRING *)0x0) goto LAB_0017145a;
      ((p7->d).signed_and_enveloped)->enc_data->enc_data = local_94;
    }
LAB_001710ca:
    if (p_Var11 == (_STACK *)0x0) break;
    iVar1 = 0;
    while (iVar2 = sk_num(p_Var11), iVar1 < iVar2) {
      si = (PKCS7_SIGNER_INFO *)sk_value(p_Var11,iVar1);
      if (si->pkey == (EVP_PKEY *)0x0) {
LAB_001711ce:
        iVar1 = iVar1 + 1;
      }
      else {
        iVar2 = OBJ_obj2nid(si->digest_alg->algorithm);
        pBVar6 = bio;
        while( true ) {
          pBVar6 = BIO_find_type(pBVar6,0x208);
          if (pBVar6 == (BIO *)0x0) goto LAB_0017112c;
          BIO_ctrl(pBVar6,0x78,0,&local_8c);
          if (local_8c == (EVP_MD_CTX *)0x0) goto LAB_001711d2;
          pEVar8 = EVP_MD_CTX_md(local_8c);
          iVar3 = EVP_MD_type(pEVar8);
          if (iVar2 == iVar3) break;
          pBVar6 = BIO_next(pBVar6);
        }
        iVar2 = EVP_MD_CTX_copy_ex(&EStack_80,local_8c);
        if (iVar2 == 0) goto LAB_0017113e;
        iVar2 = sk_num(&si->auth_attr->stack);
        if (iVar2 < 1) {
          local_84 = EVP_PKEY_size(si->pkey);
          md = (uchar *)CRYPTO_malloc(local_84,"pk7_doit.c",0x358);
          if (md != (uchar *)0x0) {
            iVar2 = EVP_SignFinal(&EStack_80,md,&local_84,si->pkey);
            if (iVar2 != 0) {
              ASN1_STRING_set0(si->enc_digest,md,local_84);
              goto LAB_001711ce;
            }
            ERR_put_error(0x21,0x80,6,"pk7_doit.c",0x35d);
          }
          goto LAB_0017113e;
        }
        p_Var9 = &si->auth_attr->stack;
        b = OBJ_nid2obj(0x34);
        if (p_Var9 == (_STACK *)0x0 || b == (ASN1_OBJECT *)0x0) {
LAB_0017123a:
          iVar2 = PKCS7_add0_attrib_signing_time(si,(ASN1_TIME *)0x0);
          if (iVar2 != 0) goto LAB_00171246;
          iVar1 = 0x2d0;
LAB_001712aa:
          ERR_put_error(0x21,0x88,0x41,"pk7_doit.c",iVar1);
          goto LAB_0017113e;
        }
        iVar2 = 0;
        do {
          iVar3 = sk_num(p_Var9);
          if (iVar3 <= iVar2) goto LAB_0017123a;
          puVar4 = (undefined4 *)sk_value(p_Var9,iVar2);
          iVar3 = OBJ_cmp((ASN1_OBJECT *)*puVar4,b);
          iVar2 = iVar2 + 1;
        } while (iVar3 != 0);
        if (((puVar4[1] != 0) || (iVar2 = sk_num((_STACK *)puVar4[2]), iVar2 == 0)) ||
           (pvVar5 = sk_value((_STACK *)puVar4[2],0), pvVar5 == (void *)0x0)) goto LAB_0017123a;
LAB_00171246:
        iVar2 = EVP_DigestFinal_ex(&EStack_80,auStack_68,&local_84);
        if (iVar2 == 0) {
          ERR_put_error(0x21,0x88,6,"pk7_doit.c",0x2d7);
          goto LAB_0017113e;
        }
        iVar2 = PKCS7_add1_attrib_digest(si,auStack_68,local_84);
        if (iVar2 == 0) {
          iVar1 = 0x2db;
          goto LAB_001712aa;
        }
        iVar2 = PKCS7_SIGNER_INFO_sign(si);
        if (iVar2 == 0) goto LAB_0017113e;
        iVar1 = iVar1 + 1;
      }
    }
    goto LAB_00171042;
  case 0x19:
    ppVar10 = ((p7->d).digest)->contents;
    iVar2 = OBJ_obj2nid(ppVar10->type);
    if (iVar2 == 0x15) {
      local_94 = (ppVar10->d).data;
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar10->type);
      if (iVar2 - 0x15U < 6) {
        local_94 = (ASN1_STRING *)0x0;
      }
      else {
        local_94 = (ppVar10->d).data;
        if (local_94 != (ASN1_OCTET_STRING *)0x0) {
          if (local_94->length == 4) {
            local_94 = (ASN1_OCTET_STRING *)local_94->type;
          }
          else {
            local_94 = (ASN1_STRING *)0x0;
          }
        }
      }
    }
    iVar2 = OBJ_obj2nid(((p7->d).digest)->contents->type);
    if ((iVar2 == 0x15) && (p7->detached != 0)) {
      ASN1_STRING_free(local_94);
      local_94 = (ASN1_OCTET_STRING *)0x0;
      (((p7->d).digest)->contents->d).ptr = (char *)0x0;
    }
    break;
  default:
    ERR_put_error(0x21,0x80,0x70,"pk7_doit.c",0x332);
    local_94 = (ASN1_STRING *)0x0;
    goto LAB_00171064;
  }
  if (iVar1 == 0x19) {
    iVar1 = OBJ_obj2nid(((p7->d).digest)->md->algorithm);
    pBVar6 = bio;
    while (pBVar6 = BIO_find_type(pBVar6,0x208), pBVar6 != (BIO *)0x0) {
      BIO_ctrl(pBVar6,0x78,0,&local_8c);
      if (local_8c == (EVP_MD_CTX *)0x0) goto LAB_001711d2;
      pEVar8 = EVP_MD_CTX_md(local_8c);
      iVar2 = EVP_MD_type(pEVar8);
      if (iVar1 == iVar2) {
        iVar1 = EVP_DigestFinal_ex(local_8c,auStack_68,&local_84);
        if (iVar1 == 0) goto LAB_0017113e;
        ASN1_STRING_set((ASN1_STRING *)((p7->d).sign)->crl,auStack_68,local_84);
        goto LAB_00171042;
      }
      pBVar6 = BIO_next(pBVar6);
    }
LAB_0017112c:
    ERR_put_error(0x21,0x7f,0x6c,"pk7_doit.c",0x2b9);
LAB_0017113e:
    local_94 = (ASN1_STRING *)0x0;
  }
  else {
LAB_00171042:
    iVar1 = OBJ_obj2nid(p7->type);
    if ((iVar1 != 0x16) || (lVar7 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar7 == 0)) {
      if (local_94 == (ASN1_STRING *)0x0) goto LAB_0017113e;
      if ((local_94->flags & 0x10U) == 0) {
        pBVar6 = BIO_find_type(bio,0x401);
        if (pBVar6 == (BIO *)0x0) {
          ERR_put_error(0x21,0x80,0x6b,"pk7_doit.c",0x37a);
          local_94 = (ASN1_STRING *)0x0;
        }
        else {
          lVar7 = BIO_ctrl(pBVar6,3,0,&local_88);
          BIO_set_flags(pBVar6,0x200);
          BIO_ctrl(pBVar6,0x82,0,(void *)0x0);
          ASN1_STRING_set0(local_94,local_88,lVar7);
          local_94 = (ASN1_STRING *)0x1;
        }
        goto LAB_00171064;
      }
    }
    local_94 = (ASN1_STRING *)0x1;
  }
LAB_00171064:
  EVP_MD_CTX_cleanup(&EStack_80);
  return (int)local_94;
LAB_001711d2:
  ERR_put_error(0x21,0x7f,0x44,"pk7_doit.c",0x2be);
  goto LAB_0017113e;
}


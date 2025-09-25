
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  char *pcVar6;
  EVP_MD *parg;
  X509_NAME *b;
  int iVar7;
  ASN1_INTEGER *x;
  BIO *key;
  BIO *pBVar8;
  long lVar9;
  undefined4 uVar10;
  int iVar11;
  PKCS7_SIGN_ENVELOPE *pPVar12;
  PKCS7_ENC_CONTENT *pPVar13;
  ASN1_OCTET_STRING *pAVar14;
  X509_NAME *a;
  BIO *b_00;
  BIO *pBVar15;
  pkcs7_st *ppVar16;
  int iVar17;
  stack_st_X509_ALGOR *psVar18;
  stack_st_PKCS7_RECIP_INFO *psVar19;
  BIO *cipher;
  BIO *bp;
  BIO *local_4c;
  ASN1_OCTET_STRING *local_48;
  X509_ALGOR *local_40;
  EVP_CIPHER_CTX *local_34;
  BIO *local_30;
  BIO *local_2c [2];
  
  local_34 = (EVP_CIPHER_CTX *)0x0;
  local_30 = (BIO *)0x0;
  local_2c[0] = (BIO *)0x0;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x70,0x8f,"crypto/pkcs7/pk7_doit.c",0x178);
    return (BIO *)0x0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x70,0x7a,"crypto/pkcs7/pk7_doit.c",0x17d);
    return (BIO *)0x0;
  }
  iVar2 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  if (iVar2 == 0x17) {
    pPVar13 = ((p7->d).enveloped)->enc_data;
    psVar19 = ((p7->d).enveloped)->recipientinfo;
    local_40 = pPVar13->algorithm;
    local_48 = pPVar13->enc_data;
    iVar2 = OBJ_obj2nid(local_40->algorithm);
    pcVar6 = OBJ_nid2sn(iVar2);
    cipher = (BIO *)EVP_get_cipherbyname(pcVar6);
    if (cipher == (BIO *)0x0) {
      iVar2 = 0x1a9;
      bp = (BIO *)0x0;
LAB_00143f6a:
      iVar11 = 0x6f;
LAB_00143ad2:
      ERR_put_error(0x21,0x70,iVar11,"crypto/pkcs7/pk7_doit.c",iVar2);
      pBVar5 = bp;
      pBVar15 = bp;
      key = bp;
      cipher = bp;
      goto LAB_00143ae0;
    }
    if (in_bio == (BIO *)0x0 && local_48 == (ASN1_OCTET_STRING *)0x0) goto LAB_00143bfa;
    b_00 = (BIO *)0x0;
LAB_00143c26:
    pBVar4 = BIO_f_cipher();
    bp = BIO_new(pBVar4);
    pBVar15 = b_00;
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x21,0x70,0x20,"crypto/pkcs7/pk7_doit.c",0x1d4);
      cipher = (BIO *)0x0;
      pBVar5 = (BIO *)0x0;
      key = (BIO *)0x0;
      goto LAB_00143ae0;
    }
    iVar2 = 0;
    if (pcert == (X509 *)0x0) {
      iVar2 = 0;
      while( true ) {
        iVar11 = OPENSSL_sk_num(psVar19);
        if (iVar11 <= iVar2) break;
        uVar10 = OPENSSL_sk_value(psVar19,iVar2);
        iVar11 = EVP_CIPHER_key_length((EVP_CIPHER *)cipher);
        iVar11 = pkcs7_decrypt_rinfo(&local_30,local_2c,uVar10,pkey,iVar11);
        if (iVar11 < 0) {
          cipher = (BIO *)0x0;
          pBVar5 = (BIO *)0x0;
          key = (BIO *)0x0;
          goto LAB_00143ae0;
        }
        ERR_clear_error();
        iVar2 = iVar2 + 1;
      }
LAB_00143ca0:
      local_34 = (EVP_CIPHER_CTX *)0x0;
      BIO_ctrl(bp,0x81,0,&local_34);
      iVar2 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)cipher,(ENGINE *)0x0,(uchar *)0x0,
                                (uchar *)0x0,0);
      if ((0 < iVar2) &&
         (iVar2 = EVP_CIPHER_asn1_to_param(local_34,local_40->parameter), -1 < iVar2)) {
        cipher = (BIO *)EVP_CIPHER_CTX_key_length(local_34);
        key = (BIO *)CRYPTO_malloc((int)cipher,"crypto/pkcs7/pk7_doit.c",0x20d);
        pBVar5 = key;
        if ((key == (BIO *)0x0) ||
           (iVar2 = EVP_CIPHER_CTX_rand_key(local_34,(uchar *)key), pBVar5 = (BIO *)0x0, iVar2 < 1))
        goto LAB_00143ae0;
        pBVar5 = key;
        if (local_30 == (BIO *)0x0) {
          pBVar5 = local_30;
          local_30 = key;
          local_2c[0] = cipher;
        }
        pBVar8 = (BIO *)EVP_CIPHER_CTX_key_length(local_34);
        key = pBVar5;
        if ((pBVar8 != local_2c[0]) &&
           (iVar2 = EVP_CIPHER_CTX_set_key_length(local_34,(int)local_2c[0]), iVar2 == 0)) {
          CRYPTO_clear_free(local_30,local_2c[0],"crypto/pkcs7/pk7_doit.c",0x220);
          key = (BIO *)0x0;
          local_30 = pBVar5;
          local_2c[0] = cipher;
        }
        ERR_clear_error();
        iVar2 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)local_30,
                                  (uchar *)0x0,0);
        pBVar5 = (BIO *)0x0;
        if (iVar2 < 1) goto LAB_00143ae0;
        CRYPTO_clear_free(local_30,local_2c[0],"crypto/pkcs7/pk7_doit.c",0x22b);
        local_30 = (BIO *)0x0;
        CRYPTO_clear_free(key,cipher,"crypto/pkcs7/pk7_doit.c",0x22d);
        pBVar15 = bp;
        if (b_00 != (BIO *)0x0) {
          BIO_push(b_00,bp);
          pBVar15 = b_00;
        }
        goto LAB_00143d72;
      }
    }
    else {
      do {
        do {
          iVar11 = OPENSSL_sk_num(psVar19);
          iVar17 = iVar2 + 1;
          if (iVar11 <= iVar2) {
            cipher = (BIO *)0x0;
            ERR_put_error(0x21,0x70,0x73,"crypto/pkcs7/pk7_doit.c",0x1eb);
            pBVar5 = (BIO *)0x0;
            key = (BIO *)0x0;
            goto LAB_00143ae0;
          }
          iVar11 = OPENSSL_sk_value(psVar19,iVar2);
          a = (X509_NAME *)**(undefined4 **)(iVar11 + 4);
          b = X509_get_issuer_name(pcert);
          iVar7 = X509_NAME_cmp(a,b);
          iVar2 = iVar17;
        } while (iVar7 != 0);
        x = X509_get_serialNumber(pcert);
        iVar17 = ASN1_INTEGER_cmp(x,*(ASN1_INTEGER **)(*(int *)(iVar11 + 4) + 4));
      } while (iVar17 != 0);
      iVar2 = pkcs7_decrypt_rinfo(&local_30,local_2c,iVar11,pkey,0);
      if (-1 < iVar2) {
        ERR_clear_error();
        goto LAB_00143ca0;
      }
    }
    cipher = (BIO *)0x0;
    pBVar5 = cipher;
    key = cipher;
    goto LAB_00143ae0;
  }
  if (iVar2 == 0x18) {
    pPVar12 = (p7->d).signed_and_enveloped;
    psVar19 = pPVar12->recipientinfo;
    psVar18 = pPVar12->md_algs;
    local_40 = pPVar12->enc_data->algorithm;
    local_48 = pPVar12->enc_data->enc_data;
    iVar2 = OBJ_obj2nid(local_40->algorithm);
    pcVar6 = OBJ_nid2sn(iVar2);
    cipher = (BIO *)EVP_get_cipherbyname(pcVar6);
    if (cipher == (BIO *)0x0) {
      iVar2 = 0x19d;
      bp = cipher;
      goto LAB_00143f6a;
    }
    bVar1 = local_48 == (ASN1_OCTET_STRING *)0x0;
LAB_00143b52:
    if (in_bio != (BIO *)0x0) {
      bVar1 = false;
    }
    if (!bVar1) {
      if (psVar18 == (stack_st_X509_ALGOR *)0x0) {
        b_00 = (BIO *)0x0;
      }
      else {
        b_00 = (BIO *)0x0;
        for (iVar2 = 0; iVar11 = OPENSSL_sk_num(psVar18), iVar2 < iVar11; iVar2 = iVar2 + 1) {
          puVar3 = (undefined4 *)OPENSSL_sk_value(psVar18,iVar2);
          pBVar4 = BIO_f_md();
          pBVar5 = BIO_new(pBVar4);
          pBVar15 = b_00;
          if (pBVar5 == (BIO *)0x0) {
            ERR_put_error(0x21,0x70,0x20,"crypto/pkcs7/pk7_doit.c",0x1bd);
            bp = (BIO *)0x0;
            cipher = (BIO *)0x0;
            key = (BIO *)0x0;
            goto LAB_00143ae0;
          }
          iVar11 = OBJ_obj2nid((ASN1_OBJECT *)*puVar3);
          pcVar6 = OBJ_nid2sn(iVar11);
          parg = EVP_get_digestbyname(pcVar6);
          if (parg == (EVP_MD *)0x0) {
            ERR_put_error(0x21,0x70,0x6d,"crypto/pkcs7/pk7_doit.c",0x1c5);
            bp = (BIO *)0x0;
            cipher = (BIO *)0x0;
            key = (BIO *)0x0;
            goto LAB_00143ae0;
          }
          BIO_ctrl(pBVar5,0x6f,0,parg);
          if (b_00 != (BIO *)0x0) {
            BIO_push(b_00,pBVar5);
            pBVar5 = b_00;
          }
          b_00 = pBVar5;
        }
      }
      pBVar15 = b_00;
      if (cipher != (BIO *)0x0) goto LAB_00143c26;
LAB_00143d72:
      local_4c = in_bio;
      if (in_bio != (BIO *)0x0) {
LAB_00143d78:
        BIO_push(pBVar15,local_4c);
        return pBVar15;
      }
      if (local_48->length < 1) {
        pBVar4 = BIO_s_mem();
        local_4c = BIO_new(pBVar4);
        if (local_4c != (BIO *)0x0) {
          BIO_ctrl(local_4c,0x82,0,(void *)0x0);
          goto LAB_00143d78;
        }
        bp = (BIO *)0x0;
        pBVar5 = (BIO *)0x0;
        key = (BIO *)0x0;
      }
      else {
        local_4c = BIO_new_mem_buf(local_48->data,local_48->length);
        if (local_4c != (BIO *)0x0) goto LAB_00143d78;
        bp = (BIO *)0x0;
        pBVar5 = (BIO *)0x0;
        key = pBVar5;
      }
      goto LAB_00143ae0;
    }
LAB_00143bfa:
    iVar11 = 0x1b4;
    iVar2 = 0x7a;
  }
  else {
    if (iVar2 != 0x16) {
      iVar11 = 0x70;
      iVar2 = 0x1ae;
      bp = (BIO *)0x0;
      goto LAB_00143ad2;
    }
    ppVar16 = ((p7->d).sign)->contents;
    iVar2 = OBJ_obj2nid(ppVar16->type);
    if (iVar2 == 0x15) {
      local_48 = (ASN1_OCTET_STRING *)(ppVar16->d).ptr;
LAB_00143dca:
      iVar2 = OBJ_obj2nid(p7->type);
      if (iVar2 == 0x16) {
LAB_00143db0:
        lVar9 = PKCS7_ctrl(p7,2,0,(char *)0x0);
        if (lVar9 != 0) {
          bVar1 = local_48 == (ASN1_OCTET_STRING *)0x0;
          goto LAB_00143de0;
        }
      }
      if (local_48 != (ASN1_OCTET_STRING *)0x0) {
        bVar1 = false;
LAB_00143de0:
        psVar19 = (stack_st_PKCS7_RECIP_INFO *)0x0;
        cipher = (BIO *)0x0;
        local_40 = (X509_ALGOR *)0x0;
        psVar18 = (stack_st_X509_ALGOR *)((p7->d).data)->type;
        goto LAB_00143b52;
      }
    }
    else {
      iVar2 = OBJ_obj2nid(ppVar16->type);
      if (5 < iVar2 - 0x15U) {
        pAVar14 = (ppVar16->d).data;
        if ((pAVar14 != (ASN1_OCTET_STRING *)0x0) && (pAVar14->length == 4)) {
          local_48 = (ASN1_OCTET_STRING *)pAVar14->type;
          goto LAB_00143dca;
        }
        iVar2 = OBJ_obj2nid(p7->type);
        if ((iVar2 != 0x16) || (lVar9 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar9 == 0))
        goto LAB_00143f6e;
        bVar1 = true;
        local_48 = (ASN1_OCTET_STRING *)0x0;
        goto LAB_00143de0;
      }
      iVar2 = OBJ_obj2nid(p7->type);
      if (iVar2 == 0x16) {
        local_48 = (ASN1_OCTET_STRING *)0x0;
        goto LAB_00143db0;
      }
    }
LAB_00143f6e:
    iVar11 = 399;
    iVar2 = 0x9b;
  }
  cipher = (BIO *)0x0;
  ERR_put_error(0x21,0x70,iVar2,"crypto/pkcs7/pk7_doit.c",iVar11);
  bp = (BIO *)0x0;
  pBVar5 = (BIO *)0x0;
  pBVar15 = (BIO *)0x0;
  key = (BIO *)0x0;
LAB_00143ae0:
  CRYPTO_clear_free(local_30,local_2c[0],"crypto/pkcs7/pk7_doit.c",0x249);
  CRYPTO_clear_free(key,cipher,"crypto/pkcs7/pk7_doit.c",0x24a);
  BIO_free_all(pBVar15);
  BIO_free_all(pBVar5);
  BIO_free_all(bp);
  BIO_free_all((BIO *)0x0);
  return (BIO *)0x0;
}


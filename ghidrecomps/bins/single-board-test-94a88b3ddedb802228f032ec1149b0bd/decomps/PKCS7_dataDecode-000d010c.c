
BIO * PKCS7_dataDecode(PKCS7 *p7,EVP_PKEY *pkey,BIO *in_bio,X509 *pcert)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  BIO_METHOD *pBVar3;
  BIO *pBVar4;
  char *pcVar5;
  EVP_MD *parg;
  void *pvVar6;
  BIO *len;
  BIO *key;
  BIO *pBVar7;
  long lVar8;
  int iVar9;
  PKCS7_SIGN_ENVELOPE *pPVar10;
  PKCS7_ENC_CONTENT *pPVar11;
  ASN1_OCTET_STRING *pAVar12;
  int iVar13;
  pkcs7_st *ppVar14;
  BIO *b;
  BIO *pBVar15;
  _STACK *p_Var16;
  _STACK *p_Var17;
  ASN1_OCTET_STRING *local_48;
  BIO *local_44;
  X509_ALGOR *local_40;
  EVP_CIPHER_CTX *local_34;
  BIO *local_30;
  BIO *local_2c [2];
  
  local_34 = (EVP_CIPHER_CTX *)0x0;
  local_30 = (BIO *)0x0;
  local_2c[0] = (BIO *)0x0;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x70,0x8f,DAT_000d05d0,0x1b2);
    return (BIO *)0x0;
  }
  if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x70,0x7a,DAT_000d05d0,0x1b7);
    return (BIO *)0x0;
  }
  iVar1 = OBJ_obj2nid(p7->type);
  p7->state = 0;
  if (iVar1 == 0x17) {
    pPVar11 = ((p7->d).enveloped)->enc_data;
    p_Var17 = &((p7->d).enveloped)->recipientinfo->stack;
    local_40 = pPVar11->algorithm;
    local_48 = pPVar11->enc_data;
    iVar1 = OBJ_obj2nid(local_40->algorithm);
    pcVar5 = OBJ_nid2sn(iVar1);
    pBVar15 = (BIO *)EVP_get_cipherbyname(pcVar5);
    iVar1 = 0x1e3;
    if (pBVar15 == (BIO *)0x0) {
LAB_000d050c:
      iVar9 = 0x6f;
LAB_000d0156:
      ERR_put_error(0x21,0x70,iVar9,DAT_000d0294,iVar1);
      pBVar4 = pBVar15;
      b = pBVar15;
      len = pBVar15;
      key = pBVar15;
      goto LAB_000d0164;
    }
    if ((in_bio != (BIO *)0x0) || (local_48 != (ASN1_OCTET_STRING *)0x0)) {
      b = (BIO *)0x0;
      local_44 = pBVar15;
      goto LAB_000d02d2;
    }
  }
  else {
    if (iVar1 == 0x18) {
      pPVar10 = (p7->d).signed_and_enveloped;
      p_Var17 = &pPVar10->recipientinfo->stack;
      p_Var16 = &pPVar10->md_algs->stack;
      local_40 = pPVar10->enc_data->algorithm;
      local_48 = pPVar10->enc_data->enc_data;
      iVar1 = OBJ_obj2nid(local_40->algorithm);
      pcVar5 = OBJ_nid2sn(iVar1);
      local_44 = (BIO *)EVP_get_cipherbyname(pcVar5);
      if (local_44 == (BIO *)0x0) {
        iVar1 = 0x1d7;
        pBVar15 = (BIO *)0x0;
        goto LAB_000d050c;
      }
    }
    else {
      if (iVar1 != 0x16) {
        pBVar15 = (BIO *)0x0;
        iVar9 = 0x70;
        iVar1 = 0x1e8;
        goto LAB_000d0156;
      }
      ppVar14 = ((p7->d).sign)->contents;
      iVar1 = OBJ_obj2nid(ppVar14->type);
      if (iVar1 == 0x15) {
        local_48 = (ppVar14->d).data;
      }
      else {
        iVar1 = OBJ_obj2nid(ppVar14->type);
        if (iVar1 - 0x15U < 6) {
LAB_000d026a:
          local_48 = (ASN1_OCTET_STRING *)0x0;
        }
        else {
          pAVar12 = (ppVar14->d).data;
          if (pAVar12 == (ASN1_OCTET_STRING *)0x0) {
            local_48 = (ASN1_OCTET_STRING *)0x0;
          }
          else {
            if (pAVar12->length != 4) goto LAB_000d026a;
            local_48 = (ASN1_OCTET_STRING *)pAVar12->type;
          }
        }
      }
      iVar1 = OBJ_obj2nid(p7->type);
      if (((iVar1 != 0x16) || (lVar8 = PKCS7_ctrl(p7,2,0,(char *)0x0), lVar8 == 0)) &&
         (local_48 == (ASN1_OCTET_STRING *)0x0)) {
        iVar1 = 0x1c9;
        iVar9 = 0x9b;
        pBVar15 = (BIO *)0x0;
        goto LAB_000d0156;
      }
      p_Var17 = (_STACK *)0x0;
      local_40 = (X509_ALGOR *)0x0;
      local_44 = (BIO *)0x0;
      p_Var16 = &((p7->d).sign)->md_algs->stack;
    }
    if (local_48 != (ASN1_OCTET_STRING *)0x0 || in_bio != (BIO *)0x0) {
      pBVar15 = (BIO *)0x0;
      b = pBVar15;
      if (p_Var16 == (_STACK *)0x0) {
        b = (BIO *)0x0;
      }
      else {
        for (; iVar1 = sk_num(p_Var16), (int)pBVar15 < iVar1;
            pBVar15 = (BIO *)((int)&pBVar15->method + 1)) {
          ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var16,(int)pBVar15);
          pBVar3 = BIO_f_md();
          pBVar4 = BIO_new(pBVar3);
          if (pBVar4 == (BIO *)0x0) {
            ERR_put_error(0x21,0x70,0x20,DAT_000d05d0,0x1f7);
            pBVar15 = (BIO *)0x0;
            len = (BIO *)0x0;
            key = (BIO *)0x0;
            goto LAB_000d0164;
          }
          iVar1 = OBJ_obj2nid(*ppAVar2);
          pcVar5 = OBJ_nid2sn(iVar1);
          parg = EVP_get_digestbyname(pcVar5);
          if (parg == (EVP_MD *)0x0) {
            ERR_put_error(0x21,0x70,0x6d,DAT_000d05d0,0x1ff);
            pBVar15 = (BIO *)0x0;
            len = (BIO *)0x0;
            key = (BIO *)0x0;
            goto LAB_000d0164;
          }
          BIO_ctrl(pBVar4,0x6f,0,parg);
          if (b != (BIO *)0x0) {
            BIO_push(b,pBVar4);
            pBVar4 = b;
          }
          b = pBVar4;
        }
      }
      if (local_44 == (BIO *)0x0) {
        len = (BIO *)0x0;
        pBVar7 = b;
      }
      else {
LAB_000d02d2:
        pBVar3 = BIO_f_cipher();
        pBVar15 = BIO_new(pBVar3);
        if (pBVar15 == (BIO *)0x0) {
          ERR_put_error(0x21,0x70,0x20,DAT_000d05d0,0x217);
          len = (BIO *)0x0;
          key = (BIO *)0x0;
          pBVar4 = (BIO *)0x0;
          goto LAB_000d0164;
        }
        if (pcert == (X509 *)0x0) {
          while( true ) {
            iVar1 = sk_num(p_Var17);
            if (iVar1 <= (int)pcert) break;
            pvVar6 = sk_value(p_Var17,(int)pcert);
            iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar6,pkey);
            if (iVar1 < 0) {
              len = (BIO *)0x0;
              key = (BIO *)0x0;
              pBVar4 = (BIO *)0x0;
              goto LAB_000d0164;
            }
            ERR_clear_error();
            pcert = (X509 *)((int)&pcert->cert_info + 1);
          }
        }
        else {
          iVar1 = 0;
          do {
            iVar9 = sk_num(p_Var17);
            iVar13 = iVar1 + 1;
            if (iVar9 <= iVar1) {
              len = (BIO *)0x0;
              key = (BIO *)0x0;
              ERR_put_error(0x21,0x70,0x73,DAT_000d05d0,0x22e);
              pBVar4 = (BIO *)0x0;
              goto LAB_000d0164;
            }
            pvVar6 = sk_value(p_Var17,iVar1);
            iVar9 = X509_NAME_cmp(**(X509_NAME ***)((int)pvVar6 + 4),pcert->cert_info->issuer);
            iVar1 = iVar13;
          } while ((iVar9 != 0) ||
                  (iVar9 = ASN1_STRING_cmp(pcert->cert_info->serialNumber,
                                           *(ASN1_STRING **)(*(int *)((int)pvVar6 + 4) + 4)),
                  iVar9 != 0));
          iVar1 = pkcs7_decrypt_rinfo(&local_30,local_2c,pvVar6,pkey);
          if (iVar1 < 0) {
            len = (BIO *)0x0;
            key = (BIO *)0x0;
            pBVar4 = (BIO *)0x0;
            goto LAB_000d0164;
          }
          ERR_clear_error();
        }
        local_34 = (EVP_CIPHER_CTX *)0x0;
        BIO_ctrl(pBVar15,0x81,0,&local_34);
        iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)local_44,(ENGINE *)0x0,(uchar *)0x0,
                                  (uchar *)0x0,0);
        if ((iVar1 < 1) ||
           (iVar1 = EVP_CIPHER_asn1_to_param(local_34,local_40->parameter), iVar1 < 0)) {
          len = (BIO *)0x0;
          key = (BIO *)0x0;
          pBVar4 = (BIO *)0x0;
          goto LAB_000d0164;
        }
        len = (BIO *)EVP_CIPHER_CTX_key_length(local_34);
        key = (BIO *)CRYPTO_malloc((int)len,DAT_000d05d0,0x24f);
        pBVar4 = key;
        if ((key == (BIO *)0x0) ||
           (iVar1 = EVP_CIPHER_CTX_rand_key(local_34,(uchar *)key), pBVar4 = (BIO *)0x0, iVar1 < 1))
        goto LAB_000d0164;
        pBVar4 = key;
        if (local_30 == (BIO *)0x0) {
          pBVar4 = local_30;
          local_30 = key;
          local_2c[0] = len;
        }
        pBVar7 = (BIO *)EVP_CIPHER_CTX_key_length(local_34);
        key = pBVar4;
        if ((pBVar7 != local_2c[0]) &&
           (iVar1 = EVP_CIPHER_CTX_set_key_length(local_34,(int)local_2c[0]), iVar1 == 0)) {
          OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
          CRYPTO_free(local_30);
          key = (BIO *)0x0;
          local_30 = pBVar4;
          local_2c[0] = len;
        }
        ERR_clear_error();
        iVar1 = EVP_CipherInit_ex(local_34,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)local_30,
                                  (uchar *)0x0,0);
        pBVar4 = (BIO *)0x0;
        if (iVar1 < 1) goto LAB_000d0164;
        if (local_30 != (BIO *)0x0) {
          OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
          CRYPTO_free(local_30);
          local_30 = (BIO *)0x0;
        }
        if (key != (BIO *)0x0) {
          OPENSSL_cleanse(key,(size_t)len);
          CRYPTO_free(key);
        }
        pBVar7 = pBVar15;
        if (b != (BIO *)0x0) {
          BIO_push(b,pBVar15);
          pBVar7 = b;
        }
      }
      if (in_bio != (BIO *)0x0) {
LAB_000d042e:
        BIO_push(pBVar7,in_bio);
        return pBVar7;
      }
      if (local_48->length < 1) {
        pBVar3 = BIO_s_mem();
        in_bio = BIO_new(pBVar3);
        BIO_ctrl(in_bio,0x82,0,(void *)0x0);
      }
      else {
        in_bio = BIO_new_mem_buf(local_48->data,local_48->length);
      }
      if (in_bio != (BIO *)0x0) goto LAB_000d042e;
      pBVar15 = (BIO *)0x0;
      key = (BIO *)0x0;
      pBVar4 = key;
      b = pBVar7;
      goto LAB_000d0164;
    }
  }
  len = (BIO *)0x0;
  key = (BIO *)0x0;
  ERR_put_error(0x21,0x70,0x7a,DAT_000d05d0,0x1ee);
  pBVar15 = (BIO *)0x0;
  pBVar4 = (BIO *)0x0;
  b = (BIO *)0x0;
LAB_000d0164:
  if (local_30 != (BIO *)0x0) {
    OPENSSL_cleanse(local_30,(size_t)local_2c[0]);
    CRYPTO_free(local_30);
  }
  if (key != (BIO *)0x0) {
    OPENSSL_cleanse(key,(size_t)len);
    CRYPTO_free(key);
  }
  if (b != (BIO *)0x0) {
    BIO_free_all(b);
  }
  if (pBVar4 != (BIO *)0x0) {
    BIO_free_all(pBVar4);
  }
  if (pBVar15 != (BIO *)0x0) {
    BIO_free_all(pBVar15);
  }
  return (BIO *)0x0;
}


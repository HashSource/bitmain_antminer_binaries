
BIO * cms_EncryptedContent_init_bio(int param_1)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *type_00;
  char *name;
  uchar *key;
  EVP_CIPHER *pEVar3;
  uchar *num;
  uchar *puVar4;
  undefined4 *puVar5;
  uchar *enc;
  uchar *buf;
  bool bVar6;
  EVP_CIPHER_CTX *local_3c;
  uchar auStack_38 [20];
  
  puVar4 = *(uchar **)(param_1 + 0xc);
  puVar5 = *(undefined4 **)(param_1 + 4);
  type = BIO_f_cipher();
  enc = puVar4;
  if (puVar4 != (uchar *)0x0) {
    enc = (uchar *)0x1;
  }
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"crypto/cms/cms_enc.c",0x29);
    return (BIO *)0x0;
  }
  BIO_ctrl(bp,0x81,0,&local_3c);
  if (puVar4 == (uchar *)0x0) {
    iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar5);
    name = OBJ_nid2sn(iVar1);
    pEVar3 = EVP_get_cipherbyname(name);
    if (pEVar3 == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x78,0x94,"crypto/cms/cms_enc.c",0x3a);
      num = (uchar *)0x0;
      key = (uchar *)0x0;
      goto LAB_001dac98;
    }
    iVar1 = EVP_CipherInit_ex(local_3c,pEVar3,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,(int)enc);
    if (0 < iVar1) {
      iVar1 = EVP_CIPHER_asn1_to_param(local_3c,(ASN1_TYPE *)puVar5[1]);
      if (iVar1 < 1) {
        ERR_put_error(0x2e,0x78,0x66,"crypto/cms/cms_enc.c",0x51);
        num = (uchar *)0x0;
        key = puVar4;
        goto LAB_001dac98;
      }
      num = (uchar *)EVP_CIPHER_CTX_key_length(local_3c);
      buf = (uchar *)0x0;
      goto LAB_001dad10;
    }
  }
  else {
    pEVar3 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    num = (uchar *)0x0;
    iVar1 = EVP_CipherInit_ex(local_3c,pEVar3,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,(int)enc);
    if (0 < iVar1) {
      pEVar3 = EVP_CIPHER_CTX_cipher(local_3c);
      iVar1 = EVP_CIPHER_type(pEVar3);
      pAVar2 = OBJ_nid2obj(iVar1);
      *puVar5 = pAVar2;
      iVar1 = EVP_CIPHER_CTX_iv_length(local_3c);
      buf = num;
      if (0 < iVar1) {
        buf = auStack_38;
        iVar1 = RAND_bytes(buf,iVar1);
        if (iVar1 < 1) {
          key = (uchar *)0x0;
          goto LAB_001dac98;
        }
      }
      num = (uchar *)EVP_CIPHER_CTX_key_length(local_3c);
      key = (uchar *)0x0;
      if (*(int *)(param_1 + 0x10) != 0) goto LAB_001dac06;
LAB_001dad10:
      key = (uchar *)CRYPTO_malloc((int)num,"crypto/cms/cms_enc.c",0x57);
      iVar1 = 0x59;
      if (key == (uchar *)0x0) {
LAB_001dada4:
        ERR_put_error(0x2e,0x78,0x41,"crypto/cms/cms_enc.c",iVar1);
      }
      else {
        iVar1 = EVP_CIPHER_CTX_rand_key(local_3c,key);
        if (iVar1 < 1) goto LAB_001dac98;
        if (*(int *)(param_1 + 0x10) == 0) {
          *(uchar **)(param_1 + 0x10) = key;
          *(uchar **)(param_1 + 0x14) = num;
          if (puVar4 == (uchar *)0x0) {
            ERR_clear_error();
            key = puVar4;
            goto LAB_001dac06;
          }
          iVar1 = EVP_CipherInit_ex(local_3c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,key,buf,(int)enc);
          if (0 < iVar1) {
            bVar6 = false;
            key = (uchar *)0x0;
LAB_001dac3a:
            type_00 = ASN1_TYPE_new();
            puVar5[1] = type_00;
            if (type_00 != (ASN1_TYPE *)0x0) {
              iVar1 = EVP_CIPHER_param_to_asn1(local_3c,type_00);
              if (0 < iVar1) {
                if (((ASN1_TYPE *)puVar5[1])->type == -1) {
                  ASN1_TYPE_free((ASN1_TYPE *)puVar5[1]);
                  puVar5[1] = 0;
                }
                puVar4 = key;
                if (!bVar6) {
                  CRYPTO_clear_free(key,num,"crypto/cms/cms_enc.c",0x9e);
                  return bp;
                }
LAB_001dadf6:
                CRYPTO_clear_free(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                                  "crypto/cms/cms_enc.c",0x9b);
                *(undefined4 *)(param_1 + 0x10) = 0;
                CRYPTO_clear_free(puVar4,num,"crypto/cms/cms_enc.c",0x9e);
                return bp;
              }
              ERR_put_error(0x2e,0x78,0x66,"crypto/cms/cms_enc.c",0x8e);
              goto LAB_001dac98;
            }
            iVar1 = 0x89;
            goto LAB_001dada4;
          }
          key = (uchar *)0x0;
        }
        else {
LAB_001dac06:
          if ((*(uchar **)(param_1 + 0x14) == num) ||
             (iVar1 = EVP_CIPHER_CTX_set_key_length(local_3c,(int)*(uchar **)(param_1 + 0x14)),
             0 < iVar1)) {
            iVar1 = EVP_CipherInit_ex(local_3c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                      *(uchar **)(param_1 + 0x10),buf,(int)enc);
            if (0 < iVar1) {
              bVar6 = puVar4 == (uchar *)0x0;
              puVar4 = key;
              if (bVar6) goto LAB_001dadf6;
              bVar6 = true;
              goto LAB_001dac3a;
            }
          }
          else {
            if ((puVar4 != (uchar *)0x0) || (*(int *)(param_1 + 0x18) != 0)) {
              ERR_put_error(0x2e,0x78,0x76,"crypto/cms/cms_enc.c",0x74);
              goto LAB_001dac98;
            }
            CRYPTO_clear_free(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                              "crypto/cms/cms_enc.c",0x78);
            *(uchar **)(param_1 + 0x10) = key;
            *(uchar **)(param_1 + 0x14) = num;
            ERR_clear_error();
            iVar1 = EVP_CipherInit_ex(local_3c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                      *(uchar **)(param_1 + 0x10),buf,(int)enc);
            key = puVar4;
            if (0 < iVar1) goto LAB_001dadf6;
          }
        }
        ERR_put_error(0x2e,0x78,0x65,"crypto/cms/cms_enc.c",0x83);
      }
      goto LAB_001dac98;
    }
  }
  num = (uchar *)0x0;
  ERR_put_error(0x2e,0x78,0x65,"crypto/cms/cms_enc.c",0x41);
  key = (uchar *)0x0;
LAB_001dac98:
  CRYPTO_clear_free(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                    "crypto/cms/cms_enc.c",0x9b);
  *(undefined4 *)(param_1 + 0x10) = 0;
  CRYPTO_clear_free(key,num,"crypto/cms/cms_enc.c",0x9e);
  BIO_free(bp);
  return (BIO *)0x0;
}


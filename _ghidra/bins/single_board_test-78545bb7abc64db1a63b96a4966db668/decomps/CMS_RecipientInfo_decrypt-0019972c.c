
int CMS_RecipientInfo_decrypt(CMS_ContentInfo *cms,CMS_RecipientInfo *ri)

{
  EVP_PKEY_CTX *pEVar1;
  int iVar2;
  char *name;
  EVP_CIPHER *cipher;
  uint uVar3;
  int iVar4;
  uchar *puVar5;
  EVP_PKEY *pkey;
  int iVar6;
  AES_KEY local_114;
  
  iVar4 = *(int *)ri;
  if (iVar4 == 2) {
    iVar4 = *(int *)(ri + 4);
    iVar6 = *(int *)(*(int *)(cms + 4) + 0xc);
    if (*(int *)(iVar4 + 0x10) == 0) {
      ERR_put_error(0x2e,0x87,0x82,"crypto/cms/cms_env.c",699);
      return 0;
    }
    iVar2 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(iVar4 + 8));
    if (iVar2 - 0x314U < 3) {
      iVar2 = *(int *)(&CSWTCH_7 + (iVar2 - 0x314U) * 4);
      if (*(int *)(iVar4 + 0x14) != iVar2) {
LAB_00199852:
        ERR_put_error(0x2e,0x87,0x76,"crypto/cms/cms_env.c",0x2c2);
        return 0;
      }
    }
    else {
      iVar2 = 0;
      if (*(int *)(iVar4 + 0x14) != 0) goto LAB_00199852;
    }
    if (**(int **)(iVar4 + 0xc) < 0x10) {
      puVar5 = (uchar *)0x0;
      ERR_put_error(0x2e,0x87,0x75,"crypto/cms/cms_env.c",0x2ca);
    }
    else {
      iVar2 = AES_set_decrypt_key(*(uchar **)(iVar4 + 0x10),iVar2 << 3,&local_114);
      if (iVar2 == 0) {
        puVar5 = (uchar *)CRYPTO_malloc(**(int **)(iVar4 + 0xc) + -8,"crypto/cms/cms_env.c",0x2d4);
        if (puVar5 == (uchar *)0x0) {
          ERR_put_error(0x2e,0x87,0x41,"crypto/cms/cms_env.c",0x2d7);
        }
        else {
          iVar4 = AES_unwrap_key(&local_114,(uchar *)0x0,puVar5,
                                 (uchar *)(*(uint **)(iVar4 + 0xc))[2],**(uint **)(iVar4 + 0xc));
          if (0 < iVar4) {
            iVar2 = 1;
            CRYPTO_clear_free(*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x14),
                              "crypto/cms/cms_env.c",0x2e4);
            *(uchar **)(iVar6 + 0x10) = puVar5;
            *(int *)(iVar6 + 0x14) = iVar4;
            goto LAB_00199834;
          }
          ERR_put_error(0x2e,0x87,0x9d,"crypto/cms/cms_env.c",0x2e0);
        }
      }
      else {
        puVar5 = (uchar *)0x0;
        ERR_put_error(0x2e,0x87,0x73,"crypto/cms/cms_env.c",0x2d0);
      }
    }
    iVar2 = 0;
    CRYPTO_free(puVar5);
LAB_00199834:
    OPENSSL_cleanse(&local_114,0xf4);
    return iVar2;
  }
  if (iVar4 == 3) {
    iVar4 = cms_RecipientInfo_pwri_crypt(cms,ri,0);
    return iVar4;
  }
  if (iVar4 != 0) {
    ERR_put_error(0x2e,0x86,0x9b,"crypto/cms/cms_env.c",0x302);
    return 0;
  }
  iVar6 = *(int *)(ri + 4);
  pkey = *(EVP_PKEY **)(iVar6 + 0x14);
  iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x2e,0x8c,0x85,"crypto/cms/cms_env.c",0x173);
    return 0;
  }
  if ((*(int *)(iVar4 + 0x1c) == 0) || (*(int *)(iVar4 + 0x18) != 0)) {
    uVar3 = 0;
  }
  else {
    iVar2 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(iVar4 + 4));
    name = OBJ_nid2sn(iVar2);
    cipher = EVP_get_cipherbyname(name);
    if (cipher == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x8c,0x94,"crypto/cms/cms_env.c",0x17d);
      return 0;
    }
    uVar3 = EVP_CIPHER_key_length(cipher);
  }
  pEVar1 = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
  *(EVP_PKEY_CTX **)(iVar6 + 0x18) = pEVar1;
  if (pEVar1 == (EVP_PKEY_CTX *)0x0) {
    return 0;
  }
  iVar2 = EVP_PKEY_decrypt_init(pEVar1);
  if ((0 < iVar2) && (iVar2 = cms_env_asn1_ctrl(ri,1), iVar2 != 0)) {
    iVar2 = EVP_PKEY_CTX_ctrl(*(EVP_PKEY_CTX **)(iVar6 + 0x18),-1,0x200,10,0,ri);
    if (iVar2 < 1) {
      puVar5 = (uchar *)0x0;
      ERR_put_error(0x2e,0x8c,0x6e,"crypto/cms/cms_env.c",400);
      goto LAB_001997a6;
    }
    iVar2 = EVP_PKEY_decrypt(*(EVP_PKEY_CTX **)(iVar6 + 0x18),(uchar *)0x0,local_114.rd_key,
                             (uchar *)(*(size_t **)(iVar6 + 0xc))[2],**(size_t **)(iVar6 + 0xc));
    if (0 < iVar2) {
      puVar5 = (uchar *)CRYPTO_malloc(local_114.rd_key[0],"crypto/cms/cms_env.c",0x199);
      if (puVar5 == (uchar *)0x0) {
        ERR_put_error(0x2e,0x8c,0x41,"crypto/cms/cms_env.c",0x19c);
      }
      else {
        iVar2 = EVP_PKEY_decrypt(*(EVP_PKEY_CTX **)(iVar6 + 0x18),puVar5,local_114.rd_key,
                                 (uchar *)(*(size_t **)(iVar6 + 0xc))[2],**(size_t **)(iVar6 + 0xc))
        ;
        if (((0 < iVar2) && (local_114.rd_key[0] != 0)) &&
           (uVar3 == 0 || local_114.rd_key[0] == uVar3)) {
          CRYPTO_clear_free(*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x14),
                            "crypto/cms/cms_env.c",0x1ab);
          pEVar1 = *(EVP_PKEY_CTX **)(iVar6 + 0x18);
          *(uchar **)(iVar4 + 0x10) = puVar5;
          *(uint *)(iVar4 + 0x14) = local_114.rd_key[0];
          EVP_PKEY_CTX_free(pEVar1);
          *(undefined4 *)(iVar6 + 0x18) = 0;
          return 1;
        }
        ERR_put_error(0x2e,0x8c,0x68,"crypto/cms/cms_env.c",0x1a5);
      }
      goto LAB_001997a6;
    }
  }
  puVar5 = (uchar *)0x0;
LAB_001997a6:
  EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar6 + 0x18));
  *(undefined4 *)(iVar6 + 0x18) = 0;
  CRYPTO_free(puVar5);
  return 0;
}


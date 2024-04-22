
int CMS_RecipientInfo_decrypt(CMS_ContentInfo *cms,CMS_RecipientInfo *ri)

{
  EVP_PKEY_CTX *ctx;
  int iVar1;
  int iVar2;
  uint uVar3;
  uchar *puVar4;
  int iVar5;
  size_t local_110;
  AES_KEY AStack_10c;
  
  iVar2 = *(int *)ri;
  if (iVar2 == 2) {
    iVar2 = *(int *)(ri + 4);
    iVar5 = *(int *)(*(int *)(cms + 4) + 0xc);
    if (*(int *)(iVar2 + 0x10) == 0) {
      ERR_put_error(0x2e,0x87,0x82,DAT_000d5e14,0x2ed);
      return 0;
    }
    iVar1 = OBJ_obj2nid(**(ASN1_OBJECT ***)(iVar2 + 8));
    if (iVar1 - 0x314U < 3) {
      iVar1 = *(int *)(DAT_000d5e18 + (iVar1 - 0x314U) * 4);
    }
    else {
      iVar1 = 0;
    }
    if (*(int *)(iVar2 + 0x14) != iVar1) {
      ERR_put_error(0x2e,0x87,0x76,DAT_000d5e14,0x2f4);
      return 0;
    }
    if (**(int **)(iVar2 + 0xc) < 0x10) {
      uVar3 = 0;
      ERR_put_error(0x2e,0x87,0x75,DAT_000d5e14,0x2fc);
    }
    else {
      iVar1 = AES_set_decrypt_key(*(uchar **)(iVar2 + 0x10),iVar1 << 3,&AStack_10c);
      if (iVar1 == 0) {
        puVar4 = (uchar *)CRYPTO_malloc(**(int **)(iVar2 + 0xc) + -8,DAT_000d5e14,0x306);
        if (puVar4 == (uchar *)0x0) {
          ERR_put_error(0x2e,0x87,0x41,DAT_000d5e14,0x309);
          uVar3 = 0;
        }
        else {
          iVar2 = AES_unwrap_key(&AStack_10c,(uchar *)0x0,puVar4,
                                 (uchar *)(*(uint **)(iVar2 + 0xc))[2],**(uint **)(iVar2 + 0xc));
          uVar3 = (uint)(0 < iVar2);
          if (0 < iVar2) {
            *(uchar **)(iVar5 + 0x10) = puVar4;
          }
          if (iVar2 < 1) {
            ERR_put_error(0x2e,0x87,0x9d,DAT_000d5e14,0x312);
            CRYPTO_free(puVar4);
          }
          else {
            *(int *)(iVar5 + 0x14) = iVar2;
          }
        }
      }
      else {
        ERR_put_error(0x2e,0x87,0x73,DAT_000d5e14,0x302);
        uVar3 = 0;
      }
    }
    OPENSSL_cleanse(&AStack_10c,0xf4);
    return uVar3;
  }
  if (iVar2 == 3) {
    iVar2 = cms_RecipientInfo_pwri_crypt(cms,ri,0);
    return iVar2;
  }
  if (iVar2 != 0) {
    ERR_put_error(0x2e,0x86,0x9b,DAT_000d5e14,0x333);
    return 0;
  }
  iVar2 = *(int *)(ri + 4);
  iVar5 = *(int *)(*(int *)(cms + 4) + 0xc);
  if (*(EVP_PKEY **)(iVar2 + 0x14) == (EVP_PKEY *)0x0) {
    ERR_put_error(0x2e,0x8c,0x85,DAT_000d5e14,0x1ad);
    return 0;
  }
  ctx = EVP_PKEY_CTX_new(*(EVP_PKEY **)(iVar2 + 0x14),(ENGINE *)0x0);
  *(EVP_PKEY_CTX **)(iVar2 + 0x18) = ctx;
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return 0;
  }
  iVar1 = EVP_PKEY_decrypt_init(ctx);
  if ((0 < iVar1) && (iVar1 = cms_env_asn1_ctrl(ri,1), iVar1 != 0)) {
    iVar1 = EVP_PKEY_CTX_ctrl(*(EVP_PKEY_CTX **)(iVar2 + 0x18),-1,0x200,10,0,ri);
    if (iVar1 < 1) {
      ERR_put_error(0x2e,0x8c,0x6e,DAT_000d5e14,0x1bd);
      iVar1 = 0;
      iVar5 = 0;
      puVar4 = (uchar *)0x0;
      goto LAB_000d5bee;
    }
    iVar1 = EVP_PKEY_decrypt(*(EVP_PKEY_CTX **)(iVar2 + 0x18),(uchar *)0x0,&local_110,
                             (uchar *)(*(size_t **)(iVar2 + 0xc))[2],**(size_t **)(iVar2 + 0xc));
    if (0 < iVar1) {
      puVar4 = (uchar *)CRYPTO_malloc(local_110,DAT_000d5e14,0x1c6);
      if (puVar4 == (uchar *)0x0) {
        iVar1 = 0;
        ERR_put_error(0x2e,0x8c,0x41,DAT_000d5e14,0x1c9);
        iVar5 = iVar1;
      }
      else {
        iVar1 = EVP_PKEY_decrypt(*(EVP_PKEY_CTX **)(iVar2 + 0x18),puVar4,&local_110,
                                 (uchar *)(*(size_t **)(iVar2 + 0xc))[2],**(size_t **)(iVar2 + 0xc))
        ;
        if (iVar1 < 1) {
          ERR_put_error(0x2e,0x8c,0x68,DAT_000d5e14,0x1d0);
          iVar1 = 1;
          iVar5 = 0;
        }
        else {
          if (*(void **)(iVar5 + 0x10) != (void *)0x0) {
            OPENSSL_cleanse(*(void **)(iVar5 + 0x10),*(size_t *)(iVar5 + 0x14));
            CRYPTO_free(*(void **)(iVar5 + 0x10));
          }
          iVar1 = 0;
          *(uchar **)(iVar5 + 0x10) = puVar4;
          *(size_t *)(iVar5 + 0x14) = local_110;
          iVar5 = 1;
        }
      }
      goto LAB_000d5bee;
    }
  }
  iVar1 = 0;
  puVar4 = (uchar *)0x0;
  iVar5 = 0;
LAB_000d5bee:
  if (*(EVP_PKEY_CTX **)(iVar2 + 0x18) != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar2 + 0x18));
    *(undefined4 *)(iVar2 + 0x18) = 0;
  }
  if (iVar1 != 0) {
    iVar5 = 0;
    CRYPTO_free(puVar4);
  }
  return iVar5;
}


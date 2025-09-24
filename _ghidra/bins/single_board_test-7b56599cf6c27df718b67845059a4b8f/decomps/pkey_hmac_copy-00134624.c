
undefined4 pkey_hmac_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  HMAC_CTX *sctx;
  
  pvVar1 = (void *)CRYPTO_zalloc(0x18,"crypto/hmac/hm_pmeth.c",0x1f);
  if (pvVar1 == (void *)0x0) {
    ERR_put_error(0xf,0x7b,0x41,"crypto/hmac/hm_pmeth.c",0x20);
  }
  else {
    *(undefined4 *)((int)pvVar1 + 8) = 4;
    iVar2 = HMAC_CTX_new();
    *(int *)((int)pvVar1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      CRYPTO_free(pvVar1);
    }
    else {
      *(void **)(param_1 + 0x14) = pvVar1;
      *(undefined4 *)(param_1 + 0x24) = 0;
      puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
      puVar4 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      sctx = (HMAC_CTX *)puVar3[5];
      *puVar4 = *puVar3;
      iVar2 = HMAC_CTX_copy((HMAC_CTX *)puVar4[5],sctx);
      if ((iVar2 != 0) &&
         (((void *)puVar3[3] == (void *)0x0 ||
          (iVar2 = ASN1_OCTET_STRING_set((ASN1_STRING *)(puVar4 + 1),(void *)puVar3[3],puVar3[1]),
          iVar2 != 0)))) {
        return 1;
      }
      pvVar1 = EVP_PKEY_CTX_get_data(param_1);
      if (pvVar1 != (void *)0x0) {
        HMAC_CTX_free(*(undefined4 *)((int)pvVar1 + 0x14));
        CRYPTO_clear_free(*(undefined4 *)((int)pvVar1 + 0xc),*(undefined4 *)((int)pvVar1 + 4),
                          "crypto/hmac/hm_pmeth.c",0x50);
        CRYPTO_free(pvVar1);
        EVP_PKEY_CTX_set_data(param_1,(void *)0x0);
        return 0;
      }
    }
  }
  return 0;
}


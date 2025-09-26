
undefined4
EVP_MD_CTX_reset(EVP_MD_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != (EVP_MD_CTX *)0x0) {
    if (param_1->digest != (EVP_MD *)0x0) {
      if ((param_1->digest->cleanup != (_func_1224 *)0x0) &&
         (iVar1 = EVP_MD_CTX_test_flags(param_1,2), iVar1 == 0)) {
        (*param_1->digest->cleanup)(param_1);
      }
      if (((param_1->md_data != (void *)0x0) && (0 < (int)param_1->digest->verify)) &&
         (iVar1 = EVP_MD_CTX_test_flags(param_1,4), iVar1 == 0)) {
        CRYPTO_clear_free(param_1->md_data,param_1->digest->verify,"crypto/evp/digest.c",0x1c,
                          param_4);
        param_1->md_data = (void *)0x0;
      }
    }
    iVar1 = EVP_MD_CTX_test_flags(param_1,0x400);
    if (iVar1 == 0) {
      EVP_PKEY_CTX_free(param_1->pctx);
    }
    ENGINE_finish(param_1->engine);
    OPENSSL_cleanse(param_1,0x18);
    return 1;
  }
  return 1;
}


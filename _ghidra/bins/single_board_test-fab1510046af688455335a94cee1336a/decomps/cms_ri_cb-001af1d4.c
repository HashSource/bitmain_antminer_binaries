
undefined4 cms_ri_cb(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 2) {
    param_2 = (int *)*param_2;
    iVar1 = *param_2;
    if (iVar1 == 0) {
      iVar1 = param_2[1];
      if (*(EVP_PKEY **)(iVar1 + 0x14) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)(iVar1 + 0x14));
      }
      if (*(X509 **)(iVar1 + 0x10) != (X509 *)0x0) {
        X509_free(*(X509 **)(iVar1 + 0x10));
      }
      if (*(EVP_PKEY_CTX **)(iVar1 + 0x18) != (EVP_PKEY_CTX *)0x0) {
        EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar1 + 0x18));
        return 1;
      }
    }
    else if ((iVar1 == 2) || (iVar1 == 3)) {
      iVar1 = param_2[1];
      if (*(void **)(iVar1 + 0x10) != (void *)0x0) {
        OPENSSL_cleanse(*(void **)(iVar1 + 0x10),*(size_t *)(iVar1 + 0x14));
        CRYPTO_free(*(void **)(iVar1 + 0x10));
      }
    }
  }
  return 1;
}


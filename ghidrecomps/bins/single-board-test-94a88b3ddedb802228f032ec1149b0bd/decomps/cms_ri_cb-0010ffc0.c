
undefined4 cms_ri_cb(int param_1,int **param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 2) {
    piVar1 = *param_2;
    iVar2 = *piVar1;
    if (iVar2 == 0) {
      iVar2 = piVar1[1];
      if (*(EVP_PKEY **)(iVar2 + 0x14) != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(*(EVP_PKEY **)(iVar2 + 0x14));
      }
      if (*(X509 **)(iVar2 + 0x10) != (X509 *)0x0) {
        X509_free(*(X509 **)(iVar2 + 0x10));
      }
      if (*(EVP_PKEY_CTX **)(iVar2 + 0x18) != (EVP_PKEY_CTX *)0x0) {
        EVP_PKEY_CTX_free(*(EVP_PKEY_CTX **)(iVar2 + 0x18));
        return 1;
      }
    }
    else if ((iVar2 == 2) || (iVar2 == 3)) {
      iVar2 = piVar1[1];
      if (*(void **)(iVar2 + 0x10) != (void *)0x0) {
        OPENSSL_cleanse(*(void **)(iVar2 + 0x10),*(size_t *)(iVar2 + 0x14));
        CRYPTO_free(*(void **)(iVar2 + 0x10));
      }
    }
  }
  return 1;
}


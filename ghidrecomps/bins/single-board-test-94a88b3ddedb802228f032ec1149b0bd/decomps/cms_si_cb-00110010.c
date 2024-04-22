
undefined4 cms_si_cb(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 3) {
    iVar1 = *param_2;
    if (*(EVP_PKEY **)(iVar1 + 0x20) != (EVP_PKEY *)0x0) {
      EVP_PKEY_free(*(EVP_PKEY **)(iVar1 + 0x20));
    }
    if (*(X509 **)(iVar1 + 0x1c) != (X509 *)0x0) {
      X509_free(*(X509 **)(iVar1 + 0x1c));
    }
    if (*(int *)(iVar1 + 0x3c) != 0) {
      EVP_MD_CTX_cleanup((EVP_MD_CTX *)(iVar1 + 0x24));
      return 1;
    }
  }
  return 1;
}


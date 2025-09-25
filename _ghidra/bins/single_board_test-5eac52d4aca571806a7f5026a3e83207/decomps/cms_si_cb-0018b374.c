
undefined4 cms_si_cb(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 != 3) {
    return 1;
  }
  iVar1 = *param_2;
  EVP_PKEY_free(*(EVP_PKEY **)(iVar1 + 0x20));
  X509_free(*(X509 **)(iVar1 + 0x1c));
  EVP_MD_CTX_free(*(undefined4 *)(iVar1 + 0x24));
  return 1;
}


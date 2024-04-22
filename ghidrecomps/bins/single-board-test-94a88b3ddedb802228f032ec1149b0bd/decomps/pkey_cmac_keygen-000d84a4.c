
undefined4 pkey_cmac_keygen(int param_1,EVP_PKEY *param_2)

{
  CMAC_CTX *out;
  int iVar1;
  
  out = CMAC_CTX_new();
  if (out == (CMAC_CTX *)0x0) {
    return 0;
  }
  iVar1 = CMAC_CTX_copy(out,*(CMAC_CTX **)(param_1 + 0x14));
  if (iVar1 != 0) {
    EVP_PKEY_assign(param_2,0x37e,out);
    return 1;
  }
  CMAC_CTX_free(out);
  return 0;
}


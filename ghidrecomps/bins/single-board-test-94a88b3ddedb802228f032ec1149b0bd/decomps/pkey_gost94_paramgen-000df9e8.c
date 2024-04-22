
undefined4
pkey_gost94_paramgen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DSA *r;
  int iVar2;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  if (*piVar1 == 0) {
    ERR_GOST_error(0x8b,0x77,DAT_000dfa34,0x105,param_4);
    return 0;
  }
  r = DSA_new();
  iVar2 = fill_GOST94_params(r,*piVar1);
  if (iVar2 != 0) {
    EVP_PKEY_assign(param_2,0x32c,r);
    return 1;
  }
  DSA_free(r);
  return 0;
}


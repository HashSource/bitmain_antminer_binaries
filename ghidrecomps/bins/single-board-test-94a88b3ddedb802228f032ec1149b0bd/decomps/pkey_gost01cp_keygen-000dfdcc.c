
undefined4 pkey_gost01cp_keygen(EVP_PKEY_CTX *param_1,EVP_PKEY *param_2)

{
  int *piVar1;
  EC_KEY *key;
  int iVar2;
  
  piVar1 = (int *)EVP_PKEY_CTX_get_data(param_1);
  if (*piVar1 == 0) {
    ERR_GOST_error(0x8a,0x77,DAT_000dfe20,0x117);
    return 0;
  }
  key = EC_KEY_new();
  iVar2 = fill_GOST2001_params(key,*piVar1);
  if (iVar2 != 0) {
    EVP_PKEY_assign(param_2,0x32b,key);
    EVP_PKEY_get0(param_2);
    gost2001_keygen();
    return 1;
  }
  EC_KEY_free(key);
  return 0;
}



int param_missing_gost01(EVP_PKEY *param_1)

{
  EC_KEY *key;
  EC_GROUP *pEVar1;
  int iVar2;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  if (key != (EC_KEY *)0x0) {
    pEVar1 = EC_KEY_get0_group(key);
    iVar2 = 1 - (int)pEVar1;
    if ((EC_GROUP *)0x1 < pEVar1) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 1;
}


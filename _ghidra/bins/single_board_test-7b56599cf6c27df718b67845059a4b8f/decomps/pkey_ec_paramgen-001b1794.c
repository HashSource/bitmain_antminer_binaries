
int pkey_ec_paramgen(int param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  if (*piVar2 == 0) {
    ERR_put_error(0x10,0xdb,0x8b,"crypto/ec/ec_pmeth.c",0x191);
    return 0;
  }
  key = EC_KEY_new();
  if (key != (EC_KEY *)0x0) {
    iVar1 = EC_KEY_set_group(key,(EC_GROUP *)*piVar2);
    if ((iVar1 != 0) && (iVar1 = EVP_PKEY_assign(param_2,0x198,key), iVar1 != 0)) {
      return iVar1;
    }
    EC_KEY_free(key);
    return 0;
  }
  return 0;
}


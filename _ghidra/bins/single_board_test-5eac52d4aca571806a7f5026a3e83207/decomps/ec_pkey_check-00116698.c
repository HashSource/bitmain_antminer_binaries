
int ec_pkey_check(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(EC_KEY **)(param_1 + 0x18) + 0x14) != 0) {
    iVar1 = EC_KEY_check_key(*(EC_KEY **)(param_1 + 0x18));
    return iVar1;
  }
  ERR_put_error(0x10,0x111,0x7d,"crypto/ec/ec_ameth.c",0x228);
  return 0;
}


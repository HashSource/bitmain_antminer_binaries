
int ec_pkey_param_check(int param_1)

{
  int iVar1;
  EC_GROUP *group;
  
  group = *(EC_GROUP **)(*(int *)(param_1 + 0x18) + 0xc);
  if (group != (EC_GROUP *)0x0) {
    iVar1 = EC_GROUP_check(group,(BN_CTX *)0x0);
    return iVar1;
  }
  ERR_put_error(0x10,0x112,0x7c,"crypto/ec/ec_ameth.c",0x245);
  return 0;
}


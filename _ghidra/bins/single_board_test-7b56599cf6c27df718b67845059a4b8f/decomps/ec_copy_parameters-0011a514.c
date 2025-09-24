
undefined4 ec_copy_parameters(int param_1,int param_2)

{
  EC_GROUP *pEVar1;
  EC_KEY *key;
  int iVar2;
  
  pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x18));
  pEVar1 = EC_GROUP_dup(pEVar1);
  if (pEVar1 == (EC_GROUP *)0x0) {
    return 0;
  }
  key = *(EC_KEY **)(param_1 + 0x18);
  if (key == (EC_KEY *)0x0) {
    key = EC_KEY_new();
    *(EC_KEY **)(param_1 + 0x18) = key;
    if (key == (EC_KEY *)0x0) goto LAB_0011a532;
  }
  iVar2 = EC_KEY_set_group(key,pEVar1);
  if (iVar2 != 0) {
    EC_GROUP_free(pEVar1);
    return 1;
  }
LAB_0011a532:
  EC_GROUP_free(pEVar1);
  return 0;
}


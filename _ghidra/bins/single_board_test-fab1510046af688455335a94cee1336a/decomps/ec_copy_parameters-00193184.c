
undefined4 ec_copy_parameters(int param_1,int param_2)

{
  EC_GROUP *pEVar1;
  int iVar2;
  
  pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14));
  pEVar1 = EC_GROUP_dup(pEVar1);
  if ((pEVar1 != (EC_GROUP *)0x0) &&
     (iVar2 = EC_KEY_set_group(*(EC_KEY **)(param_1 + 0x14),pEVar1), iVar2 != 0)) {
    EC_GROUP_free(pEVar1);
    return 1;
  }
  return 0;
}


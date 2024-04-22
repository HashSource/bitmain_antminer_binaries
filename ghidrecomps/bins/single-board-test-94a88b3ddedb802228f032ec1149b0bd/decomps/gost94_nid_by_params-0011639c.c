
undefined4 gost94_nid_by_params(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *str;
  BIGNUM *local_14 [2];
  
  puVar1 = DAT_001163e4;
  local_14[0] = BN_new();
  str = (char *)puVar1[3];
  while( true ) {
    if (str == (char *)0x0) {
      BN_free(local_14[0]);
      return 0;
    }
    BN_dec2bn(local_14,str);
    iVar2 = BN_cmp(local_14[0],*(BIGNUM **)(param_1 + 0x10));
    if (iVar2 == 0) break;
    str = (char *)puVar1[7];
    HintPreloadData(puVar1 + 0x23);
    puVar1 = puVar1 + 4;
  }
  BN_free(local_14[0]);
  return *puVar1;
}


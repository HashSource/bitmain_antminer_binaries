
undefined4 fill_GOST94_params(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *str;
  int iVar1;
  int *piVar2;
  
  iVar1 = *DAT_000e0504;
  piVar2 = DAT_000e0504;
  while( true ) {
    if (iVar1 == 0) {
      ERR_GOST_error(0x66,0x82,DAT_000e0508,0x109,param_4);
      return 0;
    }
    if (iVar1 == param_2) break;
    piVar2 = piVar2 + 4;
    iVar1 = *piVar2;
  }
  if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xc));
  }
  *(BIGNUM **)(param_1 + 0xc) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0xc),(char *)piVar2[2]);
  if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x10));
  }
  *(BIGNUM **)(param_1 + 0x10) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x10),(char *)piVar2[3]);
  if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x14));
  }
  str = (char *)piVar2[1];
  *(BIGNUM **)(param_1 + 0x14) = (BIGNUM *)0x0;
  BN_dec2bn((BIGNUM **)(param_1 + 0x14),str);
  return 1;
}


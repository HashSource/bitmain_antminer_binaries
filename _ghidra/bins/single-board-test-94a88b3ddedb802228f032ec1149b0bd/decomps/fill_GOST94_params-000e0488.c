
undefined4 fill_GOST94_params(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char *str;
  undefined1 *puVar2;
  
  if (R3410_paramset._0_4_ != 0) {
    if (R3410_paramset._0_4_ == param_2) {
      puVar2 = R3410_paramset;
    }
    else {
      piVar1 = (int *)(R3410_paramset + 0x10);
      do {
        puVar2 = (undefined1 *)piVar1;
        if (*(int *)puVar2 == 0) goto LAB_000e04a8;
        piVar1 = (int *)((int)puVar2 + 0x10);
      } while (*(int *)puVar2 != param_2);
    }
    if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0xc));
    }
    *(BIGNUM **)(param_1 + 0xc) = (BIGNUM *)0x0;
    BN_dec2bn((BIGNUM **)(param_1 + 0xc),*(char **)((int)puVar2 + 8));
    if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x10));
    }
    *(BIGNUM **)(param_1 + 0x10) = (BIGNUM *)0x0;
    BN_dec2bn((BIGNUM **)(param_1 + 0x10),*(char **)((int)puVar2 + 0xc));
    if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x14));
    }
    str = *(char **)((int)puVar2 + 4);
    *(BIGNUM **)(param_1 + 0x14) = (BIGNUM *)0x0;
    BN_dec2bn((BIGNUM **)(param_1 + 0x14),str);
    return 1;
  }
LAB_000e04a8:
  ERR_GOST_error(0x66,0x82,"gost_sign.c",0x109,param_4);
  return 0;
}


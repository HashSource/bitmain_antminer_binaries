
int EC_POINT_copy(EC_POINT *dst,EC_POINT *src)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)dst + 0x38);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x72,0x42,"crypto/ec/ec_lib.c",0x2c1);
    iVar1 = 0;
  }
  else if ((*(int *)dst == *(int *)src) &&
          (*(int *)(src + 4) == 0 ||
           (*(int *)(dst + 4) == *(int *)(src + 4) || *(int *)(dst + 4) == 0))) {
    if (dst != src) {
                    /* WARNING: Could not recover jumptable at 0x00127fe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    iVar1 = 1;
  }
  else {
    ERR_put_error(0x10,0x72,0x65,"crypto/ec/ec_lib.c",0x2c8);
    iVar1 = 0;
  }
  return iVar1;
}


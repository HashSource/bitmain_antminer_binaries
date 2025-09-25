
int EC_POINT_is_on_curve(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x6c);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x77,0x42,"crypto/ec/ec_lib.c",0x3ae);
  }
  else {
    if ((*(int *)group == *(int *)point) &&
       ((*(int *)(group + 0x10) == 0 ||
        (*(int *)(group + 0x10) == *(int *)(point + 4) || *(int *)(point + 4) == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x0011aa0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x77,0x65,"crypto/ec/ec_lib.c",0x3b2);
  }
  return 0;
}


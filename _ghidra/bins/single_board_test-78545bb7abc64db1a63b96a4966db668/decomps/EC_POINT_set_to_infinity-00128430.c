
int EC_POINT_set_to_infinity(EC_GROUP *group,EC_POINT *point)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x3c);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x7f,0x42,"crypto/ec/ec_lib.c",0x2ec);
  }
  else {
    if (*(int *)group == *(int *)point) {
                    /* WARNING: Could not recover jumptable at 0x00128460. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x7f,0x65,"crypto/ec/ec_lib.c",0x2f0);
  }
  return 0;
}


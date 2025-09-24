
int EC_POINT_invert(EC_GROUP *group,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 100);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0xd2,0x42,"crypto/ec/ec_lib.c",0x38b);
  }
  else {
    if ((*(int *)group == *(int *)a) &&
       ((*(int *)(group + 0x10) == 0 ||
        (*(int *)(group + 0x10) == *(int *)(a + 4) || *(int *)(a + 4) == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x0011eadc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0xd2,0x65,"crypto/ec/ec_lib.c",0x38f);
  }
  return 0;
}



int EC_POINT_make_affine(EC_GROUP *group,EC_POINT *point,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x74);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x78,0x42,"crypto/ec/ec_lib.c",0x3c9);
  }
  else {
    if ((*(int *)group == *(int *)point) &&
       ((*(int *)(group + 0x10) == 0 ||
        (*(int *)(group + 0x10) == *(int *)(point + 4) || *(int *)(point + 4) == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x0011ef78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x78,0x65,"crypto/ec/ec_lib.c",0x3cd);
  }
  return 0;
}



int EC_POINT_get_Jprojective_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,BIGNUM *y,BIGNUM *z,BN_CTX *ctx)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)group + 0x44);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x10,0x75,0x42,"crypto/ec/ec_lib.c",0x310);
  }
  else {
    if ((*(int *)group == *(int *)p) &&
       ((*(int *)(group + 0x10) == 0 ||
        (*(int *)(group + 0x10) == *(int *)(p + 4) || *(int *)(p + 4) == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x0011e968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    ERR_put_error(0x10,0x75,0x65,"crypto/ec/ec_lib.c",0x315);
  }
  return 0;
}


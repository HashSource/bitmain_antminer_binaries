
int EC_POINT_dbl(EC_GROUP *group,EC_POINT *r,EC_POINT *a,BN_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x60) == (code *)0x0) {
    ERR_put_error(0x10,0x73,0x42,"crypto/ec/ec_lib.c",0x37e);
  }
  else {
    if (iVar1 == *(int *)r) {
      iVar2 = *(int *)(group + 0x10);
      if (iVar2 == 0) {
        if (iVar1 == *(int *)a) goto LAB_0012864c;
      }
      else if (((*(int *)(r + 4) == 0 || iVar2 == *(int *)(r + 4)) && (iVar1 == *(int *)a)) &&
              (*(int *)(a + 4) == 0 || iVar2 == *(int *)(a + 4))) {
LAB_0012864c:
                    /* WARNING: Could not recover jumptable at 0x00128654. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (**(code **)(iVar1 + 0x60))();
        return iVar1;
      }
    }
    ERR_put_error(0x10,0x73,0x65,"crypto/ec/ec_lib.c",0x382);
  }
  return 0;
}


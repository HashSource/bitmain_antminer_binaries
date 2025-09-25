
int EC_POINT_cmp(EC_GROUP *group,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x70) == (code *)0x0) {
    ERR_put_error(0x10,0x71,0x42,"crypto/ec/ec_lib.c",0x3bc);
  }
  else {
    if (iVar1 == *(int *)a) {
      iVar2 = *(int *)(group + 0x10);
      if (iVar2 == 0) {
        if (iVar1 == *(int *)b) goto LAB_0011ab26;
      }
      else if (((*(int *)(a + 4) == 0 || iVar2 == *(int *)(a + 4)) && (iVar1 == *(int *)b)) &&
              (*(int *)(b + 4) == 0 || iVar2 == *(int *)(b + 4))) {
LAB_0011ab26:
                    /* WARNING: Could not recover jumptable at 0x0011ab2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (**(code **)(iVar1 + 0x70))();
        return iVar1;
      }
    }
    ERR_put_error(0x10,0x71,0x65,"crypto/ec/ec_lib.c",0x3c0);
  }
  return -1;
}



int EC_POINT_add(EC_GROUP *group,EC_POINT *r,EC_POINT *a,EC_POINT *b,BN_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)group;
  if (*(code **)(iVar1 + 0x5c) == (code *)0x0) {
    ERR_put_error(0x10,0x70,0x42,"crypto/ec/ec_lib.c",0x36f);
  }
  else {
    if (iVar1 == *(int *)r) {
      iVar2 = *(int *)(group + 0x10);
      if (iVar2 == 0) {
        if ((iVar1 == *(int *)a) && (iVar1 == *(int *)b)) goto LAB_0011a79a;
      }
      else if (((iVar2 == *(int *)(r + 4) || *(int *)(r + 4) == 0) &&
               (((iVar1 == *(int *)a && (iVar2 == *(int *)(a + 4) || *(int *)(a + 4) == 0)) &&
                (iVar1 == *(int *)b)))) && (*(int *)(b + 4) == 0 || iVar2 == *(int *)(b + 4))) {
LAB_0011a79a:
                    /* WARNING: Could not recover jumptable at 0x0011a7a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (**(code **)(iVar1 + 0x5c))();
        return iVar1;
      }
    }
    ERR_put_error(0x10,0x70,0x65,"crypto/ec/ec_lib.c",0x374);
  }
  return 0;
}



int EC_POINTs_make_affine(EC_GROUP *group,size_t num,EC_POINT **points,BN_CTX *ctx)

{
  EC_POINT *pEVar1;
  size_t sVar2;
  int iVar3;
  
  iVar3 = *(int *)group;
  if (*(code **)(iVar3 + 0x78) == (code *)0x0) {
    ERR_put_error(0x10,0x88,0x42,"crypto/ec/ec_lib.c",0x3d9);
  }
  else {
    if (num == 0) {
LAB_00128be2:
                    /* WARNING: Could not recover jumptable at 0x00128bec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (**(code **)(iVar3 + 0x78))();
      return iVar3;
    }
    pEVar1 = *points;
    if (iVar3 == *(int *)pEVar1) {
      sVar2 = 0;
      if (*(int *)(group + 0x10) == 0) {
        sVar2 = 0;
        do {
          sVar2 = sVar2 + 1;
          if (num == sVar2) goto LAB_00128be2;
          points = points + 1;
        } while (iVar3 == *(int *)*points);
      }
      else {
        do {
          if (*(int *)(pEVar1 + 4) != 0 && *(int *)(pEVar1 + 4) != *(int *)(group + 0x10)) break;
          sVar2 = sVar2 + 1;
          if (num == sVar2) goto LAB_00128be2;
          points = points + 1;
          pEVar1 = *points;
        } while (iVar3 == *(int *)pEVar1);
      }
    }
    ERR_put_error(0x10,0x88,0x65,"crypto/ec/ec_lib.c",0x3de);
  }
  return 0;
}



undefined4
EC_POINT_get_affine_coordinates_GF2m
          (EC_GROUP *param_1,EC_POINT *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)param_1 + 0x4c) == 0) {
    ERR_put_error(0x10,0x125,0x42,"crypto/ec/ec_lib.c",0x34b);
  }
  else {
    if ((*(int *)param_1 == *(int *)param_2) &&
       ((*(int *)(param_1 + 0x10) == 0 ||
        (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 4) || *(int *)(param_2 + 4) == 0)))) {
      iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
      if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x001287a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (**(code **)(*(int *)param_1 + 0x4c))(param_1,param_2,param_3,param_4);
        return uVar2;
      }
      ERR_put_error(0x10,0x125,0x6a,"crypto/ec/ec_lib.c",0x353);
      return 0;
    }
    ERR_put_error(0x10,0x125,0x65,"crypto/ec/ec_lib.c",0x34f);
  }
  return 0;
}



int EC_POINT_set_affine_coordinates_GF2m
              (EC_GROUP *param_1,EC_POINT *param_2,undefined4 param_3,undefined4 param_4,
              BN_CTX *param_5)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)param_1 + 0x48);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0x126,0x42,"crypto/ec/ec_lib.c",0x322);
    iVar1 = 0;
  }
  else if ((*(int *)param_1 == *(int *)param_2) &&
          ((*(int *)(param_1 + 0x10) == 0 ||
           (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 4) || *(int *)(param_2 + 4) == 0)))) {
    iVar1 = (*pcVar2)(param_1,param_2,param_3,param_4,param_5);
    if (iVar1 != 0) {
      iVar1 = EC_POINT_is_on_curve(param_1,param_2,param_5);
      if (iVar1 < 1) {
        ERR_put_error(0x10,0x126,0x6b,"crypto/ec/ec_lib.c",0x32d);
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
  }
  else {
    ERR_put_error(0x10,0x126,0x65,"crypto/ec/ec_lib.c",0x326);
    iVar1 = 0;
  }
  return iVar1;
}


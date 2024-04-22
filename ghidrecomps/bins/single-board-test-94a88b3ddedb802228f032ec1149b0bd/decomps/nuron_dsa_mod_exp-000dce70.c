
int nuron_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  int iVar2;
  BIGNUM BStack_2c;
  
  iVar2 = DAT_000dcef0;
  BN_init(&BStack_2c);
  if (*(int *)(iVar2 + 8) == 0) {
LAB_000dced6:
    iVar1 = *(int *)(iVar2 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x67,0x69,DAT_000dcef4,0xc1);
  }
  else {
    iVar1 = (**(code **)(iVar2 + 0xc))(param_2,param_3,param_4,param_7);
    if (iVar1 != 0) {
      if (*(int *)(iVar2 + 8) == 0) goto LAB_000dced6;
      iVar2 = (**(code **)(iVar2 + 0xc))(&BStack_2c,param_5,param_6,param_7);
      if (iVar2 != 0) {
        iVar2 = BN_mod_mul(param_2,param_2,&BStack_2c,param_7,param_8);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
        goto LAB_000dce9c;
      }
    }
  }
  iVar2 = 0;
LAB_000dce9c:
  BN_free(&BStack_2c);
  return iVar2;
}



int nuron_dsa_mod_exp(undefined4 param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,BIGNUM *param_7,BN_CTX *param_8)

{
  int iVar1;
  BIGNUM BStack_2c;
  
  BN_init(&BStack_2c);
  if (pvDSOHandle == 0) {
LAB_000dced6:
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc1);
  }
  else {
    iVar1 = (*pfnModExp)(param_2,param_3,param_4,param_7);
    if (iVar1 != 0) {
      if (pvDSOHandle == 0) goto LAB_000dced6;
      iVar1 = (*pfnModExp)(&BStack_2c,param_5,param_6,param_7);
      if (iVar1 != 0) {
        iVar1 = BN_mod_mul(param_2,param_2,&BStack_2c,param_7,param_8);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
        goto LAB_000dce9c;
      }
    }
  }
  iVar1 = 0;
LAB_000dce9c:
  BN_free(&BStack_2c);
  return iVar1;
}


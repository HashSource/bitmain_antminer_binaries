
undefined4
nuron_mod_exp_dh(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  undefined4 uVar1;
  
  if (pvDSOHandle == 0) {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc1);
    uVar1 = 0;
  }
  else {
    uVar1 = (*pfnModExp)(param_2,param_3,param_4,param_5);
  }
  return uVar1;
}


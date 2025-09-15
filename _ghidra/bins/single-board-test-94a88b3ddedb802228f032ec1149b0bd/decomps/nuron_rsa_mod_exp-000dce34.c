
undefined4 nuron_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3)

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
    uVar1 = (*pfnModExp)(param_1,param_2,*(undefined4 *)(param_3 + 0x18),
                         *(undefined4 *)(param_3 + 0x10));
  }
  return uVar1;
}


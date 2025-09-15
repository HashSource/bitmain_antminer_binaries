
undefined4 nuron_mod_exp_mont(void)

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
    uVar1 = (*pfnModExp)();
  }
  return uVar1;
}


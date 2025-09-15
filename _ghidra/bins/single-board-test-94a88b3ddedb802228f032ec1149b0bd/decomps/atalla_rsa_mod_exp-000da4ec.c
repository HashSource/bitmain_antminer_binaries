
undefined4 atalla_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x68,0x69,"e_atalla.c",0x215);
    uVar1 = 0;
  }
  else if ((*(int *)(param_3 + 0x18) == 0) || (*(int *)(param_3 + 0x10) == 0)) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x68,0x68,"e_atalla.c",0x21a);
    uVar1 = 0;
  }
  else {
    uVar1 = atalla_mod_exp(param_1,param_2,*(int *)(param_3 + 0x18),*(int *)(param_3 + 0x10),param_4
                          );
  }
  return uVar1;
}


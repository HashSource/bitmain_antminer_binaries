
void ERR_SUREWARE_error_constprop_5(int param_1,int param_2,int param_3)

{
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(SUREWARE_lib_error_code,param_1,param_2,"e_sureware.c",param_3);
  return;
}


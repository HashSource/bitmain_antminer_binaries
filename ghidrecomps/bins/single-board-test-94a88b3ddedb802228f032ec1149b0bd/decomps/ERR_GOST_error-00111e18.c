
void ERR_GOST_error(int param_1,int param_2,char *param_3,int param_4)

{
  if (GOST_lib_error_code == 0) {
    GOST_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(GOST_lib_error_code,param_1,param_2,param_3,param_4);
  return;
}


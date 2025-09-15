
char * atalla_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(ATALLA_lib_error_code,100,0x43,"e_atalla.c",0x1bb);
      pcVar1 = (char *)0x0;
    }
    else if (atalla_dso == 0) {
      if (ATALLA_LIBNAME != (char *)0x0) {
        CRYPTO_free(ATALLA_LIBNAME);
      }
      ATALLA_LIBNAME = (char *)0x0;
      ATALLA_LIBNAME = BUF_strdup(param_4);
      pcVar1 = ATALLA_LIBNAME;
      if (ATALLA_LIBNAME != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
    }
    else {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(ATALLA_lib_error_code,100,100,"e_atalla.c",0x1bf);
      pcVar1 = (char *)0x0;
    }
  }
  else {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,100,0x67,"e_atalla.c",0x1c6);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


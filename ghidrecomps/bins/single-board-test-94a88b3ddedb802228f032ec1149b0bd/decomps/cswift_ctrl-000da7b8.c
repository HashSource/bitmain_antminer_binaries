
char * cswift_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CSWIFT_lib_error_code,100,0x43,"e_cswift.c",0x1d7);
      pcVar1 = (char *)0x0;
    }
    else if (cswift_dso == 0) {
      if (CSWIFT_LIBNAME != (char *)0x0) {
        CRYPTO_free(CSWIFT_LIBNAME);
      }
      CSWIFT_LIBNAME = (char *)0x0;
      CSWIFT_LIBNAME = BUF_strdup(param_4);
      pcVar1 = CSWIFT_LIBNAME;
      if (CSWIFT_LIBNAME != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CSWIFT_lib_error_code,100,100,"e_cswift.c",0x1db);
      pcVar1 = (char *)0x0;
    }
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,100,0x68,"e_cswift.c",0x1e2);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



char * ubsec_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,100,0x43,"e_ubsec.c",0x227);
      pcVar1 = (char *)0x0;
    }
    else if (ubsec_dso == 0) {
      if (UBSEC_LIBNAME != (char *)0x0) {
        CRYPTO_free(UBSEC_LIBNAME);
      }
      UBSEC_LIBNAME = (char *)0x0;
      UBSEC_LIBNAME = BUF_strdup(param_4);
      pcVar1 = UBSEC_LIBNAME;
      if (UBSEC_LIBNAME != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
    }
    else {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,100,100,"e_ubsec.c",0x22b);
      pcVar1 = (char *)0x0;
    }
  }
  else {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,100,0x66,"e_ubsec.c",0x232);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


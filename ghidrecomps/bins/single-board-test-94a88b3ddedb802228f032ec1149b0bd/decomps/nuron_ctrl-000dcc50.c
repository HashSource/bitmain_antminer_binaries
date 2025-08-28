
char * nuron_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,100,0x43,"e_nuron.c",0xae);
      pcVar1 = (char *)0x0;
    }
    else if (pvDSOHandle == 0) {
      if (NURON_LIBNAME != (char *)0x0) {
        CRYPTO_free(NURON_LIBNAME);
      }
      NURON_LIBNAME = (char *)0x0;
      NURON_LIBNAME = BUF_strdup(param_4);
      pcVar1 = NURON_LIBNAME;
      if (NURON_LIBNAME != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
    }
    else {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(NURON_lib_error_code,100,100,"e_nuron.c",0xb2);
      pcVar1 = (char *)0x0;
    }
  }
  else {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(NURON_lib_error_code,100,0x65,"e_nuron.c",0xb9);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


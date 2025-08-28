
char * ibm_4758_cca_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,100,0x43,"e_4758cca.c",0x178);
      pcVar1 = (char *)0x0;
    }
    else if (dso == 0) {
      if (CCA4758_LIB_NAME != (char *)0x0) {
        CRYPTO_free(CCA4758_LIB_NAME);
      }
      CCA4758_LIB_NAME = (char *)0x0;
      CCA4758_LIB_NAME = BUF_strdup(param_4);
      pcVar1 = CCA4758_LIB_NAME;
      if (CCA4758_LIB_NAME != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
    }
    else {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(CCA4758_lib_error_code,100,100,"e_4758cca.c",0x17c);
      pcVar1 = (char *)0x0;
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CCA4758_lib_error_code,100,0x66,"e_4758cca.c",0x184);
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


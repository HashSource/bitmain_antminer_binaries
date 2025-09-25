
int openssl_config_int(undefined4 *param_1)

{
  int iVar1;
  char *appname;
  char *filename;
  ulong flags;
  
  if (openssl_configured == 0) {
    if (param_1 == (undefined4 *)0x0) {
      flags = 0x32;
      appname = (char *)0x0;
      filename = (char *)0x0;
    }
    else {
      filename = (char *)*param_1;
      appname = (char *)param_1[1];
      flags = param_1[2];
    }
    OPENSSL_load_builtin_modules();
    ENGINE_load_builtin_engines();
    ERR_clear_error();
    iVar1 = CONF_modules_load_file(filename,appname,flags);
    openssl_configured = 1;
    return iVar1;
  }
  return 1;
}


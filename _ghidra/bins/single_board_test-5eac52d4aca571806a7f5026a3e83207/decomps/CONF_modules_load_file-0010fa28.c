
int CONF_modules_load_file(char *filename,char *appname,ulong flags)

{
  CONF *conf;
  int iVar1;
  uint uVar2;
  ulong uVar3;
  char *file;
  
  conf = NCONF_new((CONF_METHOD *)0x0);
  if (conf == (CONF *)0x0) {
    uVar2 = 0;
    file = (char *)0x0;
LAB_0010fa5a:
    if (filename != (char *)0x0) goto LAB_0010fa5c;
  }
  else {
    file = filename;
    if ((filename != (char *)0x0) || (file = CONF_get1_default_config_file(), file != (char *)0x0))
    {
      iVar1 = NCONF_load(conf,file,(long *)0x0);
      if (iVar1 < 1) {
        uVar2 = flags & 0x10;
        if (uVar2 != 0) {
          uVar3 = ERR_peek_last_error();
          if ((uVar3 & 0xfff) == 0x72) {
            ERR_clear_error();
            uVar2 = 1;
          }
          else {
            uVar2 = 0;
          }
        }
      }
      else {
        uVar2 = CONF_modules_load(conf,appname,flags);
      }
      goto LAB_0010fa5a;
    }
    uVar2 = 0;
  }
  CRYPTO_free(file);
LAB_0010fa5c:
  NCONF_free(conf);
  if ((flags & 2) != 0) {
    uVar2 = 1;
  }
  return uVar2;
}


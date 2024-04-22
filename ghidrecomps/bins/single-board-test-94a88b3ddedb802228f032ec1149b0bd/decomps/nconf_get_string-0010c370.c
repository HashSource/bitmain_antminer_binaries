
char * nconf_get_string(CONF *conf,char *group,char *name)

{
  char *pcVar1;
  
  pcVar1 = _CONF_get_string(conf,group,name);
  if (pcVar1 == (char *)0x0) {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x6d,0x6a,DAT_0010d500,0x141);
    }
    else {
      ERR_put_error(0xe,0x6d,0x6c,DAT_0010d500,0x144);
      ERR_add_error_data(4,DAT_0010d504,group,DAT_0010d508,name);
    }
  }
  return pcVar1;
}


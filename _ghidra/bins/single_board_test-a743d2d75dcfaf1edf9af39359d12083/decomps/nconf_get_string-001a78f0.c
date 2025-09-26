
char * nconf_get_string(CONF *conf,char *group,char *name)

{
  char *pcVar1;
  
  pcVar1 = _CONF_get_string(conf,group,name);
  if (pcVar1 == (char *)0x0) {
    if (conf == (CONF *)0x0) {
      ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
    }
    else {
      ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x144);
      ERR_add_error_data(4,"group=",group," name=",name);
    }
  }
  return pcVar1;
}


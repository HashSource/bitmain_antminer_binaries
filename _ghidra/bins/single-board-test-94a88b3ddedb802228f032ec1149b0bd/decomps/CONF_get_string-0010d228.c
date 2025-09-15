
char * CONF_get_string(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  char *pcVar1;
  CONF CStack_24;
  
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar1 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
    }
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&CStack_24);
    CStack_24.data = conf;
    pcVar1 = _CONF_get_string(&CStack_24,group,name);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6c,"conf_lib.c",0x144);
      ERR_add_error_data(4,"group=",group," name=",name);
    }
  }
  return pcVar1;
}


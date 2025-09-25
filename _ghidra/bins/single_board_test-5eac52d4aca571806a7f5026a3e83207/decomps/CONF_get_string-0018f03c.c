
char * CONF_get_string(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  char *pcVar1;
  CONF CStack_1c;
  CONF *conf_00;
  
  conf_00 = (CONF *)conf;
  if (conf != (lhash_st_CONF_VALUE *)0x0) {
    conf_00 = &CStack_1c;
    CONF_set_nconf(conf_00,conf);
  }
  pcVar1 = NCONF_get_string(conf_00,group,name);
  return pcVar1;
}


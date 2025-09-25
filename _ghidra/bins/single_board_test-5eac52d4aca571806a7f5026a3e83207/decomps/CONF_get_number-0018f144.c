
long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  int iVar1;
  long local_20;
  CONF CStack_1c;
  
  local_20 = 0;
  ERR_set_mark();
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    iVar1 = NCONF_get_number_e((CONF *)0x0,group,name,&local_20);
  }
  else {
    CONF_set_nconf(&CStack_1c,conf);
    iVar1 = NCONF_get_number_e(&CStack_1c,group,name,&local_20);
  }
  ERR_pop_to_mark();
  if (iVar1 != 0) {
    iVar1 = local_20;
  }
  return iVar1;
}


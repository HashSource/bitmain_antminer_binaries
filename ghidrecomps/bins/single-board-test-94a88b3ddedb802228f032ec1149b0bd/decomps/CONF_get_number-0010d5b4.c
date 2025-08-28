
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  int iVar1;
  char *pcVar2;
  long local_28;
  CONF CStack_24;
  
  local_28 = 0;
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar2 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar2 != (char *)0x0) {
      local_28 = 0;
      while( true ) {
        iVar1 = (**(code **)(_shift + 0x1c))(0,*pcVar2);
        if (iVar1 == 0) break;
        iVar1 = local_28 * 10;
        local_28 = (**(code **)(_shift + 0x20))(0,*pcVar2);
        local_28 = iVar1 + local_28;
        pcVar2 = pcVar2 + 1;
      }
      return local_28;
    }
    ERR_put_error(0xe,0x6d,0x6a,"conf_lib.c",0x141);
  }
  else {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&CStack_24);
    CStack_24.data = conf;
    iVar1 = NCONF_get_number_e(&CStack_24,group,name,&local_28);
    if (iVar1 != 0) {
      return local_28;
    }
  }
  ERR_clear_error();
  return local_28;
}


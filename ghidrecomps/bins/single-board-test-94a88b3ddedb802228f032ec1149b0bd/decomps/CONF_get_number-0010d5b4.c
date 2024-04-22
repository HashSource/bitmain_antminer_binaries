
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  int iVar3;
  char *pcVar4;
  int local_28;
  CONF CStack_24;
  
  ppCVar1 = DAT_0010d644;
  local_28 = 0;
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar4 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar4 != (char *)0x0) {
      local_28 = 0;
      while( true ) {
        iVar3 = (**(code **)(_shift + 0x1c))(0,*pcVar4);
        if (iVar3 == 0) break;
        iVar3 = local_28 * 10;
        local_28 = (**(code **)(_shift + 0x20))(0,*pcVar4);
        local_28 = iVar3 + local_28;
        pcVar4 = pcVar4 + 1;
      }
      return local_28;
    }
    ERR_put_error(0xe,0x6d,0x6a,DAT_0010d648,0x141);
  }
  else {
    pCVar2 = *DAT_0010d644;
    if (pCVar2 == (CONF_METHOD *)0x0) {
      pCVar2 = NCONF_default();
      *ppCVar1 = pCVar2;
    }
    (*pCVar2->init)(&CStack_24);
    CStack_24.data = conf;
    iVar3 = NCONF_get_number_e(&CStack_24,group,name,&local_28);
    if (iVar3 != 0) {
      return local_28;
    }
  }
  ERR_clear_error();
  return local_28;
}


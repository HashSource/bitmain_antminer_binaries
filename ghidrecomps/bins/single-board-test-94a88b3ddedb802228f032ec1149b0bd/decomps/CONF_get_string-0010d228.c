
char * CONF_get_string(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  char *pcVar3;
  CONF CStack_24;
  
  ppCVar1 = DAT_0010d2a4;
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar3 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar3 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6a,DAT_0010d2a8,0x141);
    }
  }
  else {
    pCVar2 = *DAT_0010d2a4;
    if (pCVar2 == (CONF_METHOD *)0x0) {
      pCVar2 = NCONF_default();
      *ppCVar1 = pCVar2;
    }
    (*pCVar2->init)(&CStack_24);
    CStack_24.data = conf;
    pcVar3 = _CONF_get_string(&CStack_24,group,name);
    if (pcVar3 == (char *)0x0) {
      ERR_put_error(0xe,0x6d,0x6c,DAT_0010d2a8,0x144);
      ERR_add_error_data(4,DAT_0010d2ac,group,DAT_0010d2b0,name);
    }
  }
  return pcVar3;
}


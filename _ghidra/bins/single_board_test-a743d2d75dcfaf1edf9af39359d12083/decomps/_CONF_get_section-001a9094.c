
CONF_VALUE * _CONF_get_section(CONF *conf,char *section)

{
  CONF_VALUE *pCVar1;
  char *local_14;
  undefined4 local_10;
  
  if (conf == (CONF *)0x0 || section == (char *)0x0) {
    pCVar1 = (CONF_VALUE *)0x0;
  }
  else {
    local_10 = 0;
    local_14 = section;
    pCVar1 = (CONF_VALUE *)lh_retrieve((_LHASH *)conf->data,&local_14);
  }
  return pCVar1;
}


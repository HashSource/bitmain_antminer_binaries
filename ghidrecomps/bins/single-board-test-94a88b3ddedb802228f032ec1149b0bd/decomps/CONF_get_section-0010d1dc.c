
stack_st_CONF_VALUE * CONF_get_section(lhash_st_CONF_VALUE *conf,char *section)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  CONF CStack_1c;
  
  ppCVar1 = DAT_0010d220;
  if (conf != (lhash_st_CONF_VALUE *)0x0) {
    pCVar2 = *DAT_0010d220;
    if (pCVar2 == (CONF_METHOD *)0x0) {
      pCVar2 = NCONF_default();
      *ppCVar1 = pCVar2;
    }
    (*pCVar2->init)(&CStack_1c);
    CStack_1c.data = conf;
    if (section == (char *)0x0) {
      ERR_put_error(0xe,0x6c,0x6b,DAT_0010d224,0x12d);
      conf = (lhash_st_CONF_VALUE *)0x0;
    }
    else {
      conf = (lhash_st_CONF_VALUE *)_CONF_get_section_values(&CStack_1c,section);
    }
  }
  return (stack_st_CONF_VALUE *)conf;
}



void CONF_free(lhash_st_CONF_VALUE *conf)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  CONF local_1c;
  
  ppCVar1 = DAT_0010d2dc;
  pCVar2 = *DAT_0010d2dc;
  if (pCVar2 == (CONF_METHOD *)0x0) {
    pCVar2 = NCONF_default();
    *ppCVar1 = pCVar2;
  }
  (*pCVar2->init)(&local_1c);
  local_1c.data = conf;
  (*(local_1c.meth)->destroy_data)(&local_1c);
  return;
}


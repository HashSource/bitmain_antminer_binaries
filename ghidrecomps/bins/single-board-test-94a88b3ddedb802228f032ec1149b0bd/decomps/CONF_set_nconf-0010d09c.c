
void CONF_set_nconf(CONF *conf,lhash_st_CONF_VALUE *hash)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  
  ppCVar1 = DAT_0010d0bc;
  pCVar2 = *DAT_0010d0bc;
  if (pCVar2 == (CONF_METHOD *)0x0) {
    pCVar2 = NCONF_default();
    *ppCVar1 = pCVar2;
  }
  (*pCVar2->init)(conf);
  conf->data = hash;
  return;
}


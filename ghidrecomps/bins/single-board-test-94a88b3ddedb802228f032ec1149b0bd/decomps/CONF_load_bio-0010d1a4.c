
lhash_st_CONF_VALUE * CONF_load_bio(lhash_st_CONF_VALUE *conf,BIO *bp,long *eline)

{
  CONF_METHOD **ppCVar1;
  CONF_METHOD *pCVar2;
  lhash_st_CONF_VALUE *plVar3;
  CONF local_24;
  
  ppCVar1 = DAT_0010d1d8;
  pCVar2 = *DAT_0010d1d8;
  if (pCVar2 == (CONF_METHOD *)0x0) {
    pCVar2 = NCONF_default();
    *ppCVar1 = pCVar2;
  }
  (*pCVar2->init)(&local_24);
  local_24.data = conf;
  plVar3 = (lhash_st_CONF_VALUE *)(*(local_24.meth)->load_bio)(&local_24,bp,eline);
  if (plVar3 != (lhash_st_CONF_VALUE *)0x0) {
    plVar3 = local_24.data;
  }
  return plVar3;
}


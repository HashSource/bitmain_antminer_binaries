
lhash_st_CONF_VALUE * CONF_load_bio(lhash_st_CONF_VALUE *conf,BIO *bp,long *eline)

{
  lhash_st_CONF_VALUE *plVar1;
  CONF local_24;
  
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_24);
  local_24.data = conf;
  plVar1 = (lhash_st_CONF_VALUE *)(*(local_24.meth)->load_bio)(&local_24,bp,eline);
  if (plVar1 != (lhash_st_CONF_VALUE *)0x0) {
    plVar1 = local_24.data;
  }
  return plVar1;
}



int CONF_dump_bio(lhash_st_CONF_VALUE *conf,BIO *out)

{
  int iVar1;
  CONF local_1c;
  
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_1c);
  local_1c.data = conf;
  iVar1 = (*(local_1c.meth)->dump)(&local_1c,out);
  return iVar1;
}


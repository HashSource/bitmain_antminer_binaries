
void CONF_set_nconf(CONF *conf,lhash_st_CONF_VALUE *hash)

{
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(conf);
  conf->data = hash;
  return;
}



void CONF_free(lhash_st_CONF_VALUE *conf)

{
  CONF local_1c;
  
  if (default_CONF_method == (CONF_METHOD *)0x0) {
    default_CONF_method = NCONF_default();
  }
  (*default_CONF_method->init)(&local_1c);
  local_1c.data = conf;
  (*(local_1c.meth)->destroy_data)(&local_1c);
  return;
}


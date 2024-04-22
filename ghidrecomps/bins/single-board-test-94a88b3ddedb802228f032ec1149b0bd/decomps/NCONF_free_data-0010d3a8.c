
void NCONF_free_data(CONF *conf)

{
  if (conf != (CONF *)0x0) {
    (*conf->meth->destroy_data)(conf);
  }
  return;
}


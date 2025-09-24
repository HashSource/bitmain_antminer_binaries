
void _CONF_free_data(CONF *conf)

{
  if ((conf != (CONF *)0x0) && (conf->data != (lhash_st_CONF_VALUE *)0x0)) {
    OPENSSL_LH_set_down_load(conf->data,0);
    OPENSSL_LH_doall_arg(conf->data,0x1d1481);
    OPENSSL_LH_doall(conf->data,0x1d14c5);
    OPENSSL_LH_free(conf->data);
    return;
  }
  return;
}


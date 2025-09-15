
void NCONF_free(CONF *conf)

{
  if (conf != (CONF *)0x0) {
    (*conf->meth->destroy)(conf);
  }
  return;
}


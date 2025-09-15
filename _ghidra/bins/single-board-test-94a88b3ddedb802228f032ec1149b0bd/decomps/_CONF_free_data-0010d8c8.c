
void _CONF_free_data(CONF *conf)

{
  _LHASH *lh;
  
  if ((conf != (CONF *)0x0) && (lh = (_LHASH *)conf->data, lh != (_LHASH *)0x0)) {
    lh->down_load = 0;
    lh_doall_arg(lh,(LHASH_DOALL_ARG_FN_TYPE)0x10d725,lh);
    lh_doall((_LHASH *)conf->data,(LHASH_DOALL_FN_TYPE)0x10d6d5);
    lh_free((_LHASH *)conf->data);
    return;
  }
  return;
}


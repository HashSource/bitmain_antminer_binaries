
void _CONF_free_data(CONF *conf)

{
  _LHASH *lh;
  
  if ((conf != (CONF *)0x0) && (lh = (_LHASH *)conf->data, lh != (_LHASH *)0x0)) {
    lh->down_load = 0;
    lh_doall_arg(lh,DAT_0010d8f4,lh);
    lh_doall((_LHASH *)conf->data,DAT_0010d8f8);
    lh_free((_LHASH *)conf->data);
    return;
  }
  return;
}


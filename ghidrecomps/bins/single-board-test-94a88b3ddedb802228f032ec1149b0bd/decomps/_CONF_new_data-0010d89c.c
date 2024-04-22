
int _CONF_new_data(CONF *conf)

{
  _LHASH *p_Var1;
  
  if (conf == (CONF *)0x0) {
    return 0;
  }
  if (conf->data != (lhash_st_CONF_VALUE *)0x0) {
    return 1;
  }
  p_Var1 = lh_new(DAT_0010d8c4,DAT_0010d8c0);
  conf->data = (lhash_st_CONF_VALUE *)p_Var1;
  if (p_Var1 != (_LHASH *)0x0) {
    p_Var1 = (_LHASH *)0x1;
  }
  return (int)p_Var1;
}



lhash_st_CONF_VALUE * CONF_load_bio(lhash_st_CONF_VALUE *conf,BIO *bp,long *eline)

{
  lhash_st_CONF_VALUE *plVar1;
  CONF CStack_1c;
  
  CONF_set_nconf(&CStack_1c,conf);
  plVar1 = (lhash_st_CONF_VALUE *)NCONF_load_bio(&CStack_1c,bp,eline);
  if (plVar1 != (lhash_st_CONF_VALUE *)0x0) {
    plVar1 = CStack_1c.data;
  }
  return plVar1;
}


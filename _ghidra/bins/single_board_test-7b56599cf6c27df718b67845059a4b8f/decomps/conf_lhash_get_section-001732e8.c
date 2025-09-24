
stack_st_CONF_VALUE * conf_lhash_get_section(lhash_st_CONF_VALUE *conf,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  CONF CStack_1c;
  
  if (conf != (lhash_st_CONF_VALUE *)0x0) {
    CONF_set_nconf(&CStack_1c,conf);
    psVar1 = NCONF_get_section(&CStack_1c,section);
    return psVar1;
  }
  return (stack_st_CONF_VALUE *)0x0;
}


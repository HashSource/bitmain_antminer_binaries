
void CONF_free(lhash_st_CONF_VALUE *conf)

{
  CONF CStack_14;
  
  CONF_set_nconf(&CStack_14,conf);
  NCONF_free_data(&CStack_14);
  return;
}


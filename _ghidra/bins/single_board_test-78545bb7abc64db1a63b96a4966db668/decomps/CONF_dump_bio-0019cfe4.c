
int CONF_dump_bio(lhash_st_CONF_VALUE *conf,BIO *out)

{
  int iVar1;
  CONF CStack_1c;
  
  CONF_set_nconf(&CStack_1c,conf);
  iVar1 = NCONF_dump_bio(&CStack_1c,out);
  return iVar1;
}


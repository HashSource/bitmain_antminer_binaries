
int X509V3_EXT_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  int iVar1;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  iVar1 = X509V3_EXT_add_nconf(&CStack_24,ctx,section,cert);
  return iVar1;
}


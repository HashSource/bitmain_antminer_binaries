
int X509V3_EXT_REQ_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  int iVar1;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  iVar1 = X509V3_EXT_REQ_add_nconf(&CStack_24,ctx,section,req);
  return iVar1;
}


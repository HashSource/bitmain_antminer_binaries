
X509_EXTENSION * X509V3_EXT_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *name,char *value)

{
  X509_EXTENSION *pXVar1;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  pXVar1 = X509V3_EXT_nconf(&CStack_24,ctx,name,value);
  return pXVar1;
}


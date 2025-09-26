
X509_EXTENSION *
X509V3_EXT_conf_nid(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,int ext_nid,char *value)

{
  X509_EXTENSION *pXVar1;
  CONF CStack_24;
  
  CONF_set_nconf(&CStack_24,conf);
  pXVar1 = X509V3_EXT_nconf_nid(&CStack_24,ctx,ext_nid,value);
  return pXVar1;
}


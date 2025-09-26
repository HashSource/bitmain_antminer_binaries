
int X509V3_EXT_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  int iVar1;
  stack_st_X509_EXTENSION **sk;
  CONF CStack_1c;
  
  CONF_set_nconf(&CStack_1c,conf);
  if (cert == (X509 *)0x0) {
    sk = (stack_st_X509_EXTENSION **)0x0;
  }
  else {
    sk = &cert->cert_info->extensions;
  }
  iVar1 = X509V3_EXT_add_nconf_sk(&CStack_1c,ctx,section,sk);
  return iVar1;
}



int X509V3_EXT_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509 *cert)

{
  int iVar1;
  
  if (cert != (X509 *)0x0) {
    cert = (X509 *)&cert->cert_info->extensions;
  }
  iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,(stack_st_X509_EXTENSION **)cert);
  return iVar1;
}


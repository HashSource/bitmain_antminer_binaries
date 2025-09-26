
int X509V3_EXT_CRL_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509_CRL *crl)

{
  int iVar1;
  
  if (crl != (X509_CRL *)0x0) {
    crl = (X509_CRL *)&crl->crl->extensions;
  }
  iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,(stack_st_X509_EXTENSION **)crl);
  return iVar1;
}


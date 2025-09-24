
int X509V3_EXT_REQ_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  int iVar1;
  stack_st_X509_EXTENSION *local_14 [2];
  
  local_14[0] = (stack_st_X509_EXTENSION *)0x0;
  if (req == (X509_REQ *)0x0) {
    iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,(stack_st_X509_EXTENSION **)0x0);
    return iVar1;
  }
  iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,local_14);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = X509_REQ_add_extensions(req,local_14[0]);
  OPENSSL_sk_pop_free(local_14[0],0x16d42d);
  return iVar1;
}



int X509V3_EXT_REQ_add_nconf(CONF *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  int iVar1;
  _STACK *local_14 [2];
  
  local_14[0] = (_STACK *)0x0;
  if (req == (X509_REQ *)0x0) {
    iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,(stack_st_X509_EXTENSION **)0x0);
  }
  else {
    iVar1 = X509V3_EXT_add_nconf_sk(conf,ctx,section,(stack_st_X509_EXTENSION **)local_14);
    if (iVar1 != 0) {
      iVar1 = X509_REQ_add_extensions(req,(stack_st_X509_EXTENSION *)local_14[0]);
      sk_pop_free(local_14[0],DAT_0010ca1c);
    }
  }
  return iVar1;
}


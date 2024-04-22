
int X509V3_EXT_REQ_add_conf(lhash_st_CONF_VALUE *conf,X509V3_CTX *ctx,char *section,X509_REQ *req)

{
  int iVar1;
  _STACK *local_20;
  CONF CStack_1c;
  
  CONF_set_nconf(&CStack_1c,conf);
  local_20 = (_STACK *)0x0;
  if (req == (X509_REQ *)0x0) {
    iVar1 = X509V3_EXT_add_nconf_sk(&CStack_1c,ctx,section,(stack_st_X509_EXTENSION **)0x0);
  }
  else {
    iVar1 = X509V3_EXT_add_nconf_sk(&CStack_1c,ctx,section,(stack_st_X509_EXTENSION **)&local_20);
    if (iVar1 != 0) {
      iVar1 = X509_REQ_add_extensions(req,(stack_st_X509_EXTENSION *)local_20);
      sk_pop_free(local_20,DAT_0010cd60);
    }
  }
  return iVar1;
}


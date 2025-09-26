
int X509_LOOKUP_by_alias(X509_LOOKUP *ctx,int type,char *str,int len,X509_OBJECT *ret)

{
  X509_LOOKUP_METHOD *pXVar1;
  
  pXVar1 = ctx->method;
  if ((pXVar1 != (X509_LOOKUP_METHOD *)0x0) &&
     (pXVar1 = (X509_LOOKUP_METHOD *)pXVar1->get_by_alias, pXVar1 != (X509_LOOKUP_METHOD *)0x0)) {
    pXVar1 = (X509_LOOKUP_METHOD *)(*(code *)pXVar1)();
  }
  return (int)pXVar1;
}



int X509_LOOKUP_by_subject(X509_LOOKUP *ctx,int type,X509_NAME *name,X509_OBJECT *ret)

{
  int iVar1;
  X509_LOOKUP_METHOD *pXVar2;
  
  pXVar2 = ctx->method;
  if ((pXVar2 != (X509_LOOKUP_METHOD *)0x0) &&
     (pXVar2 = (X509_LOOKUP_METHOD *)pXVar2->get_by_subject, pXVar2 != (X509_LOOKUP_METHOD *)0x0)) {
    if (ctx->skip != 0) {
      return 0;
    }
    iVar1 = (*(code *)pXVar2)();
    return iVar1;
  }
  return (int)pXVar2;
}


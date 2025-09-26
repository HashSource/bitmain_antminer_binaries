
int X509_LOOKUP_by_issuer_serial
              (X509_LOOKUP *ctx,int type,X509_NAME *name,ASN1_INTEGER *serial,X509_OBJECT *ret)

{
  X509_LOOKUP_METHOD *pXVar1;
  
  pXVar1 = ctx->method;
  if ((pXVar1 != (X509_LOOKUP_METHOD *)0x0) &&
     (pXVar1 = (X509_LOOKUP_METHOD *)pXVar1->get_by_issuer_serial,
     pXVar1 != (X509_LOOKUP_METHOD *)0x0)) {
    pXVar1 = (X509_LOOKUP_METHOD *)(*(code *)pXVar1)();
  }
  return (int)pXVar1;
}



int X509_CRL_set_issuer_name(X509_CRL *x,X509_NAME *name)

{
  int iVar1;
  
  if (x != (X509_CRL *)0x0) {
    iVar1 = X509_NAME_set((X509_NAME **)&x->references,name);
    return iVar1;
  }
  return 0;
}



int X509_CRL_set_issuer_name(X509_CRL *x,X509_NAME *name)

{
  int iVar1;
  
  if ((x != (X509_CRL *)0x0) && (x->crl != (X509_CRL_INFO *)0x0)) {
    iVar1 = X509_NAME_set(&x->crl->issuer,name);
    return iVar1;
  }
  return 0;
}


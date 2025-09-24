
int X509_CRL_set_version(X509_CRL *x,long version)

{
  X509_CRL_INFO *a;
  int iVar1;
  
  if (x == (X509_CRL *)0x0) {
    return 0;
  }
  a = x->crl;
  if (a == (X509_CRL_INFO *)0x0) {
    a = (X509_CRL_INFO *)ASN1_INTEGER_new();
    x->crl = a;
    if (a == (X509_CRL_INFO *)0x0) {
      return 0;
    }
  }
  iVar1 = ASN1_INTEGER_set((ASN1_INTEGER *)a,version);
  return iVar1;
}


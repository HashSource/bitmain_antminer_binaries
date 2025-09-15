
int X509_CRL_set_version(X509_CRL *x,long version)

{
  ASN1_INTEGER *a;
  int iVar1;
  ASN1_STRING *pAVar2;
  X509_CRL_INFO *pXVar3;
  
  if (x == (X509_CRL *)0x0) {
    return 0;
  }
  pXVar3 = x->crl;
  a = pXVar3->version;
  if (a == (ASN1_INTEGER *)0x0) {
    pAVar2 = ASN1_STRING_type_new(2);
    pXVar3->version = pAVar2;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      return 0;
    }
    a = x->crl->version;
  }
  iVar1 = ASN1_INTEGER_set(a,version);
  return iVar1;
}



int X509_REQ_set_version(X509_REQ *x,long version)

{
  int iVar1;
  
  if (x != (X509_REQ *)0x0) {
    x->signature = (ASN1_BIT_STRING *)0x1;
    iVar1 = ASN1_INTEGER_set((ASN1_INTEGER *)x->references,version);
    return iVar1;
  }
  return 0;
}


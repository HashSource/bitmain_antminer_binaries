
int X509_REVOKED_set_serialNumber(X509_REVOKED *x,ASN1_INTEGER *serial)

{
  ASN1_INTEGER *pAVar1;
  ASN1_STRING *pAVar2;
  
  if (x == (X509_REVOKED *)0x0) {
    return 0;
  }
  pAVar1 = x->serialNumber;
  if (pAVar1 != serial) {
    pAVar2 = ASN1_STRING_dup(serial);
    if (pAVar2 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(x->serialNumber);
      x->serialNumber = pAVar2;
      return 1;
    }
    return 0;
  }
  if (pAVar1 != (ASN1_INTEGER *)0x0) {
    pAVar1 = (ASN1_INTEGER *)0x1;
  }
  return (int)pAVar1;
}


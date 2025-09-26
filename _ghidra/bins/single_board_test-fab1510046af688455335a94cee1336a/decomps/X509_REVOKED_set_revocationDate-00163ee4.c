
int X509_REVOKED_set_revocationDate(X509_REVOKED *r,ASN1_TIME *tm)

{
  ASN1_TIME *pAVar1;
  ASN1_STRING *pAVar2;
  
  if (r == (X509_REVOKED *)0x0) {
    return 0;
  }
  pAVar1 = r->revocationDate;
  if (pAVar1 != tm) {
    pAVar2 = ASN1_STRING_dup(tm);
    if (pAVar2 != (ASN1_STRING *)0x0) {
      ASN1_STRING_free(r->revocationDate);
      r->revocationDate = pAVar2;
      return 1;
    }
    return 0;
  }
  if (pAVar1 != (ASN1_TIME *)0x0) {
    pAVar1 = (ASN1_TIME *)0x1;
  }
  return (int)pAVar1;
}


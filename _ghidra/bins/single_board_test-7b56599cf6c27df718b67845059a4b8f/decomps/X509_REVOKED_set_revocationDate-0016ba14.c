
int X509_REVOKED_set_revocationDate(X509_REVOKED *r,ASN1_TIME *tm)

{
  if (r != (X509_REVOKED *)0x0) {
    if (((ASN1_TIME *)r->reason != tm) && (tm = ASN1_STRING_dup(tm), tm != (ASN1_STRING *)0x0)) {
      ASN1_TIME_free((ASN1_TIME *)r->reason);
      r->reason = (int)tm;
    }
    if (tm != (ASN1_STRING *)0x0) {
      tm = (ASN1_STRING *)0x1;
    }
    return (int)tm;
  }
  return 0;
}


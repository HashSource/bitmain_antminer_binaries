
int PKCS7_add0_attrib_signing_time(PKCS7_SIGNER_INFO *si,ASN1_TIME *t)

{
  int iVar1;
  
  if ((t == (ASN1_TIME *)0x0) && (t = X509_gmtime_adj((ASN1_TIME *)0x0,0), t == (ASN1_TIME *)0x0)) {
    ERR_put_error(0x21,0x87,0x41,DAT_000d1254,0x90);
    return 0;
  }
  iVar1 = PKCS7_add_signed_attribute(si,0x34,0x17,t);
  return iVar1;
}


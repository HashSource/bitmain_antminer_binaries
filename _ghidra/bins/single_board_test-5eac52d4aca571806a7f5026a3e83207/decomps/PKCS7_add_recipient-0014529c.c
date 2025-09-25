
PKCS7_RECIP_INFO * PKCS7_add_recipient(PKCS7 *p7,X509 *x509)

{
  PKCS7_RECIP_INFO *p7i;
  int iVar1;
  
  p7i = PKCS7_RECIP_INFO_new();
  if (((p7i != (PKCS7_RECIP_INFO *)0x0) && (iVar1 = PKCS7_RECIP_INFO_set(p7i,x509), iVar1 != 0)) &&
     (iVar1 = PKCS7_add_recipient_info(p7,p7i), iVar1 != 0)) {
    return p7i;
  }
  PKCS7_RECIP_INFO_free(p7i);
  return (PKCS7_RECIP_INFO *)0x0;
}


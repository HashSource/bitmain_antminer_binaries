
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_SIGN_ENVELOPE * PKCS7_SIGN_ENVELOPE_new(void)

{
  PKCS7_SIGN_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_SIGN_ENVELOPE *)ASN1_item_new(DAT_000cf0f0);
  return pPVar1;
}


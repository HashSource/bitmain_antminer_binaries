
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ENVELOPE * PKCS7_ENVELOPE_new(void)

{
  PKCS7_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_ENVELOPE *)ASN1_item_new(DAT_000cf060);
  return pPVar1;
}


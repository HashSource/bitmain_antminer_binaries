
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ISSUER_AND_SERIAL * PKCS7_ISSUER_AND_SERIAL_new(void)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  
  pPVar1 = (PKCS7_ISSUER_AND_SERIAL *)ASN1_item_new(DAT_000cf030);
  return pPVar1;
}


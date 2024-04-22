
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ENCRYPT * PKCS7_ENCRYPT_new(void)

{
  PKCS7_ENCRYPT *pPVar1;
  
  pPVar1 = (PKCS7_ENCRYPT *)ASN1_item_new(DAT_000cf120);
  return pPVar1;
}


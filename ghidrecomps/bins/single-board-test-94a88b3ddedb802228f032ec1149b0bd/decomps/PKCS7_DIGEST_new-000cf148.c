
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_DIGEST * PKCS7_DIGEST_new(void)

{
  PKCS7_DIGEST *pPVar1;
  
  pPVar1 = (PKCS7_DIGEST *)ASN1_item_new(DAT_000cf150);
  return pPVar1;
}


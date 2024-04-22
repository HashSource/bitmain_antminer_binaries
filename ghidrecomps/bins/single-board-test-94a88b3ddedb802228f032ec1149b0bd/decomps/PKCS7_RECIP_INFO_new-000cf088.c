
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_RECIP_INFO * PKCS7_RECIP_INFO_new(void)

{
  PKCS7_RECIP_INFO *pPVar1;
  
  pPVar1 = (PKCS7_RECIP_INFO *)ASN1_item_new(DAT_000cf090);
  return pPVar1;
}


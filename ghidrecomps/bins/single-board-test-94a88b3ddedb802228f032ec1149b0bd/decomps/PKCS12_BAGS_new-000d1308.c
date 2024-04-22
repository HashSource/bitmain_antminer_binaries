
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_BAGS * PKCS12_BAGS_new(void)

{
  PKCS12_BAGS *pPVar1;
  
  pPVar1 = (PKCS12_BAGS *)ASN1_item_new(DAT_000d1310);
  return pPVar1;
}


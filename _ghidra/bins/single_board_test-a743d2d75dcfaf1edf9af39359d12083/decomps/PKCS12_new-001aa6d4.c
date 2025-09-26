
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12 * PKCS12_new(void)

{
  PKCS12 *pPVar1;
  
  pPVar1 = (PKCS12 *)ASN1_item_new((ASN1_ITEM *)&PKCS12_it);
  return pPVar1;
}


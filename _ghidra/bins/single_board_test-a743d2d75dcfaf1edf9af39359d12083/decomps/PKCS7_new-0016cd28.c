
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7 * PKCS7_new(void)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)ASN1_item_new((ASN1_ITEM *)&PKCS7_it);
  return pPVar1;
}


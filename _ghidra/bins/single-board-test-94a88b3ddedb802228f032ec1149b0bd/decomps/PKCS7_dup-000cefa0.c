
PKCS7 * PKCS7_dup(PKCS7 *p7)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)ASN1_item_dup((ASN1_ITEM *)&PKCS7_it,p7);
  return pPVar1;
}


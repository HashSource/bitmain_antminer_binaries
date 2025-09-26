
PKCS7 * d2i_PKCS7_fp(FILE *fp,PKCS7 **p7)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)ASN1_item_d2i_fp((ASN1_ITEM *)&PKCS7_it,fp,p7);
  return pPVar1;
}


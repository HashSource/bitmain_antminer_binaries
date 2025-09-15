
PKCS7 * d2i_PKCS7_bio(BIO *bp,PKCS7 **p7)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)ASN1_item_d2i_bio((ASN1_ITEM *)&PKCS7_it,bp,p7);
  return pPVar1;
}


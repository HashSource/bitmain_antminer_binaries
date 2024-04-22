
PKCS12 * d2i_PKCS12_bio(BIO *bp,PKCS12 **p12)

{
  PKCS12 *pPVar1;
  
  pPVar1 = (PKCS12 *)ASN1_item_d2i_bio((ASN1_ITEM *)&PKCS12_it,bp,p12);
  return pPVar1;
}



PKCS7 * d2i_PKCS7(PKCS7 **a,uchar **in,long len)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&PKCS7_it);
  return pPVar1;
}


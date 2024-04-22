
PKCS12 * d2i_PKCS12(PKCS12 **a,uchar **in,long len)

{
  PKCS12 *pPVar1;
  
  pPVar1 = (PKCS12 *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)&PKCS12_it);
  return pPVar1;
}


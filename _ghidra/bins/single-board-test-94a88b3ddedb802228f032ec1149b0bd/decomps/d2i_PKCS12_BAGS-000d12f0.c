
PKCS12_BAGS * d2i_PKCS12_BAGS(PKCS12_BAGS **a,uchar **in,long len)

{
  PKCS12_BAGS *pPVar1;
  
  pPVar1 = (PKCS12_BAGS *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PKCS12_BAGS_it);
  return pPVar1;
}



PKCS7_ENCRYPT * d2i_PKCS7_ENCRYPT(PKCS7_ENCRYPT **a,uchar **in,long len)

{
  PKCS7_ENCRYPT *pPVar1;
  
  pPVar1 = (PKCS7_ENCRYPT *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PKCS7_ENCRYPT_it);
  return pPVar1;
}


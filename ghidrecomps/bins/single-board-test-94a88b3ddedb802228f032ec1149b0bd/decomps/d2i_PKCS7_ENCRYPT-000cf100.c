
PKCS7_ENCRYPT * d2i_PKCS7_ENCRYPT(PKCS7_ENCRYPT **a,uchar **in,long len)

{
  PKCS7_ENCRYPT *pPVar1;
  
  pPVar1 = (PKCS7_ENCRYPT *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cf108);
  return pPVar1;
}


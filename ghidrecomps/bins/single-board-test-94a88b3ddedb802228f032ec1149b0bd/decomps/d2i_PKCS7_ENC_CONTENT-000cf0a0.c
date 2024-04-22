
PKCS7_ENC_CONTENT * d2i_PKCS7_ENC_CONTENT(PKCS7_ENC_CONTENT **a,uchar **in,long len)

{
  PKCS7_ENC_CONTENT *pPVar1;
  
  pPVar1 = (PKCS7_ENC_CONTENT *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cf0a8);
  return pPVar1;
}


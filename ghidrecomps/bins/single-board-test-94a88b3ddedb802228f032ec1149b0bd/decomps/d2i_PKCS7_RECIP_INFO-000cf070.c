
PKCS7_RECIP_INFO * d2i_PKCS7_RECIP_INFO(PKCS7_RECIP_INFO **a,uchar **in,long len)

{
  PKCS7_RECIP_INFO *pPVar1;
  
  pPVar1 = (PKCS7_RECIP_INFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cf078);
  return pPVar1;
}


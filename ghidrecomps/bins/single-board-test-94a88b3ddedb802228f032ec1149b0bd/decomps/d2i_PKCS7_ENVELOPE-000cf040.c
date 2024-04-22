
PKCS7_ENVELOPE * d2i_PKCS7_ENVELOPE(PKCS7_ENVELOPE **a,uchar **in,long len)

{
  PKCS7_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_ENVELOPE *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cf048);
  return pPVar1;
}


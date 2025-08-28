
PKCS7_SIGN_ENVELOPE * d2i_PKCS7_SIGN_ENVELOPE(PKCS7_SIGN_ENVELOPE **a,uchar **in,long len)

{
  PKCS7_SIGN_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_SIGN_ENVELOPE *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PKCS7_SIGN_ENVELOPE_it);
  return pPVar1;
}


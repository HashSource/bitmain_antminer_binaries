
PKCS7_SIGNER_INFO * d2i_PKCS7_SIGNER_INFO(PKCS7_SIGNER_INFO **a,uchar **in,long len)

{
  PKCS7_SIGNER_INFO *pPVar1;
  
  pPVar1 = (PKCS7_SIGNER_INFO *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,DAT_000cefe8);
  return pPVar1;
}


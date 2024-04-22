
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ENC_CONTENT * PKCS7_ENC_CONTENT_new(void)

{
  PKCS7_ENC_CONTENT *pPVar1;
  
  pPVar1 = (PKCS7_ENC_CONTENT *)ASN1_item_new(DAT_000cf0c0);
  return pPVar1;
}


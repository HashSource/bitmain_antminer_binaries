
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_SIGNER_INFO * PKCS7_SIGNER_INFO_new(void)

{
  PKCS7_SIGNER_INFO *pPVar1;
  
  pPVar1 = (PKCS7_SIGNER_INFO *)ASN1_item_new(DAT_000cf000);
  return pPVar1;
}


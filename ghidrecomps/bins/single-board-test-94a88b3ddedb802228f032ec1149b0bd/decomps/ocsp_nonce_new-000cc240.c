
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_OCTET_STRING * ocsp_nonce_new(void)

{
  ASN1_OCTET_STRING *pAVar1;
  
  pAVar1 = (ASN1_OCTET_STRING *)ASN1_item_new(DAT_000bbba8);
  return pAVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PROXY_CERT_INFO_EXTENSION * PROXY_CERT_INFO_EXTENSION_new(void)

{
  PROXY_CERT_INFO_EXTENSION *pPVar1;
  
  pPVar1 = (PROXY_CERT_INFO_EXTENSION *)ASN1_item_new((ASN1_ITEM *)PROXY_CERT_INFO_EXTENSION_it);
  return pPVar1;
}


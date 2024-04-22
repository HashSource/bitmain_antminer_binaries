
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_MAC_DATA * PKCS12_MAC_DATA_new(void)

{
  PKCS12_MAC_DATA *pPVar1;
  
  pPVar1 = (PKCS12_MAC_DATA *)ASN1_item_new(DAT_000d12e0);
  return pPVar1;
}


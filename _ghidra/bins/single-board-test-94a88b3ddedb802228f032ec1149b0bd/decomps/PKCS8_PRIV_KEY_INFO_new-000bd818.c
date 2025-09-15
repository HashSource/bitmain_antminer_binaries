
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS8_PRIV_KEY_INFO * PKCS8_PRIV_KEY_INFO_new(void)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)ASN1_item_new((ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it);
  return pPVar1;
}


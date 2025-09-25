
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKEY_USAGE_PERIOD * PKEY_USAGE_PERIOD_new(void)

{
  PKEY_USAGE_PERIOD *pPVar1;
  
  pPVar1 = (PKEY_USAGE_PERIOD *)ASN1_item_new((ASN1_ITEM *)&PKEY_USAGE_PERIOD_it);
  return pPVar1;
}


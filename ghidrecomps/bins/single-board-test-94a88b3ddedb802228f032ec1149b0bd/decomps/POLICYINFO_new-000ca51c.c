
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICYINFO * POLICYINFO_new(void)

{
  POLICYINFO *pPVar1;
  
  pPVar1 = (POLICYINFO *)ASN1_item_new((ASN1_ITEM *)&POLICYINFO_it);
  return pPVar1;
}


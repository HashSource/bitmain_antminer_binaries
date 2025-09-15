
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICYQUALINFO * POLICYQUALINFO_new(void)

{
  POLICYQUALINFO *pPVar1;
  
  pPVar1 = (POLICYQUALINFO *)ASN1_item_new((ASN1_ITEM *)POLICYQUALINFO_it);
  return pPVar1;
}


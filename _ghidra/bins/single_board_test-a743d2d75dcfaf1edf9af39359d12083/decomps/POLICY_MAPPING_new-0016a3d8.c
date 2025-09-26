
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICY_MAPPING * POLICY_MAPPING_new(void)

{
  POLICY_MAPPING *pPVar1;
  
  pPVar1 = (POLICY_MAPPING *)ASN1_item_new((ASN1_ITEM *)&POLICY_MAPPING_it);
  return pPVar1;
}


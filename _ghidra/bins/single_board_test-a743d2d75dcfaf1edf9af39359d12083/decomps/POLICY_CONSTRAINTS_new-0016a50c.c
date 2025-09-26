
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICY_CONSTRAINTS * POLICY_CONSTRAINTS_new(void)

{
  POLICY_CONSTRAINTS *pPVar1;
  
  pPVar1 = (POLICY_CONSTRAINTS *)ASN1_item_new((ASN1_ITEM *)&POLICY_CONSTRAINTS_it);
  return pPVar1;
}


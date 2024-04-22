
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICYQUALINFO * POLICYQUALINFO_new(void)

{
  POLICYQUALINFO *pPVar1;
  
  pPVar1 = (POLICYQUALINFO *)ASN1_item_new(DAT_000ca548);
  return pPVar1;
}


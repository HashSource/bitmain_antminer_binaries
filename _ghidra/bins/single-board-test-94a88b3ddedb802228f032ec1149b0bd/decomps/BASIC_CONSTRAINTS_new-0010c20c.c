
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BASIC_CONSTRAINTS * BASIC_CONSTRAINTS_new(void)

{
  BASIC_CONSTRAINTS *pBVar1;
  
  pBVar1 = (BASIC_CONSTRAINTS *)ASN1_item_new((ASN1_ITEM *)&BASIC_CONSTRAINTS_it);
  return pBVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NAME_CONSTRAINTS * NAME_CONSTRAINTS_new(void)

{
  NAME_CONSTRAINTS *pNVar1;
  
  pNVar1 = (NAME_CONSTRAINTS *)ASN1_item_new((ASN1_ITEM *)&NAME_CONSTRAINTS_it);
  return pNVar1;
}


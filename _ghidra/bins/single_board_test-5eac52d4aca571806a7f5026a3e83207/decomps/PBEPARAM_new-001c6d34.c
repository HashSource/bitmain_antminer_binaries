
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PBEPARAM * PBEPARAM_new(void)

{
  PBEPARAM *pPVar1;
  
  pPVar1 = (PBEPARAM *)ASN1_item_new((ASN1_ITEM *)&PBEPARAM_it);
  return pPVar1;
}


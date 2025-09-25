
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OTHERNAME * OTHERNAME_new(void)

{
  OTHERNAME *pOVar1;
  
  pOVar1 = (OTHERNAME *)ASN1_item_new((ASN1_ITEM *)OTHERNAME_it);
  return pOVar1;
}


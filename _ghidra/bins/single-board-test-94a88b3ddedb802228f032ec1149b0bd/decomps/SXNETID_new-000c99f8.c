
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

SXNETID * SXNETID_new(void)

{
  SXNETID *pSVar1;
  
  pSVar1 = (SXNETID *)ASN1_item_new((ASN1_ITEM *)&SXNETID_it);
  return pSVar1;
}


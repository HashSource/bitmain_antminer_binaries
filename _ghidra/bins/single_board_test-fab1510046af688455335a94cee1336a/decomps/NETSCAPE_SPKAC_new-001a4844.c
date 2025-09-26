
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NETSCAPE_SPKAC * NETSCAPE_SPKAC_new(void)

{
  NETSCAPE_SPKAC *pNVar1;
  
  pNVar1 = (NETSCAPE_SPKAC *)ASN1_item_new((ASN1_ITEM *)&NETSCAPE_SPKAC_it);
  return pNVar1;
}


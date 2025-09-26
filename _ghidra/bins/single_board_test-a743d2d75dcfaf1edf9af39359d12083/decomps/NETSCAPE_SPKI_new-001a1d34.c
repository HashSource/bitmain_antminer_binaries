
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NETSCAPE_SPKI * NETSCAPE_SPKI_new(void)

{
  NETSCAPE_SPKI *pNVar1;
  
  pNVar1 = (NETSCAPE_SPKI *)ASN1_item_new((ASN1_ITEM *)NETSCAPE_SPKI_it);
  return pNVar1;
}


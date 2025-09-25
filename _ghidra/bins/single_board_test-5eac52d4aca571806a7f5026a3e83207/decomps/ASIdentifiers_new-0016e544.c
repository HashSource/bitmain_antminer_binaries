
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASIdentifiers * ASIdentifiers_new(void)

{
  ASIdentifiers *pAVar1;
  
  pAVar1 = (ASIdentifiers *)ASN1_item_new((ASN1_ITEM *)&ASIdentifiers_it);
  return pAVar1;
}


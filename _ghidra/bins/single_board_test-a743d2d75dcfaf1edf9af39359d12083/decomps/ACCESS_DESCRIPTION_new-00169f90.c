
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ACCESS_DESCRIPTION * ACCESS_DESCRIPTION_new(void)

{
  ACCESS_DESCRIPTION *pAVar1;
  
  pAVar1 = (ACCESS_DESCRIPTION *)ASN1_item_new((ASN1_ITEM *)&ACCESS_DESCRIPTION_it);
  return pAVar1;
}


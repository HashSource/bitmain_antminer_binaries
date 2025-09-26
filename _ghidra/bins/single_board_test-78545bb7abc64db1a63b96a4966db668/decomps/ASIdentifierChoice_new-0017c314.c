
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASIdentifierChoice * ASIdentifierChoice_new(void)

{
  ASIdentifierChoice *pAVar1;
  
  pAVar1 = (ASIdentifierChoice *)ASN1_item_new((ASN1_ITEM *)ASIdentifierChoice_it);
  return pAVar1;
}


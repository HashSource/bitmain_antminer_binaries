
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASIdOrRange * ASIdOrRange_new(void)

{
  ASIdOrRange *pAVar1;
  
  pAVar1 = (ASIdOrRange *)ASN1_item_new((ASN1_ITEM *)ASIdOrRange_it);
  return pAVar1;
}


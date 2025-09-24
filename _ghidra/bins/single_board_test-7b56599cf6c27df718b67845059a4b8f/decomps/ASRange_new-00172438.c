
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASRange * ASRange_new(void)

{
  ASRange *pAVar1;
  
  pAVar1 = (ASRange *)ASN1_item_new((ASN1_ITEM *)ASRange_it);
  return pAVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_TIME * ASN1_TIME_new(void)

{
  ASN1_TIME *pAVar1;
  
  pAVar1 = (ASN1_TIME *)ASN1_item_new((ASN1_ITEM *)&ASN1_TIME_it);
  return pAVar1;
}


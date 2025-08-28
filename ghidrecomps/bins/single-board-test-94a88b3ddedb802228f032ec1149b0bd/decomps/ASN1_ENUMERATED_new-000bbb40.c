
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_ENUMERATED * ASN1_ENUMERATED_new(void)

{
  ASN1_ENUMERATED *pAVar1;
  
  pAVar1 = (ASN1_ENUMERATED *)ASN1_item_new((ASN1_ITEM *)ASN1_ENUMERATED_it);
  return pAVar1;
}


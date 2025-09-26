
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_INTEGER * ASN1_INTEGER_new(void)

{
  ASN1_INTEGER *pAVar1;
  
  pAVar1 = (ASN1_INTEGER *)ASN1_item_new((ASN1_ITEM *)&ASN1_INTEGER_it);
  return pAVar1;
}


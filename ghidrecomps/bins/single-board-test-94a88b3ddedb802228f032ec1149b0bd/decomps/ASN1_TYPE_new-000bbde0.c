
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_TYPE * ASN1_TYPE_new(void)

{
  ASN1_TYPE *pAVar1;
  
  pAVar1 = (ASN1_TYPE *)ASN1_item_new((ASN1_ITEM *)ASN1_ANY_it);
  return pAVar1;
}


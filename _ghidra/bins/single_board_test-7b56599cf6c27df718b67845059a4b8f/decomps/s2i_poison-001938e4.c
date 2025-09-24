
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_NULL * s2i_poison(void)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_new((ASN1_ITEM *)ASN1_NULL_it);
  return (ASN1_NULL *)pAVar1;
}


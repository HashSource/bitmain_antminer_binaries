
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_BIT_STRING * ASN1_BIT_STRING_new(void)

{
  ASN1_BIT_STRING *pAVar1;
  
  pAVar1 = (ASN1_BIT_STRING *)ASN1_item_new((ASN1_ITEM *)ASN1_BIT_STRING_it);
  return pAVar1;
}


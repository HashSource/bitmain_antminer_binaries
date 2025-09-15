
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_IA5STRING * ASN1_IA5STRING_new(void)

{
  ASN1_IA5STRING *pAVar1;
  
  pAVar1 = (ASN1_IA5STRING *)ASN1_item_new((ASN1_ITEM *)ASN1_IA5STRING_it);
  return pAVar1;
}


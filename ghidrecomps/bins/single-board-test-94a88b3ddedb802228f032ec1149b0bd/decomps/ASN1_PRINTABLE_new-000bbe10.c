
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_STRING * ASN1_PRINTABLE_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)ASN1_item_new((ASN1_ITEM *)ASN1_PRINTABLE_it);
  return pAVar1;
}


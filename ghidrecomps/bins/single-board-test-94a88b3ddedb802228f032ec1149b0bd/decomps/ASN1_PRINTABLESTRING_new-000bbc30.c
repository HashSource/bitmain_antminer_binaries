
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_PRINTABLESTRING * ASN1_PRINTABLESTRING_new(void)

{
  ASN1_PRINTABLESTRING *pAVar1;
  
  pAVar1 = (ASN1_PRINTABLESTRING *)ASN1_item_new((ASN1_ITEM *)ASN1_PRINTABLESTRING_it);
  return pAVar1;
}


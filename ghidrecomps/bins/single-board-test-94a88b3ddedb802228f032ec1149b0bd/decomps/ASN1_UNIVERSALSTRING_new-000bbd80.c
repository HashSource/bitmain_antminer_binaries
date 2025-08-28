
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UNIVERSALSTRING * ASN1_UNIVERSALSTRING_new(void)

{
  ASN1_UNIVERSALSTRING *pAVar1;
  
  pAVar1 = (ASN1_UNIVERSALSTRING *)ASN1_item_new((ASN1_ITEM *)ASN1_UNIVERSALSTRING_it);
  return pAVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_GENERALSTRING * ASN1_GENERALSTRING_new(void)

{
  ASN1_GENERALSTRING *pAVar1;
  
  pAVar1 = (ASN1_GENERALSTRING *)ASN1_item_new((ASN1_ITEM *)ASN1_GENERALSTRING_it);
  return pAVar1;
}


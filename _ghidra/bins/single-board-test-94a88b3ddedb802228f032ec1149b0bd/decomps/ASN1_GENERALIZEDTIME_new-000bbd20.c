
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_GENERALIZEDTIME * ASN1_GENERALIZEDTIME_new(void)

{
  ASN1_GENERALIZEDTIME *pAVar1;
  
  pAVar1 = (ASN1_GENERALIZEDTIME *)ASN1_item_new((ASN1_ITEM *)ASN1_GENERALIZEDTIME_it);
  return pAVar1;
}


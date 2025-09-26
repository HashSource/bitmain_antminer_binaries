
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_T61STRING * ASN1_T61STRING_new(void)

{
  ASN1_T61STRING *pAVar1;
  
  pAVar1 = (ASN1_T61STRING *)ASN1_item_new((ASN1_ITEM *)ASN1_T61STRING_it);
  return pAVar1;
}


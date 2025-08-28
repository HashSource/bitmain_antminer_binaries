
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_STRING * DIRECTORYSTRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)ASN1_item_new((ASN1_ITEM *)DIRECTORYSTRING_it);
  return pAVar1;
}


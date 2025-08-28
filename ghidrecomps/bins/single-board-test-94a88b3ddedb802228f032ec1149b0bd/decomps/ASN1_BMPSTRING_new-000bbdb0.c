
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_BMPSTRING * ASN1_BMPSTRING_new(void)

{
  ASN1_BMPSTRING *pAVar1;
  
  pAVar1 = (ASN1_BMPSTRING *)ASN1_item_new((ASN1_ITEM *)ASN1_BMPSTRING_it);
  return pAVar1;
}


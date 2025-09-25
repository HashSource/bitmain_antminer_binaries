
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_BMPSTRING * ASN1_BMPSTRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x1e);
  return pAVar1;
}


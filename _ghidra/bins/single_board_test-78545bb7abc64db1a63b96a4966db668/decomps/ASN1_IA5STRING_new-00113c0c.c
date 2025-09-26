
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_IA5STRING * ASN1_IA5STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x16);
  return pAVar1;
}


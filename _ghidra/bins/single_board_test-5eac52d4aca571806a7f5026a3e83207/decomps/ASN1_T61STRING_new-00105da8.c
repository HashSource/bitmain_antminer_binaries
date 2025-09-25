
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_T61STRING * ASN1_T61STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x14);
  return pAVar1;
}


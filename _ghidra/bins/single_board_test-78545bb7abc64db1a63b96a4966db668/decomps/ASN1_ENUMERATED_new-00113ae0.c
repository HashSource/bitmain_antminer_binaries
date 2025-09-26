
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_ENUMERATED * ASN1_ENUMERATED_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(10);
  return pAVar1;
}


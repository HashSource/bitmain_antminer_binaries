
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_OCTET_STRING * ASN1_OCTET_STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(4);
  return pAVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UTF8STRING * ASN1_UTF8STRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0xc);
  return pAVar1;
}


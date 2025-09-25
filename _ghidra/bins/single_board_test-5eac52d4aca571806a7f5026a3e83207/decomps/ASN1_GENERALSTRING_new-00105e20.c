
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_GENERALSTRING * ASN1_GENERALSTRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x1b);
  return pAVar1;
}


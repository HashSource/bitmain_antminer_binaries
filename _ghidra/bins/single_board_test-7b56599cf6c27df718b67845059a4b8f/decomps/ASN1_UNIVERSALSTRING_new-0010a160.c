
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UNIVERSALSTRING * ASN1_UNIVERSALSTRING_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x1c);
  return pAVar1;
}


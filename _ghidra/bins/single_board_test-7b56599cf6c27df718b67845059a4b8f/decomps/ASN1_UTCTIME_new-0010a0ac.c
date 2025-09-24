
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UTCTIME * ASN1_UTCTIME_new(void)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_STRING_type_new(0x17);
  return pAVar1;
}


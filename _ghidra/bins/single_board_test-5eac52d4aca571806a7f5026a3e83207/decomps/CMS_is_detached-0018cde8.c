
int CMS_is_detached(CMS_ContentInfo *cms)

{
  ASN1_OCTET_STRING **ppAVar1;
  
  ppAVar1 = CMS_get0_content(cms);
  if (ppAVar1 != (ASN1_OCTET_STRING **)0x0) {
    return (uint)(*ppAVar1 == (ASN1_OCTET_STRING *)0x0);
  }
  return -1;
}


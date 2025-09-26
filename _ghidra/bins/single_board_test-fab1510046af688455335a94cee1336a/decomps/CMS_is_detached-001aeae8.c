
int CMS_is_detached(CMS_ContentInfo *cms)

{
  ASN1_OCTET_STRING **ppAVar1;
  int iVar2;
  
  ppAVar1 = CMS_get0_content(cms);
  if (ppAVar1 != (ASN1_OCTET_STRING **)0x0) {
    iVar2 = 1 - (int)*ppAVar1;
    if ((ASN1_OCTET_STRING *)0x1 < *ppAVar1) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return -1;
}


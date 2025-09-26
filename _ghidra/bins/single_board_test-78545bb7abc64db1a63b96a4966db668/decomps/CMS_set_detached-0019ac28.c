
int CMS_set_detached(CMS_ContentInfo *cms,int detached)

{
  ASN1_OCTET_STRING **ppAVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  ppAVar1 = CMS_get0_content(cms);
  if (ppAVar1 == (ASN1_OCTET_STRING **)0x0) {
    return 0;
  }
  if (detached == 0) {
    pAVar2 = *ppAVar1;
    if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
      pAVar2 = ASN1_OCTET_STRING_new();
      *ppAVar1 = pAVar2;
      if (pAVar2 == (ASN1_OCTET_STRING *)0x0) {
        ERR_put_error(0x2e,0x93,0x41,"crypto/cms/cms_lib.c",0x119);
        return 0;
      }
    }
    pAVar2->flags = pAVar2->flags | 0x20;
    return 1;
  }
  ASN1_OCTET_STRING_free(*ppAVar1);
  *ppAVar1 = (ASN1_OCTET_STRING *)0x0;
  return 1;
}


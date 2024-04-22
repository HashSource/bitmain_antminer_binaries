
int CMS_set_detached(CMS_ContentInfo *cms,int detached)

{
  ASN1_OCTET_STRING **ppAVar1;
  ASN1_OCTET_STRING **ppAVar2;
  ASN1_OCTET_STRING *pAVar3;
  
  ppAVar1 = CMS_get0_content(cms);
  ppAVar2 = ppAVar1;
  if (ppAVar1 != (ASN1_OCTET_STRING **)0x0) {
    if (detached == 0) {
      pAVar3 = *ppAVar1;
      if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
        pAVar3 = ASN1_OCTET_STRING_new();
        *ppAVar1 = pAVar3;
        if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
          ERR_put_error(0x2e,0x93,0x41,DAT_0010f948,0x14c);
          return 0;
        }
      }
      ppAVar2 = (ASN1_OCTET_STRING **)0x1;
      pAVar3->flags = pAVar3->flags | 0x20;
    }
    else if (*ppAVar1 == (ASN1_OCTET_STRING *)0x0) {
      ppAVar2 = (ASN1_OCTET_STRING **)0x1;
    }
    else {
      ASN1_OCTET_STRING_free(*ppAVar1);
      ppAVar2 = (ASN1_OCTET_STRING **)0x1;
      *ppAVar1 = (ASN1_OCTET_STRING *)0x0;
    }
  }
  return (int)ppAVar2;
}


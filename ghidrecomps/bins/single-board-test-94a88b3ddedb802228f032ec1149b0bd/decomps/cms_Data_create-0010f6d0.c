
ASN1_OBJECT ** cms_Data_create(void)

{
  ASN1_OBJECT **cms;
  ASN1_OBJECT *pAVar1;
  ASN1_OCTET_STRING **ppAVar2;
  ASN1_OCTET_STRING *pAVar3;
  
  cms = (ASN1_OBJECT **)ASN1_item_new(DAT_0010f720);
  if (cms != (ASN1_OBJECT **)0x0) {
    pAVar1 = OBJ_nid2obj(0x15);
    *cms = pAVar1;
    ppAVar2 = CMS_get0_content((CMS_ContentInfo *)cms);
    if (ppAVar2 != (ASN1_OCTET_STRING **)0x0) {
      pAVar3 = *ppAVar2;
      if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
        pAVar3 = ASN1_OCTET_STRING_new();
        *ppAVar2 = pAVar3;
        if (pAVar3 == (ASN1_OCTET_STRING *)0x0) {
          ERR_put_error(0x2e,0x93,0x41,DAT_0010f724,0x14c);
          return cms;
        }
      }
      pAVar3->flags = pAVar3->flags | 0x20;
    }
  }
  return cms;
}


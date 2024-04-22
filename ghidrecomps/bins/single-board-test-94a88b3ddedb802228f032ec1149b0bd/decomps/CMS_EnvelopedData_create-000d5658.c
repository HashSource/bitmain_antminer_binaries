
CMS_ContentInfo * CMS_EnvelopedData_create(EVP_CIPHER *cipher)

{
  ASN1_OBJECT **a;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_OBJECT **ppAVar4;
  
  a = (ASN1_OBJECT **)CMS_ContentInfo_new();
  if (a == (ASN1_OBJECT **)0x0) goto LAB_000d56a6;
  if (a[1] == (ASN1_OBJECT *)0x0) {
    pAVar2 = (ASN1_OBJECT *)ASN1_item_new(DAT_000d56fc);
    a[1] = pAVar2;
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      ppAVar4 = (ASN1_OBJECT **)pAVar2->length;
      pAVar2->sn = (char *)0x0;
      pAVar2 = OBJ_nid2obj(0x15);
      *ppAVar4 = pAVar2;
      ASN1_OBJECT_free(*a);
      pAVar2 = OBJ_nid2obj(0x17);
      pAVar3 = a[1];
      *a = pAVar2;
      goto LAB_000d567a;
    }
    ERR_put_error(0x2e,0x7e,0x41,DAT_000d56f8,0x5a);
  }
  else {
    iVar1 = OBJ_obj2nid(*a);
    if (iVar1 == 0x17) {
      pAVar3 = a[1];
LAB_000d567a:
      if ((pAVar3 != (ASN1_OBJECT *)0x0) &&
         (iVar1 = cms_EncryptedContent_init(pAVar3->length,cipher,0,0), iVar1 != 0)) {
        return (CMS_ContentInfo *)a;
      }
    }
    else {
      ERR_put_error(0x2e,0x83,0x6b,DAT_000d56f8,0x4f);
    }
  }
  CMS_ContentInfo_free((CMS_ContentInfo *)a);
LAB_000d56a6:
  ERR_put_error(0x2e,0x7c,0x41,DAT_000d56f8,0xad);
  return (CMS_ContentInfo *)0x0;
}


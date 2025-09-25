
CMS_ContentInfo * CMS_EnvelopedData_create(EVP_CIPHER *cipher)

{
  CMS_ContentInfo *a;
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_OBJECT *pAVar3;
  undefined4 *puVar4;
  
  a = CMS_ContentInfo_new();
  if (a != (CMS_ContentInfo *)0x0) {
    if (*(int *)(a + 4) == 0) {
      pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_EnvelopedData_it);
      *(ASN1_VALUE **)(a + 4) = pAVar2;
      if (pAVar2 == (ASN1_VALUE *)0x0) {
        ERR_put_error(0x2e,0x7e,0x41,"crypto/cms/cms_env.c",0x26);
        goto LAB_0018b55c;
      }
      puVar4 = *(undefined4 **)(pAVar2 + 0xc);
      *(undefined4 *)pAVar2 = 0;
      pAVar3 = OBJ_nid2obj(0x15);
      *puVar4 = pAVar3;
      ASN1_OBJECT_free(*(ASN1_OBJECT **)a);
      pAVar3 = OBJ_nid2obj(0x17);
      iVar1 = *(int *)(a + 4);
      *(ASN1_OBJECT **)a = pAVar3;
    }
    else {
      iVar1 = cms_get0_enveloped();
    }
    if ((iVar1 != 0) &&
       (iVar1 = cms_EncryptedContent_init(*(undefined4 *)(iVar1 + 0xc),cipher,0), iVar1 != 0)) {
      return a;
    }
  }
LAB_0018b55c:
  CMS_ContentInfo_free(a);
  ERR_put_error(0x2e,0x7c,0x41,"crypto/cms/cms_env.c",0x78);
  return (CMS_ContentInfo *)0x0;
}


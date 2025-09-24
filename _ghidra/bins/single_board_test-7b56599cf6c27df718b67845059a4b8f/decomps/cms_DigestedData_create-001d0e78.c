
CMS_ContentInfo * cms_DigestedData_create(EVP_MD *param_1)

{
  CMS_ContentInfo *a;
  ASN1_VALUE *pAVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 *puVar3;
  
  a = CMS_ContentInfo_new();
  if (a == (CMS_ContentInfo *)0x0) {
    return (CMS_ContentInfo *)0x0;
  }
  pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_DigestedData_it);
  if (pAVar1 != (ASN1_VALUE *)0x0) {
    pAVar2 = OBJ_nid2obj(0x19);
    *(ASN1_VALUE **)(a + 4) = pAVar1;
    puVar3 = *(undefined4 **)(pAVar1 + 8);
    *(ASN1_OBJECT **)a = pAVar2;
    *(undefined4 *)pAVar1 = 0;
    pAVar2 = OBJ_nid2obj(0x15);
    *puVar3 = pAVar2;
    X509_ALGOR_set_md(*(X509_ALGOR **)(pAVar1 + 4),param_1);
    return a;
  }
  CMS_ContentInfo_free(a);
  return (CMS_ContentInfo *)0x0;
}


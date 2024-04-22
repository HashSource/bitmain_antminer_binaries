
ASN1_OBJECT ** cms_DigestedData_create(undefined4 param_1)

{
  ASN1_OBJECT **a;
  ASN1_OBJECT *pAVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **ppAVar3;
  
  a = (ASN1_OBJECT **)CMS_ContentInfo_new();
  if (a != (ASN1_OBJECT **)0x0) {
    pAVar1 = (ASN1_OBJECT *)ASN1_item_new(DAT_00111624);
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      CMS_ContentInfo_free((CMS_ContentInfo *)a);
      return (ASN1_OBJECT **)0x0;
    }
    pAVar2 = OBJ_nid2obj(0x19);
    a[1] = pAVar1;
    ppAVar3 = (ASN1_OBJECT **)pAVar1->nid;
    *a = pAVar2;
    pAVar1->sn = (char *)0x0;
    pAVar2 = OBJ_nid2obj(0x15);
    *ppAVar3 = pAVar2;
    cms_DigestAlgorithm_set(pAVar1->ln,param_1);
  }
  return a;
}


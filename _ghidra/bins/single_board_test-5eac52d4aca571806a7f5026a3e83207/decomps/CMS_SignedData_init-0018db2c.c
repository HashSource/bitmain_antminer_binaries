
int CMS_SignedData_init(CMS_ContentInfo *cms)

{
  int iVar1;
  ASN1_VALUE *pAVar2;
  ASN1_OBJECT *pAVar3;
  undefined4 *puVar4;
  
  if (*(int *)(cms + 4) == 0) {
    pAVar2 = ASN1_item_new((ASN1_ITEM *)CMS_SignedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar2;
    if (pAVar2 != (ASN1_VALUE *)0x0) {
      puVar4 = *(undefined4 **)(pAVar2 + 8);
      *(undefined4 *)pAVar2 = 1;
      pAVar3 = OBJ_nid2obj(0x15);
      *puVar4 = pAVar3;
      pAVar3 = *(ASN1_OBJECT **)cms;
      *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
      ASN1_OBJECT_free(pAVar3);
      pAVar3 = OBJ_nid2obj(0x16);
      iVar1 = *(int *)(cms + 4);
      *(ASN1_OBJECT **)cms = pAVar3;
      goto LAB_0018db48;
    }
    ERR_put_error(0x2e,0x95,0x41,"crypto/cms/cms_sd.c",0x25);
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar1 == 0x16) {
      iVar1 = *(int *)(cms + 4);
LAB_0018db48:
      if (iVar1 == 0) {
        return 0;
      }
      return 1;
    }
    ERR_put_error(0x2e,0x85,0x6c,"crypto/cms/cms_sd.c",0x1a);
  }
  return 0;
}


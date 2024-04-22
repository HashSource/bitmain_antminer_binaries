
int CMS_SignedData_init(CMS_ContentInfo *cms)

{
  int iVar1;
  undefined4 *puVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_OBJECT **ppAVar4;
  
  if (*(int *)(cms + 4) == 0) {
    puVar2 = (undefined4 *)ASN1_item_new(DAT_001102d4);
    *(undefined4 **)(cms + 4) = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      ERR_put_error(0x2e,0x95,0x41,DAT_001102d0,0x53);
      return 0;
    }
    ppAVar4 = (ASN1_OBJECT **)puVar2[2];
    *puVar2 = 1;
    pAVar3 = OBJ_nid2obj(0x15);
    *ppAVar4 = pAVar3;
    pAVar3 = *(ASN1_OBJECT **)cms;
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
    ASN1_OBJECT_free(pAVar3);
    pAVar3 = OBJ_nid2obj(0x16);
    iVar1 = *(int *)(cms + 4);
    *(ASN1_OBJECT **)cms = pAVar3;
  }
  else {
    iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar1 != 0x16) {
      ERR_put_error(0x2e,0x85,0x6c,DAT_001102d0,0x48);
      return 0;
    }
    iVar1 = *(int *)(cms + 4);
  }
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}



int CMS_set1_eContentType(CMS_ContentInfo *cms,ASN1_OBJECT *oid)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OBJECT **ppAVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_0010f8b8:
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_0010f8b8;
      if (iVar1 != 0x17) {
LAB_0010f878:
        ERR_put_error(0x2e,0x82,0x98,DAT_0010f8d0,0x10c);
        return 0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0x14);
        goto LAB_0010f89a;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_0010f878;
        ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 4);
        goto LAB_0010f89a;
      }
    }
    ppAVar3 = *(ASN1_OBJECT ***)(*(int *)(cms + 4) + 0xc);
  }
LAB_0010f89a:
  if (ppAVar3 != (ASN1_OBJECT **)0x0) {
    if (oid == (ASN1_OBJECT *)0x0) {
      return 1;
    }
    pAVar2 = OBJ_dup(oid);
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free(*ppAVar3);
      *ppAVar3 = pAVar2;
      return 1;
    }
  }
  return 0;
}


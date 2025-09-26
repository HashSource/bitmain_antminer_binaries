
int CMS_set1_eContentType(CMS_ContentInfo *cms,ASN1_OBJECT *oid)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 *puVar3;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x19) {
LAB_001aeacc:
    puVar3 = *(undefined4 **)(*(int *)(cms + 4) + 8);
  }
  else {
    if (iVar1 < 0x1a) {
      if (iVar1 == 0x16) goto LAB_001aeacc;
      if (iVar1 != 0x17) {
LAB_001aea8c:
        ERR_put_error(0x2e,0x82,0x98,"cms_lib.c",0x10c);
        return 0;
      }
    }
    else {
      if (iVar1 == 0xcd) {
        puVar3 = *(undefined4 **)(*(int *)(cms + 4) + 0x14);
        goto LAB_001aeaae;
      }
      if (iVar1 != 0x312) {
        if (iVar1 != 0x1a) goto LAB_001aea8c;
        puVar3 = *(undefined4 **)(*(int *)(cms + 4) + 4);
        goto LAB_001aeaae;
      }
    }
    puVar3 = *(undefined4 **)(*(int *)(cms + 4) + 0xc);
  }
LAB_001aeaae:
  if (puVar3 != (undefined4 *)0x0) {
    if (oid == (ASN1_OBJECT *)0x0) {
      return 1;
    }
    pAVar2 = OBJ_dup(oid);
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      ASN1_OBJECT_free((ASN1_OBJECT *)*puVar3);
      *puVar3 = pAVar2;
      return 1;
    }
  }
  return 0;
}


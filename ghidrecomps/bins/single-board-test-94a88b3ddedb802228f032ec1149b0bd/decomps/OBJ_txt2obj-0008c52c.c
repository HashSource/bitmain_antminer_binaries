
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  char *pcVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uchar *ptr;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uchar *local_50;
  uchar *local_4c;
  undefined4 local_48;
  char **local_44;
  char *local_40;
  char *local_3c;
  uint local_38;
  
  if (no_name != 0) goto LAB_0008c596;
  local_40 = s;
  if (added == (_LHASH *)0x0) {
LAB_0008c660:
    pcVar1 = local_40;
    iVar3 = DAT_0008c744;
    iVar9 = 0;
    iVar4 = 0x3b7;
    do {
      iVar8 = iVar9 + iVar4 >> 1;
      iVar7 = *(int *)(sn_objs + iVar8 * 4);
      iVar6 = strcmp(pcVar1,*(char **)(iVar3 + iVar7 * 0x18));
      if ((-1 < iVar6) && (iVar9 = iVar8 + 1, iVar8 = iVar4, iVar6 == 0)) goto LAB_0008c6aa;
      iVar4 = iVar8;
    } while (iVar9 < iVar8);
    if (iVar6 == 0) {
LAB_0008c6aa:
      local_38 = *(uint *)(iVar3 + iVar7 * 0x18 + 8);
      goto LAB_0008c562;
    }
  }
  else {
    local_44 = &local_40;
    local_48 = 1;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) goto LAB_0008c660;
    local_38 = *(uint *)(*(int *)((int)pvVar2 + 4) + 8);
LAB_0008c562:
    if (local_38 != 0) goto LAB_0008c606;
  }
  local_3c = s;
  if (added == (_LHASH *)0x0) {
LAB_0008c6c4:
    pcVar1 = local_3c;
    iVar3 = DAT_0008c744;
    iVar9 = 0;
    iVar4 = 0x3b7;
    do {
      iVar8 = iVar9 + iVar4 >> 1;
      iVar7 = *(int *)(ln_objs + iVar8 * 4);
      iVar6 = strcmp(pcVar1,*(char **)(iVar3 + iVar7 * 0x18 + 4));
      if ((-1 < iVar6) && (iVar9 = iVar8 + 1, iVar8 = iVar4, iVar6 == 0)) goto LAB_0008c710;
      iVar4 = iVar8;
    } while (iVar9 < iVar8);
    if (iVar6 != 0) goto LAB_0008c596;
LAB_0008c710:
    local_38 = *(uint *)(iVar3 + iVar7 * 0x18 + 8);
  }
  else {
    local_44 = &local_40;
    local_48 = 2;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) goto LAB_0008c6c4;
    local_38 = *(uint *)(*(int *)((int)pvVar2 + 4) + 8);
  }
  if (local_38 != 0) {
LAB_0008c606:
    if (local_38 < 0x3be) {
      pAVar5 = (ASN1_OBJECT *)(DAT_0008c744 + local_38 * 0x18);
      if (pAVar5->nid == 0) {
        ERR_put_error(8,0x67,0x65,DAT_0008c740,0x140);
        return (ASN1_OBJECT *)0x0;
      }
      return pAVar5;
    }
    if (added == (_LHASH *)0x0) {
      return (ASN1_OBJECT *)0x0;
    }
    local_44 = &local_40;
    local_48 = 3;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(8,0x67,0x65,DAT_0008c740,0x14e);
      return (ASN1_OBJECT *)0x0;
    }
    return *(ASN1_OBJECT **)((int)pvVar2 + 4);
  }
LAB_0008c596:
  iVar3 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
  if (0 < iVar3) {
    iVar4 = ASN1_object_size(0,iVar3,6);
    ptr = (uchar *)CRYPTO_malloc(iVar4,DAT_0008c740,0x1d6);
    if (ptr != (uchar *)0x0) {
      local_50 = ptr;
      ASN1_put_object(&local_50,0,iVar3,6,0);
      a2d_ASN1_OBJECT(local_50,iVar3,s,-1);
      local_4c = ptr;
      pAVar5 = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,&local_4c,iVar4);
      CRYPTO_free(ptr);
      return pAVar5;
    }
  }
  return (ASN1_OBJECT *)0x0;
}



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
  uchar *local_50;
  uchar *local_4c;
  undefined4 local_48;
  char **local_44;
  char *local_40;
  char *local_3c;
  uint local_38;
  
  if (no_name != 0) goto LAB_001354ae;
  local_40 = s;
  if (added == (_LHASH *)0x0) {
LAB_00135578:
    pcVar1 = local_40;
    iVar4 = 0;
    iVar3 = 0x3b7;
    do {
      iVar8 = iVar4 + iVar3 >> 1;
      iVar7 = *(int *)(sn_objs + iVar8 * 4);
      iVar6 = strcmp(pcVar1,*(char **)(&nid_objs + iVar7 * 0x18));
      if ((-1 < iVar6) && (iVar4 = iVar8 + 1, iVar8 = iVar3, iVar6 == 0)) goto LAB_001355c2;
      iVar3 = iVar8;
    } while (iVar4 < iVar8);
    if (iVar6 == 0) {
LAB_001355c2:
      local_38 = *(uint *)(&DAT_001f7880 + iVar7 * 0x18);
      goto LAB_0013547a;
    }
  }
  else {
    local_44 = &local_40;
    local_48 = 1;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) goto LAB_00135578;
    local_38 = *(uint *)(*(int *)((int)pvVar2 + 4) + 8);
LAB_0013547a:
    if (local_38 != 0) goto LAB_0013551e;
  }
  local_3c = s;
  if (added == (_LHASH *)0x0) {
LAB_001355dc:
    pcVar1 = local_3c;
    iVar4 = 0;
    iVar3 = 0x3b7;
    do {
      iVar8 = iVar4 + iVar3 >> 1;
      iVar7 = *(int *)(ln_objs + iVar8 * 4);
      iVar6 = strcmp(pcVar1,*(char **)(&DAT_001f787c + iVar7 * 0x18));
      if ((-1 < iVar6) && (iVar4 = iVar8 + 1, iVar8 = iVar3, iVar6 == 0)) goto LAB_00135628;
      iVar3 = iVar8;
    } while (iVar4 < iVar8);
    if (iVar6 != 0) goto LAB_001354ae;
LAB_00135628:
    local_38 = *(uint *)(&DAT_001f7880 + iVar7 * 0x18);
  }
  else {
    local_44 = &local_40;
    local_48 = 2;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) goto LAB_001355dc;
    local_38 = *(uint *)(*(int *)((int)pvVar2 + 4) + 8);
  }
  if (local_38 != 0) {
LAB_0013551e:
    if (local_38 < 0x3be) {
      if (*(int *)(&DAT_001f7880 + local_38 * 0x18) == 0) {
        ERR_put_error(8,0x67,0x65,"obj_dat.c",0x140);
        return (ASN1_OBJECT *)0x0;
      }
      return (ASN1_OBJECT *)(&nid_objs + local_38 * 0x18);
    }
    if (added == (_LHASH *)0x0) {
      return (ASN1_OBJECT *)0x0;
    }
    local_44 = &local_40;
    local_48 = 3;
    pvVar2 = lh_retrieve(added,&local_48);
    if (pvVar2 == (void *)0x0) {
      ERR_put_error(8,0x67,0x65,"obj_dat.c",0x14e);
      return (ASN1_OBJECT *)0x0;
    }
    return *(ASN1_OBJECT **)((int)pvVar2 + 4);
  }
LAB_001354ae:
  iVar3 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
  if (0 < iVar3) {
    iVar4 = ASN1_object_size(0,iVar3,6);
    ptr = (uchar *)CRYPTO_malloc(iVar4,"obj_dat.c",0x1d6);
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


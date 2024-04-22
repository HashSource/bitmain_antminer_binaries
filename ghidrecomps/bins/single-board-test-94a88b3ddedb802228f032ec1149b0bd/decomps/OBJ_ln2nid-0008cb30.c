
int OBJ_ln2nid(char *s)

{
  int iVar1;
  char *__s1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_48;
  undefined *puStack_44;
  undefined auStack_40 [4];
  char *local_3c;
  
  local_3c = s;
  if (*(_LHASH **)(DAT_0008cbb4 + 4) != (_LHASH *)0x0) {
    puStack_44 = auStack_40;
    local_48 = 2;
    pvVar2 = lh_retrieve(*(_LHASH **)(DAT_0008cbb4 + 4),&local_48);
    if (pvVar2 != (void *)0x0) {
      return *(int *)(*(int *)((int)pvVar2 + 4) + 8);
    }
  }
  __s1 = local_3c;
  iVar1 = DAT_0008cbbc;
  iVar4 = DAT_0008cbb8;
  iVar7 = 0;
  iVar8 = 0x3b7;
  do {
    while( true ) {
      iVar6 = iVar7 + iVar8 >> 1;
      iVar5 = *(int *)(iVar4 + iVar6 * 4 + -0x34);
      iVar3 = strcmp(__s1,*(char **)(iVar1 + iVar5 * 0x18 + 4));
      if (-1 < iVar3) break;
      iVar8 = iVar6;
      if (iVar6 <= iVar7) goto LAB_0008cba2;
    }
    iVar7 = iVar6 + 1;
    if (iVar3 == 0) goto LAB_0008cba8;
  } while (iVar7 < iVar8);
LAB_0008cba2:
  if (iVar3 == 0) {
LAB_0008cba8:
    iVar4 = *(int *)(iVar1 + iVar5 * 0x18 + 8);
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


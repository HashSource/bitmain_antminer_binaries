
int OBJ_ln2nid(char *s)

{
  char *__s1;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_48;
  undefined1 *puStack_44;
  undefined1 auStack_40 [4];
  char *local_3c;
  
  local_3c = s;
  if (added != (_LHASH *)0x0) {
    puStack_44 = auStack_40;
    local_48 = 2;
    pvVar1 = lh_retrieve(added,&local_48);
    if (pvVar1 != (void *)0x0) {
      return *(int *)(*(int *)((int)pvVar1 + 4) + 8);
    }
  }
  __s1 = local_3c;
  iVar6 = 0;
  iVar3 = 0x3b7;
  do {
    while( true ) {
      iVar5 = iVar6 + iVar3 >> 1;
      iVar4 = *(int *)(ln_objs + iVar5 * 4);
      iVar2 = strcmp(__s1,*(char **)(&DAT_001fc1c4 + iVar4 * 0x18));
      if (-1 < iVar2) break;
      iVar3 = iVar5;
      if (iVar5 <= iVar6) goto LAB_001385fa;
    }
    iVar6 = iVar5 + 1;
    if (iVar2 == 0) goto LAB_00138600;
  } while (iVar6 < iVar3);
LAB_001385fa:
  if (iVar2 == 0) {
LAB_00138600:
    iVar3 = *(int *)(&DAT_001fc1c8 + iVar4 * 0x18);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


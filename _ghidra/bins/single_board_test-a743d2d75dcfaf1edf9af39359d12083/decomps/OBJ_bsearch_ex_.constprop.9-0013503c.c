
undefined1 * OBJ_bsearch_ex__constprop_9(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t __n;
  undefined1 *puVar5;
  int iVar6;
  
  iVar6 = *param_1;
  __n = *(size_t *)(iVar6 + 0xc);
  if (__n == 0) {
    iVar6 = 0;
    iVar2 = 0x37a;
    do {
      iVar4 = iVar6 + iVar2 >> 1;
      if (*(int *)(&DAT_001f7884 + *(int *)(obj_objs + iVar4 * 4) * 0x18) == 0) {
        return obj_objs + iVar4 * 4;
      }
      if (*(int *)(&DAT_001f7884 + *(int *)(obj_objs + iVar4 * 4) * 0x18) < 1) {
        iVar6 = iVar4 + 1;
        iVar4 = iVar2;
      }
      iVar2 = iVar4;
    } while (iVar6 < iVar4);
    puVar5 = (undefined1 *)0x0;
  }
  else {
    iVar4 = 0;
    iVar2 = 0x37a;
    do {
      while( true ) {
        iVar3 = iVar4 + iVar2 >> 1;
        puVar5 = obj_objs + iVar3 * 4;
        iVar1 = __n - *(int *)(&DAT_001f7884 + *(int *)(obj_objs + iVar3 * 4) * 0x18);
        if (iVar1 == 0) break;
        if (-1 < iVar1) goto LAB_00135068;
LAB_00135090:
        iVar2 = iVar3;
        if (iVar3 <= iVar4) goto LAB_00135096;
      }
      iVar1 = memcmp(*(void **)(iVar6 + 0x10),
                     *(void **)(&DAT_001f7888 + *(int *)(obj_objs + iVar3 * 4) * 0x18),__n);
      if (iVar1 < 0) goto LAB_00135090;
      if (iVar1 == 0) {
        return puVar5;
      }
LAB_00135068:
      iVar4 = iVar3 + 1;
    } while (iVar4 < iVar2);
LAB_00135096:
    if (iVar1 != 0) {
      puVar5 = (undefined1 *)0x0;
    }
  }
  return puVar5;
}



int OBJ_bsearch_ex__constprop_9(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar2 = DAT_0008c1c4;
  iVar6 = DAT_0008c1c0;
  iVar8 = *param_1;
  __n = *(size_t *)(iVar8 + 0xc);
  if (__n == 0) {
    iVar6 = 0;
    iVar2 = 0x37a;
    do {
      iVar8 = iVar6 + iVar2 >> 1;
      iVar7 = *(int *)(DAT_0008c1c4 + *(int *)(DAT_0008c1c0 + iVar8 * 4) * 0x18 + 0xc);
      if (iVar7 == 0) {
        return DAT_0008c1c0 + iVar8 * 4;
      }
      if (iVar7 < 1) {
        iVar6 = iVar8 + 1;
        iVar8 = iVar2;
      }
      iVar2 = iVar8;
    } while (iVar6 < iVar8);
    iVar7 = 0;
  }
  else {
    iVar5 = 0;
    iVar9 = 0x37a;
    do {
      while( true ) {
        iVar4 = iVar5 + iVar9 >> 1;
        iVar7 = iVar6 + iVar4 * 4;
        iVar3 = iVar2 + *(int *)(iVar6 + iVar4 * 4) * 0x18;
        iVar1 = __n - *(int *)(iVar3 + 0xc);
        if (iVar1 == 0) break;
        if (-1 < iVar1) goto LAB_0008c150;
LAB_0008c178:
        iVar9 = iVar4;
        if (iVar4 <= iVar5) goto LAB_0008c17e;
      }
      iVar1 = memcmp(*(void **)(iVar8 + 0x10),*(void **)(iVar3 + 0x10),__n);
      if (iVar1 < 0) goto LAB_0008c178;
      if (iVar1 == 0) {
        return iVar7;
      }
LAB_0008c150:
      iVar5 = iVar4 + 1;
    } while (iVar5 < iVar9);
LAB_0008c17e:
    if (iVar1 != 0) {
      iVar7 = 0;
    }
  }
  return iVar7;
}


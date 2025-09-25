
int bn_lshift_fixed_top(undefined4 *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  void *__s;
  size_t __n;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char in_CY;
  
  uVar5 = param_3 + 0x3f & (int)param_3 >> 0x20;
  if (in_CY == '\0') {
    uVar5 = param_3;
  }
  iVar11 = (int)uVar5 >> 6;
  iVar1 = bn_wexpand(param_1,param_2[1] + iVar11 + 1);
  if (iVar1 != 0) {
    iVar12 = param_2[1];
    if (iVar12 == 0) {
      __s = (void *)*param_1;
      __n = iVar11 << 2;
      *(undefined4 *)((int)__s + iVar11 * 4) = 0;
    }
    else {
      __s = (void *)*param_1;
      param_3 = param_3 & 0x3f;
      iVar1 = *param_2;
      uVar10 = 0x40 - param_3 & 0x3f;
      __n = iVar11 * 4;
      uVar5 = *(uint *)(iVar1 + (iVar12 + 0x3fffffff) * 4);
      uVar14 = -uVar10 | -uVar10 >> 8;
      iVar13 = iVar12 + -1;
      piVar7 = (int *)((int)__s + __n);
      piVar7[iVar12 + 0x40000000] = uVar5 >> uVar10 & uVar14;
      if (0 < iVar13) {
        if (9 < iVar12) {
          piVar2 = piVar7 + iVar12 + 0x3ffffff0;
          iVar8 = (iVar12 + 0x3fffffff) * 4 + -0x40 + iVar1;
          do {
            uVar3 = *(uint *)(iVar8 + 0x3c);
            HintPreloadData(iVar8);
            iVar13 = iVar13 + -8;
            HintPreloadData(piVar2);
            piVar2[0xf] = uVar3 >> uVar10 & uVar14 | uVar5 << param_3;
            uVar6 = *(uint *)(iVar8 + 0x38);
            piVar2[0xe] = uVar6 >> uVar10 & uVar14 | uVar3 << param_3;
            uVar5 = *(uint *)(iVar8 + 0x34);
            piVar2[0xd] = uVar5 >> uVar10 & uVar14 | uVar6 << param_3;
            uVar3 = *(uint *)(iVar8 + 0x30);
            piVar2[0xc] = uVar3 >> uVar10 & uVar14 | uVar5 << param_3;
            uVar5 = *(uint *)(iVar8 + 0x2c);
            piVar2[0xb] = uVar5 >> uVar10 & uVar14 | uVar3 << param_3;
            uVar6 = *(uint *)(iVar8 + 0x28);
            piVar2[10] = uVar6 >> uVar10 & uVar14 | uVar5 << param_3;
            uVar3 = *(uint *)(iVar8 + 0x24);
            piVar2[9] = uVar3 >> uVar10 & uVar14 | uVar6 << param_3;
            uVar5 = *(uint *)(iVar8 + 0x20);
            piVar2[8] = uVar5 >> uVar10 & uVar14 | uVar3 << param_3;
            piVar2 = piVar2 + -8;
            iVar8 = iVar8 + -0x20;
          } while (iVar13 != (iVar12 + -9) - (iVar12 - 10U & 0xfffffff8));
        }
        puVar4 = (uint *)(iVar1 + iVar13 * 4);
        puVar9 = (uint *)(piVar7 + iVar13);
        do {
          uVar3 = uVar5 << param_3;
          puVar4 = puVar4 + -1;
          uVar5 = *puVar4;
          iVar13 = iVar13 + -1;
          *puVar9 = uVar3 | uVar5 >> uVar10 & uVar14;
          puVar9 = puVar9 + -1;
        } while (iVar13 != 0);
      }
      *piVar7 = uVar5 << param_3;
    }
    if (iVar11 != 0) {
      memset(__s,0,__n);
      iVar12 = param_2[1];
    }
    iVar13 = param_2[3];
    iVar1 = 1;
    param_1[1] = iVar11 + iVar12 + 1;
    param_1[3] = iVar13;
  }
  return iVar1;
}


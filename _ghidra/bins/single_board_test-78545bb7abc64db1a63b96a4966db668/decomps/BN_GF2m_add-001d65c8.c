
undefined4 BN_GF2m_add(int *param_1,int *param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  undefined4 *puVar13;
  
  piVar6 = param_2;
  iVar2 = param_3[1];
  if (param_3[1] <= param_2[1]) {
    piVar6 = param_3;
    iVar2 = param_2[1];
    param_3 = param_2;
  }
  iVar2 = bn_wexpand(param_1,iVar2);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = piVar6[1];
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    iVar8 = *piVar6;
    puVar9 = (uint *)*param_1;
    iVar10 = *param_3;
    if (iVar2 < 9) {
      iVar7 = 0;
    }
    else {
      iVar7 = 0;
      puVar3 = puVar9;
      iVar12 = iVar10 + 0x4c;
      iVar5 = iVar8 + 0x4c;
      do {
        iVar7 = iVar7 + 8;
        HintPreloadData(iVar12);
        HintPreloadData(iVar5);
        *puVar3 = *(uint *)(iVar5 + -0x4c) ^ *(uint *)(iVar12 + -0x4c);
        puVar3[1] = *(uint *)(iVar5 + -0x48) ^ *(uint *)(iVar12 + -0x48);
        puVar3[2] = *(uint *)(iVar5 + -0x44) ^ *(uint *)(iVar12 + -0x44);
        puVar3[3] = *(uint *)(iVar5 + -0x40) ^ *(uint *)(iVar12 + -0x40);
        puVar3[4] = *(uint *)(iVar5 + -0x3c) ^ *(uint *)(iVar12 + -0x3c);
        puVar3[5] = *(uint *)(iVar5 + -0x38) ^ *(uint *)(iVar12 + -0x38);
        puVar3[6] = *(uint *)(iVar5 + -0x34) ^ *(uint *)(iVar12 + -0x34);
        puVar3[7] = *(uint *)(iVar5 + -0x30) ^ *(uint *)(iVar12 + -0x30);
        puVar3 = puVar3 + 8;
        iVar12 = iVar12 + 0x20;
        iVar5 = iVar5 + 0x20;
      } while (iVar7 != (iVar2 - 9U & 0xfffffff8) + 8);
    }
    puVar3 = (uint *)(iVar8 + iVar7 * 4);
    puVar9 = puVar9 + iVar7;
    puVar11 = (uint *)(iVar10 + iVar7 * 4);
    do {
      iVar7 = iVar7 + 1;
      *puVar9 = *puVar3 ^ *puVar11;
      puVar3 = puVar3 + 1;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar7 < iVar2);
  }
  iVar8 = param_3[1];
  if (iVar2 < iVar8) {
    iVar10 = iVar2 + 1;
    iVar12 = *param_3;
    iVar7 = *param_1;
    if (-0x7ffffffa < iVar8 && iVar10 < iVar8 + -7) {
      iVar10 = (iVar2 + 0x19) * 4;
      puVar4 = (undefined4 *)(iVar10 + -100 + iVar7);
      iVar5 = iVar10 + iVar12;
      do {
        iVar10 = iVar2;
        HintPreloadData(iVar5);
        iVar2 = iVar10 + 8;
        *puVar4 = *(undefined4 *)(iVar5 + -100);
        puVar4[1] = *(undefined4 *)(iVar5 + -0x60);
        puVar4[2] = *(undefined4 *)(iVar5 + -0x5c);
        puVar4[3] = *(undefined4 *)(iVar5 + -0x58);
        puVar4[4] = *(undefined4 *)(iVar5 + -0x54);
        puVar4[5] = *(undefined4 *)(iVar5 + -0x50);
        puVar4[6] = *(undefined4 *)(iVar5 + -0x4c);
        puVar4[7] = *(undefined4 *)(iVar5 + -0x48);
        puVar4 = puVar4 + 8;
        iVar5 = iVar5 + 0x20;
      } while (iVar10 + 9 < iVar8 + -7);
      iVar10 = iVar10 + 9;
    }
    puVar4 = (undefined4 *)(iVar12 + iVar2 * 4);
    puVar13 = (undefined4 *)(iVar7 + iVar2 * 4);
    do {
      *puVar13 = *puVar4;
      bVar1 = iVar10 < iVar8;
      puVar4 = puVar4 + 1;
      iVar10 = iVar10 + 1;
      puVar13 = puVar13 + 1;
    } while (bVar1);
  }
  param_1[1] = iVar8;
  bn_correct_top(param_1);
  return 1;
}


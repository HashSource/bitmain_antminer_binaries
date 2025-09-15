
undefined4 bn_cmp_part_words(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  if (param_4 < 0) {
    piVar4 = (int *)(param_2 + (param_3 - param_4) * 4);
    do {
      piVar4 = piVar4 + -1;
      if (*piVar4 != 0) goto LAB_0009d89c;
      param_4 = param_4 + 1;
    } while (param_4 != 0);
    uVar5 = *(uint *)(param_1 + (param_3 + -1) * 4);
    uVar2 = *(uint *)(param_2 + (param_3 + -1) * 4);
    bVar9 = uVar2 <= uVar5;
    bVar8 = uVar5 == uVar2;
  }
  else {
    if (param_4 != 0) {
      piVar4 = (int *)(param_1 + (param_3 + param_4) * 4);
      do {
        piVar4 = piVar4 + -1;
        if (*piVar4 != 0) goto LAB_0009d8a4;
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
    uVar5 = *(uint *)(param_1 + (param_3 + -1) * 4);
    uVar2 = *(uint *)(param_2 + (param_3 + -1) * 4);
    bVar9 = uVar2 <= uVar5;
    bVar8 = uVar5 == uVar2;
  }
  if (bVar8) {
    iVar6 = param_3 + -2;
    if (iVar6 < 0) {
      return 0;
    }
    uVar5 = *(uint *)(param_1 + iVar6 * 4);
    uVar2 = *(uint *)(param_2 + iVar6 * 4);
    if (uVar5 == uVar2) {
      iVar3 = 0;
      do {
        bVar9 = iVar6 == 0;
        iVar6 = iVar6 + -1;
        iVar7 = param_1 + param_3 * 4 + iVar3;
        iVar3 = iVar3 + -4;
        if (bVar9) {
          return 0;
        }
        uVar5 = *(uint *)(iVar7 + -0xc);
        uVar2 = *(uint *)(param_2 + param_3 * 4 + iVar3 + -8);
      } while (uVar5 == uVar2);
    }
    bVar9 = uVar2 <= uVar5;
    bVar8 = uVar5 == uVar2;
  }
  if (bVar9 && !bVar8) {
LAB_0009d8a4:
    uVar1 = 1;
  }
  else {
LAB_0009d89c:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


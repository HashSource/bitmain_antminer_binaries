
uint critical_factorization_part_0(int param_1,uint param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  iVar2 = 1;
  uVar5 = 0;
  uVar7 = 0xffffffff;
  iVar9 = 1;
  while (uVar8 = iVar2 + uVar5, iVar3 = iVar2, uVar4 = uVar5, iVar2 + uVar5 < param_2) {
    while (uVar5 = uVar8, bVar1 = *(byte *)(param_1 + uVar7 + iVar3),
          *(byte *)(param_1 + uVar5) < bVar1) {
      iVar3 = 1;
      iVar9 = uVar5 - uVar7;
      uVar8 = uVar5 + 1;
      uVar4 = uVar5;
      if (param_2 <= uVar5 + 1) goto LAB_00053004;
    }
    if (*(byte *)(param_1 + uVar5) == bVar1) {
      if (iVar3 == iVar9) {
        iVar2 = 1;
        iVar9 = iVar3;
      }
      else {
        iVar2 = iVar3 + 1;
        uVar5 = uVar4;
      }
    }
    else {
      iVar2 = 1;
      uVar5 = uVar4 + 1;
      uVar7 = uVar4;
      iVar9 = 1;
    }
  }
LAB_00053004:
  iVar2 = 1;
  *param_3 = iVar9;
  uVar5 = 0;
  uVar8 = 0xffffffff;
  iVar9 = 1;
  while (uVar4 = iVar2 + uVar5, iVar3 = iVar2, uVar6 = uVar5, iVar2 + uVar5 < param_2) {
    while (uVar5 = uVar4, bVar1 = *(byte *)(param_1 + uVar8 + iVar3),
          bVar1 < *(byte *)(param_1 + uVar5)) {
      iVar3 = 1;
      iVar9 = uVar5 - uVar8;
      uVar4 = uVar5 + 1;
      uVar6 = uVar5;
      if (param_2 <= uVar5 + 1) goto LAB_0005303c;
    }
    if (*(byte *)(param_1 + uVar5) == bVar1) {
      if (iVar3 == iVar9) {
        iVar2 = 1;
        iVar9 = iVar3;
      }
      else {
        iVar2 = iVar3 + 1;
        uVar5 = uVar6;
      }
    }
    else {
      iVar2 = 1;
      uVar5 = uVar6 + 1;
      uVar8 = uVar6;
      iVar9 = 1;
    }
  }
LAB_0005303c:
  uVar5 = uVar7 + 1;
  if (uVar7 + 1 <= uVar8 + 1) {
    *param_3 = iVar9;
    uVar5 = uVar8 + 1;
  }
  return uVar5;
}


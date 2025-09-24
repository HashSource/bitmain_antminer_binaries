
undefined4 bn_cmp_words(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  if (param_3 == 0) {
    return 0;
  }
  uVar7 = *(uint *)(param_1 + (param_3 + 0x3fffffff) * 4);
  uVar5 = *(uint *)(param_2 + (param_3 + 0x3fffffff) * 4);
  if (uVar7 == uVar5) {
    iVar6 = param_3 + -2;
    if (iVar6 < 0) {
LAB_0011028e:
      uVar1 = 0;
    }
    else {
      uVar7 = *(uint *)(param_1 + iVar6 * 4);
      uVar5 = *(uint *)(param_2 + iVar6 * 4);
      if (uVar5 == uVar7) {
        iVar4 = (param_3 + 0x3ffffffe) * 4;
        puVar2 = (uint *)(param_1 + iVar4);
        puVar3 = (uint *)(param_2 + iVar4);
        do {
          bVar8 = iVar6 == 0;
          iVar6 = iVar6 + -1;
          if (bVar8) goto LAB_0011028e;
          puVar2 = puVar2 + -1;
          uVar7 = *puVar2;
          puVar3 = puVar3 + -1;
          uVar5 = *puVar3;
        } while (uVar7 == uVar5);
      }
      if (uVar5 < uVar7) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
  }
  else if (uVar5 < uVar7) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


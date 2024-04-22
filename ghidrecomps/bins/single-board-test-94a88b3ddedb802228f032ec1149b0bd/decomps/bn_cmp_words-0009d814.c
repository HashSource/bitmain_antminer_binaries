
undefined4 bn_cmp_words(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  uVar3 = *(uint *)(param_1 + (param_3 + -1) * 4);
  uVar1 = *(uint *)(param_2 + (param_3 + -1) * 4);
  if (uVar3 == uVar1) {
    iVar4 = param_3 + -2;
    if (iVar4 < 0) {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + iVar4 * 4);
    uVar1 = *(uint *)(param_2 + iVar4 * 4);
    if (uVar3 == uVar1) {
      iVar2 = 0;
      do {
        bVar6 = iVar4 == 0;
        iVar4 = iVar4 + -1;
        iVar5 = param_1 + param_3 * 4 + iVar2;
        iVar2 = iVar2 + -4;
        if (bVar6) {
          return 0;
        }
        uVar3 = *(uint *)(iVar5 + -0xc);
        uVar1 = *(uint *)(param_2 + param_3 * 4 + iVar2 + -8);
      } while (uVar3 == uVar1);
    }
    if (uVar1 < uVar3) {
      return 1;
    }
  }
  else if (uVar1 <= uVar3 && uVar3 != uVar1) {
    return 1;
  }
  return 0xffffffff;
}


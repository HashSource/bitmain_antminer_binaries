
void __work_completed(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_2 + 0x15c);
  *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + -1;
  if (iVar4 == 0) {
    iVar3 = *(int *)(param_2 + 0x160);
    if (iVar3 == 0) {
      free(**(void ***)(*(int *)(param_1 + 0x160) + 0x158));
      free(*(void **)(*(int *)(param_1 + 0x160) + 0x158));
      *(undefined4 *)(param_1 + 0x160) = 0;
      return;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x160) + 0x158);
    if (param_2 == *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0x14)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x14);
    }
    *(int *)(param_1 + 0x160) = iVar3;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x160);
    iVar5 = *(int *)(iVar3 + 0x158);
    iVar1 = *(int *)(iVar5 + 0x14) + iVar4;
    if (param_2 == *(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0x14)) {
      *(int *)(iVar5 + 0x10) = iVar1;
    }
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 0x160);
  }
  piVar2 = *(int **)(iVar3 + 0x158);
  if (*(int *)(param_2 + 0x160) != 0) {
    *(int *)(piVar2[5] + *(int *)(param_2 + 0x160) + 4) = iVar4;
  }
  iVar1 = *piVar2;
  iVar3 = (*(uint *)(param_2 + 0x174) & piVar2[1] - 1U) * 0xc;
  iVar5 = *(int *)(iVar1 + iVar3);
  *(int *)(iVar1 + iVar3 + 4) = *(int *)(iVar1 + iVar3 + 4) + -1;
  iVar4 = *(int *)(param_2 + 0x168);
  if (iVar5 == param_2 + 0x158) {
    *(int *)(iVar1 + iVar3) = iVar4;
  }
  iVar3 = *(int *)(param_2 + 0x164);
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x10) = iVar4;
    iVar4 = *(int *)(param_2 + 0x168);
  }
  if (iVar4 != 0) {
    *(int *)(iVar4 + 0xc) = iVar3;
  }
  piVar2[3] = piVar2[3] + -1;
  return;
}



void freedirs(int param_1)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  
  ppcVar1 = DAT_0005b388;
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 != 0) {
    if (0 < *(int *)(param_1 + 0x40)) {
      iVar5 = 0;
      do {
        (**ppcVar1)(*(undefined4 *)(iVar2 + iVar5 * 4));
        iVar3 = *(int *)(param_1 + 0x40);
        *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar5 * 4) = 0;
        iVar5 = iVar5 + 1;
        iVar2 = *(int *)(param_1 + 0x3c);
      } while (iVar5 < iVar3);
    }
    (**ppcVar1)();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  (**ppcVar1)(*(undefined4 *)(param_1 + 0x48));
  pcVar4 = *ppcVar1;
  *(undefined4 *)(param_1 + 0x48) = 0;
  (*pcVar4)(*(undefined4 *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}


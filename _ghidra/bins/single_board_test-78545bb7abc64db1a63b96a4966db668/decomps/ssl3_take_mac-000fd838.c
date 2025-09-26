
int ssl3_take_mac(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 100);
    uVar1 = *(undefined4 *)(iVar2 + 0x20);
    uVar3 = *(undefined4 *)(iVar2 + 0x24);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 100);
    uVar1 = *(undefined4 *)(iVar2 + 0x18);
    uVar3 = *(undefined4 *)(iVar2 + 0x1c);
  }
  iVar4 = *(int *)(param_1 + 0x7c);
  uVar1 = (**(code **)(iVar2 + 0x14))(param_1,uVar1,uVar3,iVar4 + 0x184);
  iVar2 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar4 + 0x204) = uVar1;
  iVar2 = *(int *)(iVar2 + 0x204);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}


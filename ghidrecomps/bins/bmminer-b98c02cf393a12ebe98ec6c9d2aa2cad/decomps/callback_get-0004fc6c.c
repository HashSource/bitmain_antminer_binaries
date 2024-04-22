
uint callback_get(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x404);
  if (uVar3 < *(uint *)(param_1 + 0x400)) {
    bVar1 = *(byte *)(param_1 + uVar3);
    *(uint *)(param_1 + 0x404) = uVar3 + 1;
    return (uint)bVar1;
  }
  *(undefined4 *)(param_1 + 0x404) = 0;
  iVar2 = (**(code **)(param_1 + 0x408))(param_1,0x400,*(undefined4 *)(param_1 + 0x40c));
  *(int *)(param_1 + 0x400) = iVar2;
  if (iVar2 - 1U < 0xfffffffe) {
    bVar1 = *(byte *)(param_1 + *(int *)(param_1 + 0x404));
    *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + 1;
    return (uint)bVar1;
  }
  return 0xffffffff;
}


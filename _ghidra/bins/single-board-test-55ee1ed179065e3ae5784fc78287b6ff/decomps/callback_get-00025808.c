
uint callback_get(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(uint *)(param_1 + 0x400) <= *(uint *)(param_1 + 0x404)) {
    *(undefined4 *)(param_1 + 0x404) = 0;
    uVar2 = (**(code **)(param_1 + 0x408))(param_1,0x400,*(undefined4 *)(param_1 + 0x40c));
    *(undefined4 *)(param_1 + 0x400) = uVar2;
    if ((*(int *)(param_1 + 0x400) == 0) || (*(int *)(param_1 + 0x400) == -1)) {
      return 0xffffffff;
    }
  }
  bVar1 = *(byte *)(param_1 + *(int *)(param_1 + 0x404));
  *(int *)(param_1 + 0x404) = *(int *)(param_1 + 0x404) + 1;
  return (uint)bVar1;
}


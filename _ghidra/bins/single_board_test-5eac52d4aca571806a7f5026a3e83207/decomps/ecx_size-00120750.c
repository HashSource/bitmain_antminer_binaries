
undefined4 ecx_size(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = **(int **)(param_1 + 0xc);
  if (iVar1 == 0x40a || iVar1 == 0x43f) {
    return 0x20;
  }
  if (iVar1 == 0x40b) {
    uVar2 = 0x38;
  }
  else {
    uVar2 = 0x39;
  }
  return uVar2;
}


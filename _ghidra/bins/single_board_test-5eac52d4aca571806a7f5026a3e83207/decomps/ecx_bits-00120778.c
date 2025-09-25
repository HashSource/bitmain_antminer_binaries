
undefined4 ecx_bits(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = **(int **)(param_1 + 0xc);
  if (iVar1 == 0x43f || iVar1 == 0x40a) {
    return 0xfd;
  }
  if (iVar1 == 0x40b) {
    uVar2 = 0x1c0;
  }
  else {
    uVar2 = 0x1c8;
  }
  return uVar2;
}


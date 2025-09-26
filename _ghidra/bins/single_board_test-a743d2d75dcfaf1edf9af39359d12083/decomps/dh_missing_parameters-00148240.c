
int dh_missing_parameters(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 8) != 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
    iVar2 = 1 - uVar1;
    if (1 < uVar1) {
      iVar2 = 0;
    }
    return iVar2;
  }
  return 1;
}


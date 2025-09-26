
undefined4 aes_xts_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_2 != 8) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(iVar1 + 0x1f0) = 0;
    *(undefined4 *)(iVar1 + 500) = 0;
    return 1;
  }
  iVar2 = *(int *)(param_4 + 0x60);
  if (*(int *)(iVar1 + 0x1f0) != 0) {
    if (*(int *)(iVar1 + 0x1f0) != iVar1) {
      return 0;
    }
    *(int *)(iVar2 + 0x1f0) = iVar2;
  }
  if (*(int *)(iVar1 + 500) != 0) {
    if (*(int *)(iVar1 + 500) != iVar1 + 0xf8) {
      return 0;
    }
    *(int *)(iVar2 + 500) = iVar2 + 0xf8;
    return 1;
  }
  return 1;
}


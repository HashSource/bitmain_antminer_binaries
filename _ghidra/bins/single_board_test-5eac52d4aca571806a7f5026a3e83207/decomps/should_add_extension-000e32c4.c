
undefined4 should_add_extension(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((param_2 & param_3) == 0) {
    return 0;
  }
  iVar1 = extension_is_relevant();
  if (iVar1 == 0) {
    return 0;
  }
  if (((int)(param_2 << 0x1a) < 0) && ((int)(param_3 << 0x18) < 0)) {
    uVar2 = (uint)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) >> 0x1f;
    if (param_4 < 0x304) {
      uVar2 = 1;
    }
    if (uVar2 != 0) {
      return 0;
    }
  }
  return 1;
}


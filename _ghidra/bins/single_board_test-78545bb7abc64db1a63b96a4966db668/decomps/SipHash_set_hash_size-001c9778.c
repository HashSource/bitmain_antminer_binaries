
undefined4 SipHash_set_hash_size(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    param_2 = 0x10;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x2c) = 0x10;
      return 1;
    }
  }
  else {
    if ((param_2 - 8U & 0xfffffff7) != 0) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar1 == 0) {
      iVar1 = 0x10;
    }
  }
  *(int *)(param_1 + 0x2c) = iVar1;
  if (iVar1 == param_2) {
    return 1;
  }
  *(int *)(param_1 + 0x2c) = param_2;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ 0xee;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  return 1;
}


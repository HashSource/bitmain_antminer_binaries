
uint sock_ctrl(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0xd) {
    if (10 < param_2) {
      return 1;
    }
    if (param_2 == 8) {
      return *(uint *)(param_1 + 0x14);
    }
    if (param_2 == 9) {
      *(undefined4 *)(param_1 + 0x14) = param_3;
      return 1;
    }
    if (param_2 == 2) {
      return (uint)(*(int *)(param_1 + 0x18) << 0x14) >> 0x1f;
    }
  }
  else {
    if (param_2 == 0x68) {
      if ((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) {
        if (*(int *)(param_1 + 0x10) != 0) {
          BIO_closesocket(*(undefined4 *)(param_1 + 0x20));
        }
        *(undefined4 *)(param_1 + 0x10) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
      uVar1 = *param_4;
      *(undefined4 *)(param_1 + 0x14) = param_3;
      *(undefined4 *)(param_1 + 0x10) = 1;
      *(undefined4 *)(param_1 + 0x20) = uVar1;
      return 1;
    }
    if (param_2 == 0x69) {
      if (*(int *)(param_1 + 0x10) != 0) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)(param_1 + 0x20);
        }
        return *(uint *)(param_1 + 0x20);
      }
      return 0xffffffff;
    }
  }
  return 0;
}


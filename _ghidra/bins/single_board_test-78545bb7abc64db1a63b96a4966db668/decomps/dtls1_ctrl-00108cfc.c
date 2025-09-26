
int dtls1_ctrl(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0x4a) {
    iVar1 = dtls1_handle_timeout();
    return iVar1;
  }
  if (param_2 < 0x4b) {
    if (param_2 == 0x11) {
      if (param_3 < 0xd0) {
        return 0;
      }
      *(int *)(*(int *)(param_1 + 0x80) + 0x11c) = param_3;
      return param_3;
    }
    if (param_2 == 0x49) {
      iVar1 = dtls1_get_timeout(param_1,param_4);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
  }
  else {
    if (param_2 == 0x78) {
      if (param_3 < 0x100) {
        return 0;
      }
      *(int *)(*(int *)(param_1 + 0x80) + 0x118) = param_3;
      return 1;
    }
    if (param_2 == 0x79) {
      return 0x100;
    }
  }
  iVar1 = ssl3_ctrl(param_1);
  return iVar1;
}


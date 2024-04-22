
int ssl3_shutdown(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((*(int *)(param_1 + 0x2c) != 0) || (*(int *)(param_1 + 0x34) == 0x4000)) {
    *(undefined4 *)(param_1 + 0x30) = 3;
    return 1;
  }
  uVar2 = *(uint *)(param_1 + 0x30);
  if ((uVar2 & 1) == 0) {
    *(uint *)(param_1 + 0x30) = uVar2 | 1;
    ssl3_send_alert(param_1,1);
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) != 0) {
      return -1;
    }
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) == 0) {
      if ((uVar2 & 2) == 0) {
        (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0,0,0,0);
        uVar2 = *(uint *)(param_1 + 0x30);
        if (-1 < (int)(uVar2 << 0x1e)) {
          return -1;
        }
      }
      if (uVar2 != 3) {
        return 0;
      }
      goto LAB_0006a72e;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x3c))();
    if (iVar1 == -1) {
      return -1;
    }
  }
  if (*(int *)(param_1 + 0x30) != 3) {
    return 0;
  }
LAB_0006a72e:
  uVar2 = *(uint *)(*(int *)(param_1 + 0x58) + 0x18c);
  iVar1 = 1 - uVar2;
  if (1 < uVar2) {
    iVar1 = 0;
  }
  return iVar1;
}


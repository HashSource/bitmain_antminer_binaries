
undefined4 dtls1_shutdown(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_14 [4];
  
  if ((*(int *)(param_1 + 0x24) != 0) || (iVar1 = SSL_in_before(), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x28) = 3;
    return 1;
  }
  uVar2 = *(uint *)(param_1 + 0x28);
  if ((int)(uVar2 << 0x1f) < 0) {
    if (*(int *)(*(int *)(param_1 + 0x7c) + 0xe8) == 0) {
      if ((int)(uVar2 << 0x1e) < 0) goto LAB_000e44ca;
      (**(code **)(*(int *)(param_1 + 4) + 0x38))(param_1,0,0,0,0,0,auStack_14);
      iVar1 = *(int *)(param_1 + 0x28);
      if (-1 < iVar1 << 0x1e) {
        return 0xffffffff;
      }
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x40))(param_1);
      if (iVar1 == -1) {
        return 0xffffffff;
      }
      iVar1 = *(int *)(param_1 + 0x28);
    }
    if (iVar1 != 3) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x7c) + 0xe8) != 0) {
      return 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x28) = uVar2 | 1;
    ssl3_send_alert(param_1,1,0);
    if (*(int *)(*(int *)(param_1 + 0x7c) + 0xe8) != 0) {
      return 0xffffffff;
    }
    uVar2 = *(uint *)(param_1 + 0x28);
LAB_000e44ca:
    if (uVar2 != 3) {
      return 0;
    }
  }
  return 1;
}


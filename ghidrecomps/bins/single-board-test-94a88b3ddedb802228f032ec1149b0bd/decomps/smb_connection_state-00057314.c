
int smb_connection_state(int param_1,undefined *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_15;
  int local_14 [2];
  
  local_14[0] = 0;
  if (*(int *)(param_1 + 0x3c0) == 1) {
    if (*(int *)(*(int *)(param_1 + 0x218) + 0x40) << 0x1f < 0) {
      iVar2 = Curl_ssl_connect_nonblocking(param_1,0,&local_15);
      if (iVar2 != 0x51 && iVar2 != 0) {
        return iVar2;
      }
      if (local_15 == 0) {
        return 0;
      }
    }
    iVar2 = smb_send_message(param_1,0x72,DAT_00057410,0xf);
    if (iVar2 != 0) goto LAB_0005736a;
    *(undefined4 *)(param_1 + 0x3c0) = 2;
  }
  iVar2 = smb_send_and_recv(param_1,local_14);
  if (iVar2 != 0x51 && iVar2 != 0) {
LAB_0005736a:
    *(undefined *)(param_1 + 0x1ed) = 1;
    return iVar2;
  }
  if (local_14[0] == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x3c0) == 2) {
    if (*(int *)(local_14[0] + 9) != 0) {
      *(undefined *)(param_1 + 0x1ed) = 1;
      return 7;
    }
    uVar3 = *(undefined4 *)(local_14[0] + 0x4d);
    *(undefined4 *)(param_1 + 0x3cc) = *(undefined4 *)(local_14[0] + 0x49);
    *(undefined4 *)(param_1 + 0x3d0) = uVar3;
    *(undefined4 *)(param_1 + 0x3d4) = *(undefined4 *)(local_14[0] + 0x34);
    iVar2 = smb_send_setup(param_1);
    if (iVar2 != 0) goto LAB_0005736a;
    *(undefined4 *)(param_1 + 0x3c0) = 3;
  }
  else {
    if (*(int *)(param_1 + 0x3c0) != 3) {
      *(undefined4 *)(param_1 + 0x3ec) = 0;
      return 0;
    }
    if (*(int *)(local_14[0] + 9) != 0) {
      *(undefined *)(param_1 + 0x1ed) = 1;
      return 0x43;
    }
    uVar1 = *(undefined2 *)(local_14[0] + 0x20);
    *(undefined4 *)(param_1 + 0x3c0) = 4;
    *(undefined2 *)(param_1 + 0x3d8) = uVar1;
    *param_2 = 1;
  }
  *(undefined4 *)(param_1 + 0x3ec) = 0;
  return 0;
}


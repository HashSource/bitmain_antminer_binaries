
int ssl3_get_server_done(int param_1)

{
  int iVar1;
  int local_14 [2];
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x1160,0x1161,0xe,0x1e,local_14);
  if (local_14[0] != 0) {
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    else {
      ssl3_send_alert(param_1,2,0x32);
      ERR_put_error(0x14,0x91,0x9f,DAT_00066c30,0x95b);
      iVar1 = -1;
      *(undefined4 *)(param_1 + 0x34) = 5;
    }
  }
  return iVar1;
}


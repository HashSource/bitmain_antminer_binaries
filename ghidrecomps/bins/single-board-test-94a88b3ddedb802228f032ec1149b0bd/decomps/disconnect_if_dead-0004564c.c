
undefined4
disconnect_if_dead(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*(int *)(param_1[0x97] + 0xc) + *(int *)(param_1[0x96] + 0xc) == 0) &&
     (*(char *)(param_1 + 0x10) == '\0')) {
    if ((*(uint *)(param_1[0x86] + 0x3c) & 0x40000) == 0) {
      iVar1 = Curl_socket_check(param_1[0x55],0xffffffff,0xffffffff,0,param_4);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = Curl_rtsp_connisdead();
    }
    if (iVar1 != 0) {
      *param_1 = param_2;
      Curl_infof(param_2,DAT_000456ac,param_1[0x11]);
      Curl_disconnect(param_1,1);
      return 1;
    }
  }
  return 0;
}


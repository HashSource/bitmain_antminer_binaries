
uint Curl_rtsp_connisdead(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *local_c [3];
  
  local_c[0] = param_1;
  uVar1 = Curl_socket_check(param_1[0x55],0xffffffff,0xffffffff,0);
  if (uVar1 != 0) {
    if (((-1 < (int)(uVar1 << 0x1d)) && ((int)(uVar1 << 0x1f) < 0)) && (*local_c[0] != 0)) {
      iVar2 = Curl_getconnectinfo(*local_c[0],local_c);
      return (uint)(iVar2 == -1);
    }
    uVar1 = 1;
  }
  return uVar1;
}


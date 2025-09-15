
int Curl_blockread_all(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int local_24;
  
  iVar2 = 0;
  *param_5 = 0;
  while( true ) {
    do {
      iVar1 = Curl_timeleft(*param_1,0,1);
      if (iVar1 < 0) {
        return 0x1c;
      }
      iVar1 = Curl_socket_check(param_2,0xffffffff,0xffffffff);
      if (iVar1 < 1) {
        return -1;
      }
      iVar1 = Curl_read_plain(param_2,param_3,param_4,&local_24);
    } while (iVar1 == 0x51);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_3 = param_3 + local_24;
    if (param_4 == local_24) break;
    if (local_24 == 0) {
      return -1;
    }
    param_4 = param_4 - local_24;
    iVar2 = iVar2 + local_24;
  }
  *param_5 = param_4 + iVar2;
  return 0;
}


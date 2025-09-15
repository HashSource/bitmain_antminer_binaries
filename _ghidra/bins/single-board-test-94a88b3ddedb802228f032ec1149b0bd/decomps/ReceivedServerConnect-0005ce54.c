
uint ReceivedServerConnect(undefined4 *param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 auStack_28 [4];
  int local_24 [2];
  
  uVar3 = *param_1;
  uVar5 = param_1[0x55];
  uVar4 = param_1[0x56];
  *param_2 = 0;
  iVar1 = ftp_timeleft_accept(uVar3);
  Curl_infof(uVar3,"Checking for server connect\n");
  if (iVar1 < 0) {
    Curl_failf(uVar3,"Accept timeout occurred while waiting server connect");
    uVar2 = 0xc;
  }
  else if (((param_1[0xf1] == 0) || ((byte *)param_1[0xf0] == (byte *)0x0)) ||
          (*(byte *)param_1[0xf0] < 0x34)) {
    uVar2 = Curl_socket_check(uVar5,uVar4,0xffffffff,0);
    if (uVar2 == 0xffffffff) {
      Curl_failf(uVar3,"Error while waiting for server connect");
      uVar2 = 10;
    }
    else if (uVar2 != 0) {
      if ((int)(uVar2 << 0x1c) < 0) {
        Curl_infof(uVar3,"Ready to accept data connection from server\n");
        uVar2 = 0;
        *param_2 = 1;
      }
      else {
        uVar2 = uVar2 & 1;
        if (uVar2 != 0) {
          Curl_infof(uVar3,"Ctrl conn has data while waiting for data conn\n");
          Curl_GetFTPResponse(auStack_28,param_1,local_24);
          if (local_24[0] < 400) {
            uVar2 = 8;
          }
          else {
            uVar2 = 10;
          }
        }
      }
    }
  }
  else {
    Curl_infof(uVar3,"There is negative response in cache while serv connect\n");
    Curl_GetFTPResponse(auStack_28,param_1,local_24);
    uVar2 = 10;
  }
  return uVar2;
}


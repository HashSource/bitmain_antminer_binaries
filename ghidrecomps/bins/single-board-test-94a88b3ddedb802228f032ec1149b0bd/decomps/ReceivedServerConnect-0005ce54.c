
uint ReceivedServerConnect(undefined4 *param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined auStack_28 [4];
  int local_24 [2];
  
  uVar3 = *param_1;
  uVar5 = param_1[0x55];
  uVar4 = param_1[0x56];
  *param_2 = 0;
  iVar1 = ftp_timeleft_accept(uVar3);
  Curl_infof(uVar3,DAT_0005cf14);
  if (iVar1 < 0) {
    Curl_failf(uVar3,DAT_0005cf20);
    uVar2 = 0xc;
  }
  else if (((param_1[0xf1] == 0) || ((byte *)param_1[0xf0] == (byte *)0x0)) ||
          (*(byte *)param_1[0xf0] < 0x34)) {
    uVar2 = Curl_socket_check(uVar5,uVar4,0xffffffff,0);
    if (uVar2 == 0xffffffff) {
      Curl_failf(uVar3,DAT_0005cf24);
      uVar2 = 10;
    }
    else if (uVar2 != 0) {
      if ((int)(uVar2 << 0x1c) < 0) {
        Curl_infof(uVar3,DAT_0005cf28);
        uVar2 = 0;
        *param_2 = 1;
      }
      else {
        uVar2 = uVar2 & 1;
        if (uVar2 != 0) {
          Curl_infof(uVar3,DAT_0005cf1c);
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
    Curl_infof(uVar3,DAT_0005cf18);
    Curl_GetFTPResponse(auStack_28,param_1,local_24);
    uVar2 = 10;
  }
  return uVar2;
}


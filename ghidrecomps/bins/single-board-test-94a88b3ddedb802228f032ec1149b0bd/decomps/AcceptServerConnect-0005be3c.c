
undefined4 AcceptServerConnect(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int __fd;
  int iVar3;
  socklen_t local_9c;
  sockaddr asStack_98 [8];
  
  __fd = param_1[0x56];
  iVar3 = *param_1;
  local_9c = 0x80;
  iVar1 = getsockname(__fd,asStack_98,&local_9c);
  if (iVar1 == 0) {
    local_9c = 0x80;
    iVar1 = accept(__fd,asStack_98,&local_9c);
    Curl_closesocket(param_1,__fd);
    if (iVar1 != -1) {
      Curl_infof(iVar3,DAT_0005bed8);
      *(undefined *)((int)param_1 + 0x1f5) = 0;
      param_1[0x56] = iVar1;
      curlx_nonblock(iVar1,1);
      pcVar2 = *(code **)(iVar3 + 0x1d0);
      *(undefined *)((int)param_1 + 0x165) = 1;
      if ((pcVar2 != (code *)0x0) &&
         (iVar1 = (*pcVar2)(*(undefined4 *)(iVar3 + 0x1d4),iVar1), iVar1 != 0)) {
        close_secondarysocket(param_1);
        return 0x2a;
      }
      return 0;
    }
  }
  else {
    Curl_closesocket(param_1,__fd);
  }
  Curl_failf(iVar3,DAT_0005bed4);
  return 0x1e;
}


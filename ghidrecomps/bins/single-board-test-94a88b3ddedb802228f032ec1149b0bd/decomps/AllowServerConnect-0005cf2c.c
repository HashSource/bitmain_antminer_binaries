
int AllowServerConnect(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = *param_1;
  *param_2 = '\0';
  Curl_infof(iVar3,DAT_0005cf9c);
  Curl_pgrsTime(iVar3,9);
  iVar1 = ftp_timeleft_accept(iVar3);
  if (iVar1 < 0) {
    Curl_failf(iVar3,DAT_0005cfa0);
    return 0xc;
  }
  iVar1 = ReceivedServerConnect(param_1,param_2);
  if (iVar1 == 0) {
    if (*param_2 == '\0') {
      iVar2 = *(int *)(iVar3 + 0x208);
      if (iVar2 < 1) {
        iVar2 = 60000;
      }
      Curl_expire(iVar3,iVar2);
    }
    else {
      uVar4 = AcceptServerConnect(param_1);
      iVar1 = (int)uVar4;
      if (iVar1 == 0) {
        iVar1 = InitiateTransfer(param_1,(int)((ulonglong)uVar4 >> 0x20),param_3,param_4);
        return iVar1;
      }
    }
  }
  return iVar1;
}



ssize_t Curl_recv_plain(int *param_1,int param_2,void *param_3,size_t param_4,undefined4 *param_5)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = recv(param_1[param_2 + 0x55],param_3,param_4,0);
  *param_5 = 0;
  if (sVar1 == -1) {
    piVar2 = __errno_location();
    iVar4 = *piVar2;
    if (iVar4 != 0xb && iVar4 != 4) {
      iVar5 = *param_1;
      uVar3 = Curl_strerror(param_1,iVar4);
      Curl_failf(iVar5,DAT_000431dc,uVar3);
      *(int *)(*param_1 + 0x85cc) = iVar4;
      *param_5 = 0x38;
      return -1;
    }
    *param_5 = 0x51;
  }
  return sVar1;
}


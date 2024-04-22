
ssize_t Curl_send_plain(int *param_1,int param_2,void *param_3,size_t param_4,undefined4 *param_5)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  sVar1 = send(param_1[param_2 + 0x55],param_3,param_4,0x4000);
  *param_5 = 0;
  if (sVar1 != -1) {
    return sVar1;
  }
  piVar2 = __errno_location();
  iVar5 = *piVar2;
  if (iVar5 == 0xb || iVar5 == 4) {
    *param_5 = 0x51;
    return 0;
  }
  iVar4 = *param_1;
  uVar3 = Curl_strerror(param_1,iVar5);
  Curl_failf(iVar4,DAT_00043254,uVar3);
  *(int *)(*param_1 + 0x85cc) = iVar5;
  *param_5 = 0x37;
  return -1;
}


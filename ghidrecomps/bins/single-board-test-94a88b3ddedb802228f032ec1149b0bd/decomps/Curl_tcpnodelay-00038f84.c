
void Curl_tcpnodelay(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_14 [2];
  
  local_14[0] = 1;
  uVar4 = *param_1;
  iVar1 = setsockopt(param_2,6,1,local_14,4);
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    uVar3 = Curl_strerror(param_1,*piVar2);
    Curl_infof(uVar4,DAT_00038fcc,uVar3);
  }
  else {
    Curl_infof(uVar4,DAT_00038fc8);
  }
  return;
}


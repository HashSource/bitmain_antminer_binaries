
void send_negotiation(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  
  local_1b = (undefined)param_2;
  local_1a = (undefined)param_3;
  uVar3 = *param_1;
  local_1c = 0xff;
  sVar1 = send(param_1[0x55],&local_1c,3,0x4000);
  if (sVar1 < 0) {
    piVar2 = __errno_location();
    Curl_failf(uVar3,DAT_00049cfc,*piVar2);
  }
  printoption(*param_1,DAT_00049cf8,param_2,param_3);
  return;
}


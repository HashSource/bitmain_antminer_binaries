
void send_negotiation(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  local_1b = (undefined1)param_2;
  local_1a = (undefined1)param_3;
  uVar3 = *param_1;
  local_1c = 0xff;
  sVar1 = send(param_1[0x55],&local_1c,3,0x4000);
  if (sVar1 < 0) {
    piVar2 = __errno_location();
    Curl_failf(uVar3,"Sending data failed (%d)",*piVar2);
  }
  printoption(*param_1,&DAT_00137464,param_2,param_3);
  return;
}


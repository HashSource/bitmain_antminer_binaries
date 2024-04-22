
int curl_easy_send(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int local_28;
  undefined4 local_24 [2];
  
  local_24[0] = 0;
  if (param_1 == 0) {
    iVar1 = 0x2b;
  }
  else if (*(char *)(param_1 + 0x329) == '\0') {
    Curl_failf(param_1,DAT_00038c50);
    iVar1 = 1;
  }
  else {
    iVar1 = Curl_getconnectinfo(param_1,local_24);
    if (iVar1 == -1) {
      Curl_failf(param_1,DAT_00038c54);
      iVar1 = 1;
    }
    else {
      *param_4 = 0;
      iVar1 = Curl_write(local_24[0],iVar1,param_2,param_3,&local_28);
      if (local_28 == -1) {
        iVar1 = 0x37;
      }
      else if ((iVar1 == 0) && (local_28 == 0)) {
        iVar1 = 0x51;
      }
      else {
        *param_4 = local_28;
      }
    }
  }
  return iVar1;
}


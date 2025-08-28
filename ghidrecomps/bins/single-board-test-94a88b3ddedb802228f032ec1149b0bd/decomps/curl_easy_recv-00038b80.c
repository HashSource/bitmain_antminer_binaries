
int curl_easy_recv(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 == 0) {
    iVar1 = 0x2b;
  }
  else if (*(char *)(param_1 + 0x329) == '\0') {
    Curl_failf(param_1,"CONNECT_ONLY is required!");
    iVar1 = 1;
  }
  else {
    iVar1 = Curl_getconnectinfo(param_1,&local_1c);
    if (iVar1 == -1) {
      Curl_failf(param_1,"Failed to get recent socket");
      iVar1 = 1;
    }
    else {
      *param_4 = 0;
      iVar1 = Curl_read(local_1c,iVar1,param_2,param_3,&local_20);
      if (iVar1 == 0) {
        *param_4 = local_20;
      }
    }
  }
  return iVar1;
}


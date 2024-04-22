
int Curl_reconnect_request(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_1e;
  undefined local_1d;
  undefined4 *local_1c [2];
  
  local_1c[0] = (undefined4 *)*param_1;
  uVar2 = *local_1c[0];
  Curl_infof(uVar2,DAT_0004c2e8);
  *(undefined *)((int)local_1c[0] + 0x1ed) = 1;
  iVar1 = Curl_done(local_1c,0,0);
  *param_1 = 0;
  if (iVar1 == 0 || iVar1 == 0x37) {
    local_1d = 1;
    iVar1 = Curl_connect(uVar2,param_1,&local_1e,&local_1d);
    if ((iVar1 == 0) && (local_1e != '\0')) {
      iVar1 = 6;
    }
  }
  return iVar1;
}


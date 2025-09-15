
int Curl_reconnect_request(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_1e [2];
  undefined4 *local_1c [2];
  
  local_1c[0] = (undefined4 *)*param_1;
  uVar2 = *local_1c[0];
  Curl_infof(uVar2,"Re-used connection seems dead, get a new one\n");
  *(undefined1 *)((int)local_1c[0] + 0x1ed) = 1;
  iVar1 = Curl_done(local_1c,0,0);
  *param_1 = 0;
  if (iVar1 == 0 || iVar1 == 0x37) {
    local_1e[1] = 1;
    iVar1 = Curl_connect(uVar2,param_1,local_1e,local_1e + 1);
    if ((iVar1 == 0) && (local_1e[0] != '\0')) {
      iVar1 = 6;
    }
  }
  return iVar1;
}



void Curl_http_connect(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined *)(param_1 + 0x1ed) = 0;
  iVar1 = Curl_proxy_connect();
  if ((iVar1 == 0) && (*(int *)(param_1 + 0x468) != 1)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x21c) + 0x40) << 0x1f;
    if (iVar1 < 0) {
      https_connecting(param_1,param_2,iVar1,param_4);
      return;
    }
    *param_2 = 1;
  }
  return;
}


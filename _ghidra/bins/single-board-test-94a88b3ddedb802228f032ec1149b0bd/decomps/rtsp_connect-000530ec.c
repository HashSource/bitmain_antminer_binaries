
void rtsp_connect(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  Curl_http_connect();
  if (*(int *)(iVar1 + 0x86a0) == 0) {
    *(undefined4 *)(iVar1 + 0x86a0) = 1;
  }
  if (*(int *)(iVar1 + 0x86a4) == 0) {
    *(undefined4 *)(iVar1 + 0x86a4) = 1;
  }
  param_1[0xf2] = -1;
  return;
}


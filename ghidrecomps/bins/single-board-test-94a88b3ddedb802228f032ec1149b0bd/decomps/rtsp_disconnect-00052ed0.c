
void rtsp_disconnect(int param_1)

{
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x3c0));
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  return;
}


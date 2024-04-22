
void close_secondarysocket(int param_1)

{
  if (*(int *)(param_1 + 0x158) != -1) {
    Curl_closesocket();
    *(undefined4 *)(param_1 + 0x158) = 0xffffffff;
  }
  *(undefined *)(param_1 + 0x1f7) = 0;
  *(undefined4 *)(param_1 + 0x46c) = 0;
  return;
}


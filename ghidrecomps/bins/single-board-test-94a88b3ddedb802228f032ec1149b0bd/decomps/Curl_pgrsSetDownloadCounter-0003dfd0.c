
void Curl_pgrsSetDownloadCounter
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x488) = param_3;
  *(undefined4 *)(param_1 + 0x48c) = param_4;
  return;
}


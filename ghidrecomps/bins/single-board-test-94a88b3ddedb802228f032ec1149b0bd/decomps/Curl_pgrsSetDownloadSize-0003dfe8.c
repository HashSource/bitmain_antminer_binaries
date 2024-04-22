
void Curl_pgrsSetDownloadSize(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 < 0) {
    *(undefined4 *)(param_1 + 0x478) = 0;
    *(undefined4 *)(param_1 + 0x47c) = 0;
    *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) & 0xffffffbf;
  }
  else {
    *(undefined4 *)(param_1 + 0x478) = param_3;
    *(int *)(param_1 + 0x47c) = param_4;
    *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) | 0x40;
  }
  return;
}


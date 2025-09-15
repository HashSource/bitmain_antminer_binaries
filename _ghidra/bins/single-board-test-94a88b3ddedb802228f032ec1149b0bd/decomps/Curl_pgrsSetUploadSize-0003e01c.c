
void Curl_pgrsSetUploadSize(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 < 0) {
    *(undefined4 *)(param_1 + 0x480) = 0;
    *(undefined4 *)(param_1 + 0x484) = 0;
    *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) & 0xffffffdf;
  }
  else {
    *(undefined4 *)(param_1 + 0x480) = param_3;
    *(int *)(param_1 + 0x484) = param_4;
    *(uint *)(param_1 + 0x4a8) = *(uint *)(param_1 + 0x4a8) | 0x20;
  }
  return;
}


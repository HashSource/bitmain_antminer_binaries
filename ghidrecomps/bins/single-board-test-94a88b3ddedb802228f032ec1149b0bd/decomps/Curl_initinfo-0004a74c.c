
undefined4 Curl_initinfo(int param_1)

{
  *(undefined4 *)(param_1 + 0x4f0) = 0;
  *(undefined4 *)(param_1 + 0x4f4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  *(undefined4 *)(param_1 + 0x4d8) = 0;
  *(undefined4 *)(param_1 + 0x4dc) = 0;
  *(undefined4 *)(param_1 + 0x4e0) = 0;
  *(undefined4 *)(param_1 + 0x4e4) = 0;
  *(undefined4 *)(param_1 + 0x4e8) = 0;
  *(undefined4 *)(param_1 + 0x4ec) = 0;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x8700) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x86f4) = 0;
  *(undefined4 *)(param_1 + 0x86f8) = 0;
  *(undefined4 *)(param_1 + 0x86fc) = 0;
  *(undefined *)(param_1 + 0x8704) = 0;
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x871c));
  *(undefined4 *)(param_1 + 0x871c) = 0;
  *(undefined4 *)(param_1 + 0x8708) = 0;
  *(undefined4 *)(param_1 + 0x870c) = 0;
  *(undefined4 *)(param_1 + 0x8718) = 0;
  *(undefined *)(param_1 + 0x8724) = 0;
  *(undefined *)(param_1 + 0x8758) = 0;
  *(undefined4 *)(param_1 + 0x8754) = 0;
  *(undefined4 *)(param_1 + 0x8788) = 0;
  return 0;
}


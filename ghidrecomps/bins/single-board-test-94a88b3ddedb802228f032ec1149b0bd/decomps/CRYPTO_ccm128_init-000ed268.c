
void CRYPTO_ccm128_init(byte *param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5
                       )

{
  memset(param_1,0,0x10);
  *(undefined4 *)(param_1 + 0x2c) = param_4;
  *param_1 = param_3 - 1U & 7 | (byte)(((uint)((param_2 + -2) * 0x10000000) >> 0x1d) << 3);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_5;
  return;
}


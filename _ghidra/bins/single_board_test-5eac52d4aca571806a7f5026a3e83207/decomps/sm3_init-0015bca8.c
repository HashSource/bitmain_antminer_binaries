
undefined4 sm3_init(undefined4 *param_1)

{
  memset(param_1,0,0x6c);
  *param_1 = 0x7380166f;
  param_1[2] = 0x172442d7;
  param_1[1] = 0x4914b2b9;
  param_1[3] = 0xda8a0600;
  param_1[4] = 0xa96f30bc;
  param_1[5] = 0x163138aa;
  param_1[6] = 0xe38dee4d;
  param_1[7] = 0xb0fb0e4e;
  return 1;
}


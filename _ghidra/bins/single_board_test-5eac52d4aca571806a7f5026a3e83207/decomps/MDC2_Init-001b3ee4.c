
void MDC2_Init(undefined4 *param_1)

{
  param_1[3] = 0x52525252;
  param_1[4] = 0x52525252;
  param_1[5] = 0x25252525;
  param_1[6] = 0x25252525;
  *param_1 = 0;
  param_1[7] = 1;
  return;
}


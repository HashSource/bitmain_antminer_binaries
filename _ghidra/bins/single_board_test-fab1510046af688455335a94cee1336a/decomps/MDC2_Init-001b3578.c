
undefined4 MDC2_Init(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[7] = 1;
  memset(param_1 + 3,0x52,8);
  memset(param_1 + 5,0x25,8);
  return 1;
}


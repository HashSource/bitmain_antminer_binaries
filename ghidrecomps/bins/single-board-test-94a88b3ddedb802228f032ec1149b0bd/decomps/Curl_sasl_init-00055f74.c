
void Curl_sasl_init(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[3] = 0xffffffdf;
  *(undefined *)(param_1 + 5) = 1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  *(undefined *)((int)param_1 + 0x15) = 0;
  *(undefined *)((int)param_1 + 0x16) = 0;
  return;
}


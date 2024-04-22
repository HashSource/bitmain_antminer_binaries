
void Curl_write64_le(undefined4 param_1,undefined4 param_2,undefined *param_3)

{
  *param_3 = (char)param_1;
  param_3[1] = (char)((uint)param_1 >> 8);
  param_3[2] = (char)((uint)param_1 >> 0x10);
  param_3[3] = (char)((uint)param_1 >> 0x18);
  param_3[5] = (char)((uint)param_2 >> 8);
  param_3[6] = (char)((uint)param_2 >> 0x10);
  param_3[4] = (char)param_2;
  param_3[7] = (char)((uint)param_2 >> 0x18);
  return;
}


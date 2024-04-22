
void Curl_write16_le(undefined4 param_1,undefined *param_2)

{
  *param_2 = (char)param_1;
  param_2[1] = (char)((uint)param_1 >> 8);
  return;
}


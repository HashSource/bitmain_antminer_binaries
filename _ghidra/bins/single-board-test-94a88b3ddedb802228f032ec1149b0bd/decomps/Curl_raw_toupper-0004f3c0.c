
uint Curl_raw_toupper(uint param_1)

{
  if (param_1 - 0x61 < 0x1a) {
    param_1 = param_1 - 0x20 & 0xff;
  }
  return param_1;
}


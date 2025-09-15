
uint Curl_read32_le(byte *param_1)

{
  return (uint)param_1[2] << 0x10 | (uint)param_1[1] << 8 | (uint)*param_1 |
         (uint)param_1[3] << 0x18;
}



undefined8 Curl_read64_le(byte *param_1)

{
  return CONCAT44(*(undefined4 *)(param_1 + 4),
                  (uint)param_1[1] << 8 | (uint)param_1[2] << 0x10 | (uint)*param_1 |
                  (uint)param_1[3] << 0x18);
}


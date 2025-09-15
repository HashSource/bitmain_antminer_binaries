
uint Curl_sasl_can_authenticate(int param_1,int param_2)

{
  if (*(char *)(param_2 + 0x1f1) == '\0') {
    return ((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) << 0x1a) >> 0x1f;
  }
  return 1;
}


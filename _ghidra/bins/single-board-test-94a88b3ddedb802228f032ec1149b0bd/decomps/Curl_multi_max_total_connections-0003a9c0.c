
int Curl_multi_max_total_connections(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x9c);
  }
  return param_1;
}


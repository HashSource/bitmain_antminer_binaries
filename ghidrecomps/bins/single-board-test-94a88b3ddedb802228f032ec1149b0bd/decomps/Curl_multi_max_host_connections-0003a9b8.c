
int Curl_multi_max_host_connections(int param_1)

{
  if (param_1 != 0) {
    param_1 = *(int *)(param_1 + 0x98);
  }
  return param_1;
}


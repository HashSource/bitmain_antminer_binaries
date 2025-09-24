
uint SSL_set_options(int param_1,uint param_2)

{
  param_2 = param_2 | *(uint *)(param_1 + 0x4ec);
  *(uint *)(param_1 + 0x4ec) = param_2;
  return param_2;
}


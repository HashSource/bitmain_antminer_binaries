
uint SSL_CTX_set_options(int param_1,uint param_2)

{
  param_2 = param_2 | *(uint *)(param_1 + 0xac);
  *(uint *)(param_1 + 0xac) = param_2;
  return param_2;
}


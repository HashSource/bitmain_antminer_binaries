
undefined4 SSL_set_recv_max_early_data(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xf54) = param_2;
  return 1;
}


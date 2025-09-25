
undefined4 SSL_set_max_early_data(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xf50) = param_2;
  return 1;
}


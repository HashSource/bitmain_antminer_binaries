
undefined4 SSL_set_num_tickets(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xf6c) = param_2;
  return 1;
}


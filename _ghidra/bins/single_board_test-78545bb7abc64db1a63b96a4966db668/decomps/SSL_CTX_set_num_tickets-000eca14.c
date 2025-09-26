
undefined4 SSL_CTX_set_num_tickets(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x240) = param_2;
  return 1;
}


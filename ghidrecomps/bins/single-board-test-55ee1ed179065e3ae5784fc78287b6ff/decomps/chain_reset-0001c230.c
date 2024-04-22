
void chain_reset(undefined4 param_1)

{
  chain_reset_low(param_1);
  usleep(100000);
  chain_reset_high(param_1);
  return;
}



void board_reset(undefined4 param_1)

{
  board_reset_low(param_1);
  usleep(100000);
  board_reset_high(param_1);
  return;
}


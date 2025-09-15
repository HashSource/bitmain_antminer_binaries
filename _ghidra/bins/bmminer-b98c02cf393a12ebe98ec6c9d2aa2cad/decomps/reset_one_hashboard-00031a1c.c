
void reset_one_hashboard(int param_1)

{
  int iVar1;
  
  set_QN_write_data_command(param_1 << 0x10 | 0x8000000f);
  while (iVar1 = get_QN_write_data_command(), iVar1 < 0) {
    usleep(10000);
  }
  sleep(1);
  return;
}



void reset_hashboard(void)

{
  int iVar1;
  
  set_QN_write_data_command(0x8080000f);
  while (iVar1 = get_QN_write_data_command(), iVar1 < 0) {
    usleep(10000);
  }
  sleep(1);
  return;
}


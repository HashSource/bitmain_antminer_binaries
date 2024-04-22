
void reset_one_hashboard(int chainIndex)

{
  int iVar1;
  int chainIndex_local;
  
  set_QN_write_data_command(chainIndex << 0x10 | 0x8000000f);
  while (iVar1 = get_QN_write_data_command(), iVar1 < 0) {
    usleep(10000);
  }
  sleep(1);
  return;
}


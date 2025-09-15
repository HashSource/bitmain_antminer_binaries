
void set_freq_default(int default_freq)

{
  int iVar1;
  int default_freq_local;
  int column;
  int chain;
  
  memset(scan_result,0,0x1020);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = default_freq + 0xff;
      if (-1 < default_freq) {
        iVar1 = default_freq;
      }
      scan_result[chain].start_freq_high = (uchar)((uint)iVar1 >> 8);
      scan_result[chain].start_freq_low = (uchar)default_freq;
      scan_result[chain].freq_step = '\x05';
      for (column = 0; column < 10; column = column + 1) {
        scan_result[chain].column_freq_level[column] = '\0';
      }
    }
  }
  return;
}


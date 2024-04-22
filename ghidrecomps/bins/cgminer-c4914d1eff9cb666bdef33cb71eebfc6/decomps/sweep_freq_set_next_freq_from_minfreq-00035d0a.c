
/* WARNING: Unknown calling convention */

void sweep_freq_set_next_freq_from_minfreq(void)

{
  int current_column;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      sweep_freq_set_column_freq_from_minfreq(chain,(uint)scanfreq_info.current_column[chain]);
    }
  }
  return;
}


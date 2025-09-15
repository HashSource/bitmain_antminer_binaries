
/* WARNING: Unknown calling convention */

int scanfreq_get_max_freq_index(void)

{
  int chain;
  int max_freq_index;
  
  max_freq_index = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) &&
       (max_freq_index < scanfreq_info.current_index[chain])) {
      max_freq_index = scanfreq_info.current_index[chain];
    }
  }
  return max_freq_index;
}


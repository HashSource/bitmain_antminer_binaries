
/* WARNING: Unknown calling convention */

int scan_freq_get_min_base_freq(void)

{
  int min_freq;
  int chain;
  
  min_freq = 1000;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) &&
       (scanfreq_info.base_freq[chain] < min_freq)) {
      min_freq = scanfreq_info.base_freq[chain];
    }
  }
  return min_freq;
}


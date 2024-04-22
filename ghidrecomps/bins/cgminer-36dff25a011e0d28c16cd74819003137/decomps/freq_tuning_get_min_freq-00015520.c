
int freq_tuning_get_min_freq(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int chain;
  int min_freq;
  
  min_freq = 0xffff;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (freq_info->scan_freq[chain] < min_freq)) {
      min_freq = freq_info->scan_freq[chain];
    }
  }
  return min_freq;
}


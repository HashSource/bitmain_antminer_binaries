
int sweep_freq_get_rate_min_freq(int chain,int rate)

{
  int rate_local;
  int chain_local;
  int min_freq;
  int chip;
  
  min_freq = 0xffff;
  for (chip = 0; chip < 0x3c; chip = chip + 1) {
    if ((rate == scanfreq_info.chip_rate[chain][chip]) &&
       (scanfreq_info.chip_max_freq[chain][chip] < min_freq)) {
      min_freq = scanfreq_info.chip_max_freq[chain][chip];
    }
  }
  return min_freq;
}


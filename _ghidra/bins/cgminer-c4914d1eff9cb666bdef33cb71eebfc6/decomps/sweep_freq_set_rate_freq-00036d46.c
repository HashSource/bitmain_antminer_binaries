
void sweep_freq_set_rate_freq(int chain,int rate,int freq)

{
  int freq_local;
  int rate_local;
  int chain_local;
  int chip;
  
  for (chip = 0; chip < 0x3c; chip = chip + 1) {
    if (rate == scanfreq_info.chip_rate[chain][chip]) {
      *(int *)(scanfreq_info.workdataPathPrefix +
              (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) = freq;
    }
  }
  return;
}


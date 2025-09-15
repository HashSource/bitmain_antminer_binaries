
/* WARNING: Unknown calling convention */

int do_get_ideal_max_hash_rate(void)

{
  uint32_t freq_one_chain [48];
  int work_mode;
  int i;
  int chain;
  uint32_t total_rate;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      work_mode = (int)(opt_bitmain_economic_mode == false);
      eeprom_get_freq(chain,work_mode,freq_one_chain,0x30);
      for (i = 0; i < 0x30; i = i + 1) {
        total_rate = total_rate + freq_one_chain[i] * 0x2a0;
      }
    }
  }
  return total_rate / 1000;
}


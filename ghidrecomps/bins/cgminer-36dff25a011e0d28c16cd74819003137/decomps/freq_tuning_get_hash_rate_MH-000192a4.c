
int freq_tuning_get_hash_rate_MH(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int hash_rate;
  int asic;
  int chain;
  
  hash_rate = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        hash_rate = hash_rate + freq_info->freq_table[chain][asic] * 0x2a0;
      }
    }
  }
  return hash_rate;
}


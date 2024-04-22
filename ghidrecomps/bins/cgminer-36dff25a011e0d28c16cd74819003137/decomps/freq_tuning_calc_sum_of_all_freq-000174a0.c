
void freq_tuning_calc_sum_of_all_freq(freq_tuning_info *freq_info,int *sum,int chain)

{
  int chain_local;
  int *sum_local;
  freq_tuning_info *freq_info_local;
  int scan_level;
  int asic;
  
  for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
    sum[asic] = 0;
    for (scan_level = 0; scan_level < 8; scan_level = scan_level + 1) {
      sum[asic] = sum[asic] + freq_info->chip_rate_table[chain][scan_level][asic];
    }
  }
  return;
}


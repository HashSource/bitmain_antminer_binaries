
void freq_tuning_init_chip_rate_table
               (freq_tuning_info *freq_info,int *recv_nonce_num_table,int chain)

{
  int iVar1;
  int chain_local;
  int *recv_nonce_num_table_local;
  freq_tuning_info *freq_info_local;
  int scan_level_index;
  int asic;
  
  iVar1 = freq_tuning_get_scan_level_index(freq_info,freq_info->scan_freq[chain]);
  for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
    freq_info->chip_rate_table[chain][iVar1][asic] =
         recv_nonce_num_table[asic] * freq_info->scan_freq[chain];
  }
  return;
}


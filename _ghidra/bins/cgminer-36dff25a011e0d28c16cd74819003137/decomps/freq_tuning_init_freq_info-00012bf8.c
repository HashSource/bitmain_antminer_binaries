
void freq_tuning_init_freq_info(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int i;
  
  memset(freq_info,0,0x1410c);
  freq_info->asic_num_per_chain = 0x30;
  freq_info->asic_num_per_vol_domain = 4;
  memset(freq_info->vol_value_table,0,0x40);
  for (i = 0; i < 0x10; i = i + 1) {
    freq_info->scan_freq[i] = freq_info->freq_table[i][0];
    freq_info->test_done[i] = false;
    freq_info->fake_done[i] = false;
  }
  freq_info->is_pass = false;
  freq_info->is_unbalance_happened = false;
  return;
}


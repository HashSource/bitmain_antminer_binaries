
void freq_tuning_set_freq_all_chain(freq_tuning_info *freq_info)

{
  freq_tuning_info *freq_info_local;
  int chain;
  
  chain = 0;
  while( true ) {
    if (0xf < chain) {
      return;
    }
    if (dev->chain_exist[chain] != 0) break;
    chain = chain + 1;
  }
  increase_freq_slowly
            ((float)(longlong)g_init_freq,(float)(longlong)freq_info->scan_freq[chain],
             (float)(longlong)DAT_000154f4,All_Chain);
  g_init_freq = freq_info->scan_freq[chain];
  return;
}



void scanfreq_get_next_freq_chain(int chain)

{
  int chain_local;
  int *freq_index_min;
  int *freq_index_max;
  int *current_index;
  int middle_index;
  
  if (scanfreq_info.current_index[chain] == -1) {
    scanfreq_info.current_index[chain] =
         (scanfreq_info.freq_index_max[chain] + scanfreq_info.freq_index_min[chain]) / 2;
  }
  else {
    scanfreq_get_next_freq_chain::counter[chain] = scanfreq_get_next_freq_chain::counter[chain] + 1;
    if (scanfreq_get_next_freq_chain::counter[chain] == 10) {
      scanfreq_info.scan_finished[chain] = true;
    }
  }
  return;
}


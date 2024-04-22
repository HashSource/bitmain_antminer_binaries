
void set_freq_yf(float freq)

{
  float freq_local;
  int local_pll_index;
  int chain;
  
  local_pll_index = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      if (gUsePllList != false) {
        local_pll_index = get_index_from_high_pll_yf((int)freq);
      }
      change_high_pll_test((uchar)chain,freq,local_pll_index);
      open_core_BM1393_S11_single_board((uchar)chain);
    }
  }
  return;
}


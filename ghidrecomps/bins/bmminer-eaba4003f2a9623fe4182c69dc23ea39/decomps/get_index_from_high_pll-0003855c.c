
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_index_from_high_pll(int freq)

{
  int freq_local;
  char tmp42 [2048];
  int i;
  
  i = 0;
  while ((((uint)i < 0x21 && (freq_high_pll_1393[i].freq != freq)) &&
         ((freq_high_pll_1393[i].freq <= (uint)freq ||
          ((uint)freq <= freq_high_pll_1393[i + -1].freq))))) {
    i = i + 1;
  }
  if (i == 0x21) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      tmp42._0_4_ = s_high_freq_index_set_error_return_00076c58._0_4_;
      tmp42._4_4_ = s_high_freq_index_set_error_return_00076c58._4_4_;
      tmp42._8_4_ = s_high_freq_index_set_error_return_00076c58._8_4_;
      tmp42._12_4_ = s_high_freq_index_set_error_return_00076c58._12_4_;
      tmp42._16_4_ = s_high_freq_index_set_error_return_00076c58._16_4_;
      tmp42._20_4_ = s_high_freq_index_set_error_return_00076c58._20_4_;
      tmp42._24_4_ = s_high_freq_index_set_error_return_00076c58._24_4_;
      tmp42._28_4_ = s_high_freq_index_set_error_return_00076c58._28_4_;
      tmp42._32_4_ = s_high_freq_index_set_error_return_00076c58._32_4_;
      tmp42._36_4_ = s_high_freq_index_set_error_return_00076c58._36_4_;
      tmp42._40_4_ = s_high_freq_index_set_error_return_00076c58._40_4_;
      tmp42._44_4_ = s_high_freq_index_set_error_return_00076c58._44_4_;
      tmp42._48_2_ = (undefined2)ram0x00076c88;
      tmp42[50] = (char)((uint)ram0x00076c88 >> 0x10);
      _applog(3,tmp42,false);
    }
    i = get_index_from_high_pll(200);
  }
  return i;
}


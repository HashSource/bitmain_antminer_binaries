
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_index_from_pll_B1391(int pll)

{
  int pll_local;
  char tmp42 [2048];
  int i;
  
  for (i = 0; ((uint)i < 0xb3 && (pll != freq_pll_1391[i].freq)); i = i + 1) {
  }
  if (i == 0xb3) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      tmp42._0_4_ = s_freq_index_set_error_return_defa_0009a6d4._0_4_;
      tmp42._4_4_ = s_freq_index_set_error_return_defa_0009a6d4._4_4_;
      tmp42._8_4_ = s_freq_index_set_error_return_defa_0009a6d4._8_4_;
      tmp42._12_4_ = s_freq_index_set_error_return_defa_0009a6d4._12_4_;
      tmp42._16_4_ = s_freq_index_set_error_return_defa_0009a6d4._16_4_;
      tmp42._20_4_ = s_freq_index_set_error_return_defa_0009a6d4._20_4_;
      tmp42._24_4_ = s_freq_index_set_error_return_defa_0009a6d4._24_4_;
      tmp42._28_4_ = s_freq_index_set_error_return_defa_0009a6d4._28_4_;
      tmp42._32_4_ = s_freq_index_set_error_return_defa_0009a6d4._32_4_;
      tmp42._36_4_ = s_freq_index_set_error_return_defa_0009a6d4._36_4_;
      tmp42._40_4_ = s_freq_index_set_error_return_defa_0009a6d4._40_4_;
      tmp42._44_2_ = (undefined2)ram0x0009a700;
      _applog(3,tmp42,false);
    }
    i = get_index_from_pll_B1391(200);
  }
  return i;
}


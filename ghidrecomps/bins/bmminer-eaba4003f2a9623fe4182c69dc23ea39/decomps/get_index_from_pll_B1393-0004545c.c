
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_index_from_pll_B1393(int pll)

{
  int pll_local;
  char tmp42 [2048];
  int i;
  
  for (i = 0; ((uint)i < 0xb3 && (freq_pll_1393[i].freq != pll)); i = i + 1) {
  }
  if (i == 0xb3) {
    if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
      tmp42._0_4_ = s_freq_index_set_error_return_defa_00077e80._0_4_;
      tmp42._4_4_ = s_freq_index_set_error_return_defa_00077e80._4_4_;
      tmp42._8_4_ = s_freq_index_set_error_return_defa_00077e80._8_4_;
      tmp42._12_4_ = s_freq_index_set_error_return_defa_00077e80._12_4_;
      tmp42._16_4_ = s_freq_index_set_error_return_defa_00077e80._16_4_;
      tmp42._20_4_ = s_freq_index_set_error_return_defa_00077e80._20_4_;
      tmp42._24_4_ = s_freq_index_set_error_return_defa_00077e80._24_4_;
      tmp42._28_4_ = s_freq_index_set_error_return_defa_00077e80._28_4_;
      tmp42._32_4_ = s_freq_index_set_error_return_defa_00077e80._32_4_;
      tmp42._36_4_ = s_freq_index_set_error_return_defa_00077e80._36_4_;
      tmp42._40_4_ = s_freq_index_set_error_return_defa_00077e80._40_4_;
      tmp42._44_2_ = (undefined2)ram0x00077eac;
      _applog(3,tmp42,false);
    }
    i = get_index_from_pll_B1393(200);
  }
  return i;
}


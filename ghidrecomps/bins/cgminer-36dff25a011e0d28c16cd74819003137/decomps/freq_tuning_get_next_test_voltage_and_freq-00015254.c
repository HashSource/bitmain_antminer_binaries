
_Bool freq_tuning_get_next_test_voltage_and_freq
                (freq_tuning_info *freq_info,_Bool reset_test_level,int sub_proj_index)

{
  int iVar1;
  _Bool _Var2;
  int sub_proj_index_local;
  _Bool reset_test_level_local;
  freq_tuning_info *freq_info_local;
  int test_freq;
  int test_voltage;
  int chain;
  
  test_voltage = 0;
  test_freq = 0;
  if (reset_test_level) {
    freq_tuning_get_next_test_voltage_and_freq::test_level = 0;
  }
  iVar1 = freq_tuning_get_next_test_voltage_and_freq::test_level;
  freq_tuning_get_next_test_voltage_and_freq::test_level =
       freq_tuning_get_next_test_voltage_and_freq::test_level + 1;
  iVar1 = freq_tuning_get_board_test_voltage_and_freq(iVar1,&test_voltage,&test_freq,sub_proj_index)
  ;
  if (iVar1 == -1) {
    _Var2 = false;
  }
  else {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        freq_info->vol_value_table[chain] = test_voltage;
        freq_info->scan_freq[chain] = test_freq;
      }
    }
    _Var2 = true;
  }
  return _Var2;
}


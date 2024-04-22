
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint8_t get_bt8d_from_baud(uint32_t baud)

{
  uint8_t uVar1;
  uint32_t baud_local;
  char tmp42 [1024];
  size_t max;
  size_t index;
  
  index = 0;
  while( true ) {
    if (4 < index) {
      if (index == 5) {
        if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
          tmp42._0_4_ = s_get_bt8d_value_failed____use_def_00033ed4._0_4_;
          tmp42._4_4_ = s_get_bt8d_value_failed____use_def_00033ed4._4_4_;
          tmp42._8_4_ = s_get_bt8d_value_failed____use_def_00033ed4._8_4_;
          tmp42._12_4_ = s_get_bt8d_value_failed____use_def_00033ed4._12_4_;
          tmp42._16_4_ = s_get_bt8d_value_failed____use_def_00033ed4._16_4_;
          tmp42._20_4_ = s_get_bt8d_value_failed____use_def_00033ed4._20_4_;
          tmp42._24_4_ = s_get_bt8d_value_failed____use_def_00033ed4._24_4_;
          tmp42._28_4_ = s_get_bt8d_value_failed____use_def_00033ed4._28_4_;
          tmp42._32_4_ = s_get_bt8d_value_failed____use_def_00033ed4._32_4_;
          tmp42._36_4_ = s_get_bt8d_value_failed____use_def_00033ed4._36_4_;
          tmp42._40_4_ = s_get_bt8d_value_failed____use_def_00033ed4._40_4_;
          tmp42._44_4_ = s_get_bt8d_value_failed____use_def_00033ed4._44_4_;
          tmp42._48_2_ = (undefined2)ram0x00033f04;
          _applog(3,tmp42,false);
        }
        uVar1 = get_bt8d_from_baud(0x1c200);
      }
      else {
        uVar1 = 0xff;
      }
      return uVar1;
    }
    if (baud_BT8D_values[index].baud == baud) break;
    index = index + 1;
  }
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x400,"get bt8d %d\n",(uint)baud_BT8D_values[index].bt8d);
    _applog(3,tmp42,false);
  }
  return baud_BT8D_values[index].bt8d;
}


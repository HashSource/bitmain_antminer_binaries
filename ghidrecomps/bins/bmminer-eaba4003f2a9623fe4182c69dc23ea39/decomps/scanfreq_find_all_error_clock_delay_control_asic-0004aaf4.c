
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void scanfreq_find_all_error_clock_delay_control_asic(void)

{
  bool bVar1;
  uint uVar2;
  char tmp42 [2048];
  int asic_id;
  _Bool asic_error;
  int asic;
  int m;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_4_ = s_find_all_clock_delay_error_chips_000786ac._0_4_;
    tmp42._4_4_ = s_find_all_clock_delay_error_chips_000786ac._4_4_;
    tmp42._8_4_ = s_find_all_clock_delay_error_chips_000786ac._8_4_;
    tmp42._12_4_ = s_find_all_clock_delay_error_chips_000786ac._12_4_;
    tmp42._16_4_ = s_find_all_clock_delay_error_chips_000786ac._16_4_;
    tmp42._20_4_ = s_find_all_clock_delay_error_chips_000786ac._20_4_;
    tmp42._24_4_ = s_find_all_clock_delay_error_chips_000786ac._24_4_;
    tmp42._28_4_ = s_find_all_clock_delay_error_chips_000786ac._28_4_;
    tmp42[32] = (char)ram0x000786cc;
    _applog(5,tmp42,false);
  }
  memset(clock_delay_control_error_asic,0,0x1000);
  memset(clock_delay_control_error_asic_num,0,0x40);
  memset(clock_delay_control_error_core,0,0x100000);
  memset(clock_delay_control_error_core_num,0,0x1000);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (asic = 0; asic < scanfreq_info.AsicNum; asic = asic + 1) {
        bVar1 = false;
        for (m = 0; m < 0xd0; m = m + 1) {
          if (core_hash_clock_delay_control[chain][asic][m] != '\n') {
            clock_delay_control_error_core[chain][asic]
            [clock_delay_control_error_core_num[chain][asic]] = (uchar)m;
            clock_delay_control_error_core_num[chain][asic] =
                 clock_delay_control_error_core_num[chain][asic] + '\x01';
            bVar1 = true;
          }
        }
        if (bVar1) {
          clock_delay_control_error_asic[chain][clock_delay_control_error_asic_num[chain]] =
               (uchar)asic;
          clock_delay_control_error_asic_num[chain] = clock_delay_control_error_asic_num[chain] + 1;
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"chain %d has %d error chips",chain,
                 clock_delay_control_error_asic_num[chain]);
        _applog(5,tmp42,false);
      }
      for (asic = 0; asic < clock_delay_control_error_asic_num[chain]; asic = asic + 1) {
        uVar2 = (uint)clock_delay_control_error_asic[chain][asic];
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"chip %d has %d error cores",uVar2,
                   (uint)clock_delay_control_error_core_num[chain][uVar2]);
          _applog(5,tmp42,false);
        }
        for (m = 0; m < (int)(uint)clock_delay_control_error_core_num[chain][uVar2]; m = m + 1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"core[%d]",(uint)clock_delay_control_error_core[chain][uVar2][m]);
            _applog(5,tmp42,false);
          }
        }
      }
    }
  }
  return;
}


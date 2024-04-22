
/* WARNING: Unknown calling convention */

void scanfreq_rewrite_error_clock_delay_control_asic(void)

{
  byte bVar1;
  uchar chain_00;
  char tmp42 [2048];
  int asic_id;
  int core;
  int asic;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42._0_4_ = s_rewrite_all_clock_delay_error_ch_00078714._0_4_;
    tmp42._4_4_ = s_rewrite_all_clock_delay_error_ch_00078714._4_4_;
    tmp42._8_4_ = s_rewrite_all_clock_delay_error_ch_00078714._8_4_;
    tmp42._12_4_ = s_rewrite_all_clock_delay_error_ch_00078714._12_4_;
    tmp42._16_4_ = s_rewrite_all_clock_delay_error_ch_00078714._16_4_;
    tmp42._20_4_ = s_rewrite_all_clock_delay_error_ch_00078714._20_4_;
    tmp42._24_4_ = s_rewrite_all_clock_delay_error_ch_00078714._24_4_;
    tmp42._28_4_ = s_rewrite_all_clock_delay_error_ch_00078714._28_4_;
    tmp42._32_4_ = s_rewrite_all_clock_delay_error_ch_00078714._32_4_;
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (clock_delay_control_error_asic_num[chain] != 0)) {
      for (asic = 0; asic < clock_delay_control_error_asic_num[chain]; asic = asic + 1) {
        bVar1 = clock_delay_control_error_asic[chain][asic];
        for (core = 0; core < (int)(uint)clock_delay_control_error_core_num[chain][bVar1];
            core = core + 1) {
          chain_00 = (uchar)chain;
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
          usleep(10000);
          rewrite_clock_delay_control
                    (chain_00,bVar1 << 1,clock_delay_control_error_core[chain][bVar1][core],'\n');
        }
      }
    }
  }
  return;
}


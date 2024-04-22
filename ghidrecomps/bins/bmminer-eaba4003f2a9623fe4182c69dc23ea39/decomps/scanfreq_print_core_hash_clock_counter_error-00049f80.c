
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void scanfreq_print_core_hash_clock_counter_error(void)

{
  bool bVar1;
  char tmp42 [2048];
  int error_asic [256];
  int clock_counter;
  _Bool print_asic;
  int error_num;
  int i;
  int error;
  int asic;
  int m;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"----------- hash clock counter Error Info -----------\n",chain);
    _applog(5,tmp42,false);
  }
  g_logfile_no_datetime = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      error_num = 0;
      clock_counter = (freq_pll_1393[freq_one_board[chain]].freq << 4) / 100;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"--- Chain[%d] ---\n",chain);
        _applog(5,tmp42,false);
      }
      for (asic = 0; asic < scanfreq_info.AsicNum; asic = asic + 1) {
        bVar1 = false;
        error = 0;
        for (m = 0; m < 0xd0; m = m + 1) {
          if ((((core_hash_clock_counter[chain][asic][m] & 0xffU) != 0xff) &&
              ((core_hash_clock_counter[chain][asic][m] & 0xffU) != clock_counter)) &&
             (((core_hash_clock_counter[chain][asic][m] & 0xffU) != clock_counter + 1U &&
              ((core_hash_clock_counter[chain][asic][m] & 0xffU) != clock_counter - 1U)))) {
            if (!bVar1) {
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,"--- ASIC[%d] error clock counter ---\n",asic);
                _applog(5,tmp42,false);
              }
              bVar1 = true;
            }
            error = error + 1;
            if (((error & 7U) == 0) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              tmp42[0] = '\n';
              tmp42[1] = '\0';
              _applog(5,tmp42,false);
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"CORE[%03d]=%02x ",m,
                       core_hash_clock_counter[chain][asic][m] & 0xff);
              _applog(5,tmp42,false);
            }
          }
        }
        if (0 < error) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = '\n';
            tmp42[1] = '\0';
            _applog(5,tmp42,false);
          }
          error_asic[error_num] = asic;
          error_num = error_num + 1;
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"--- ASIC[%d] all clock counter ---\n",asic);
            _applog(5,tmp42,false);
          }
          for (m = 0; m < 0xd0; m = m + 1) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"CORE[%03d]=%02x ",m,
                       core_hash_clock_counter[chain][asic][m] & 0xff);
              _applog(5,tmp42,false);
            }
            if (((m + 1U & 7) == 0) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              tmp42[0] = '\n';
              tmp42[1] = '\0';
              _applog(5,tmp42,false);
            }
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = '\n';
            tmp42[1] = '\0';
            _applog(5,tmp42,false);
          }
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42._0_3_ = (undefined3)DAT_0007854c;
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_hash_clock_counter_0_chips__000785e8[0];
        tmp42[1] = s_hash_clock_counter_0_chips__000785e8[1];
        tmp42[2] = s_hash_clock_counter_0_chips__000785e8[2];
        tmp42[3] = s_hash_clock_counter_0_chips__000785e8[3];
        tmp42[4] = s_hash_clock_counter_0_chips__000785e8[4];
        tmp42[5] = s_hash_clock_counter_0_chips__000785e8[5];
        tmp42[6] = s_hash_clock_counter_0_chips__000785e8[6];
        tmp42[7] = s_hash_clock_counter_0_chips__000785e8[7];
        tmp42[8] = s_hash_clock_counter_0_chips__000785e8[8];
        tmp42[9] = s_hash_clock_counter_0_chips__000785e8[9];
        tmp42[10] = s_hash_clock_counter_0_chips__000785e8[10];
        tmp42[11] = s_hash_clock_counter_0_chips__000785e8[11];
        tmp42[12] = s_hash_clock_counter_0_chips__000785e8[12];
        tmp42[13] = s_hash_clock_counter_0_chips__000785e8[13];
        tmp42[14] = s_hash_clock_counter_0_chips__000785e8[14];
        tmp42[15] = s_hash_clock_counter_0_chips__000785e8[15];
        tmp42[16] = s_hash_clock_counter_0_chips__000785e8[16];
        tmp42[17] = s_hash_clock_counter_0_chips__000785e8[17];
        tmp42[18] = s_hash_clock_counter_0_chips__000785e8[18];
        tmp42[19] = s_hash_clock_counter_0_chips__000785e8[19];
        tmp42[20] = s_hash_clock_counter_0_chips__000785e8[20];
        tmp42[21] = s_hash_clock_counter_0_chips__000785e8[21];
        tmp42[22] = s_hash_clock_counter_0_chips__000785e8[22];
        tmp42[23] = s_hash_clock_counter_0_chips__000785e8[23];
        tmp42[24] = s_hash_clock_counter_0_chips__000785e8[24];
        tmp42[25] = s_hash_clock_counter_0_chips__000785e8[25];
        tmp42[26] = s_hash_clock_counter_0_chips__000785e8[26];
        tmp42[27] = s_hash_clock_counter_0_chips__000785e8[27];
        tmp42[28] = (char)ram0x00078604;
        _applog(5,tmp42,false);
      }
      for (i = 0; i < error_num; i = i + 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"%02d ",error_asic[i]);
          _applog(5,tmp42,false);
        }
        if (((i + 1U & 7) == 0) &&
           (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
          tmp42[0] = '\n';
          tmp42[1] = '\0';
          _applog(5,tmp42,false);
        }
      }
    }
  }
  g_logfile_no_datetime = false;
  return;
}


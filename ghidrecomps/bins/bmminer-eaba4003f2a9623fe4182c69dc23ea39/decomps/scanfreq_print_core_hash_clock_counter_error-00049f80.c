
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scanfreq_print_core_hash_clock_counter_error(void)

{
  uint uVar1;
  bool bVar2;
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
      uVar1 = (freq_pll_1393[freq_one_board[chain]].freq << 4) / 100;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"--- Chain[%d] ---\n",chain);
        _applog(5,tmp42,false);
      }
      for (asic = 0; asic < scanfreq_info.AsicNum; asic = asic + 1) {
        bVar2 = false;
        error = 0;
        for (m = 0; m < 0xd0; m = m + 1) {
          if ((((core_hash_clock_counter[chain][asic][m] & 0xffU) != 0xff) &&
              ((core_hash_clock_counter[chain][asic][m] & 0xffU) != uVar1)) &&
             (((core_hash_clock_counter[chain][asic][m] & 0xffU) != uVar1 + 1 &&
              ((core_hash_clock_counter[chain][asic][m] & 0xffU) != uVar1 - 1)))) {
            if (!bVar2) {
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,"--- ASIC[%d] error clock counter ---\n",asic);
                _applog(5,tmp42,false);
              }
              bVar2 = true;
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
        tmp42[0] = '\n';
        tmp42[1] = '\n';
        tmp42[2] = '\0';
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"hash_clock_counter=0 chips:\n",0x1c);
        tmp42[0x1c] = '\0';
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


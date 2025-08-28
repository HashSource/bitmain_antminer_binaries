
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scanfreq_print_core_clock_delay_control_error(void)

{
  bool bVar1;
  char tmp42 [2048];
  int error_asic [256];
  int cc;
  _Bool print_asic;
  int error_num;
  int i;
  int error;
  int asic;
  int m;
  int chain;
  
  cc = 0x14;
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"----------- clock delay control Error Info -----------\n",chain);
    _applog(5,tmp42,false);
  }
  g_logfile_no_datetime = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      error_num = 0;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"--- Chain[%d] ---\n",chain);
        _applog(5,tmp42,false);
      }
      for (asic = 0; asic < scanfreq_info.AsicNum; asic = asic + 1) {
        bVar1 = false;
        error = 0;
        for (m = 0; m < 0xd0; m = m + 1) {
          cc = cc + 1;
          if ((cc < 10) &&
             (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
            snprintf(tmp42,0x800,"CORE[%03d]=%02x \n",m,
                     (uint)core_hash_clock_delay_control[chain][asic][m]);
            _applog(5,tmp42,false);
          }
          if (core_hash_clock_delay_control[chain][asic][m] != '\n') {
            if (!bVar1) {
              if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                snprintf(tmp42,0x800,"--- ASIC[%d] clock delay control error ---\n",asic);
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
                       (uint)core_hash_clock_delay_control[chain][asic][m]);
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
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = '\n';
        tmp42[1] = '\n';
        tmp42[2] = '\0';
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"clock delay control error chips:",0x20);
        tmp42[0x20] = '\n';
        tmp42[0x21] = '\0';
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


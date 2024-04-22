
/* WARNING: Unknown calling convention */

void scanfreq_print_core_hash_clock_counter(void)

{
  char tmp42 [2048];
  int m;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"----------- Chip 0 hash clock counter -----------\n",chain);
    _applog(5,tmp42,false);
  }
  g_logfile_no_datetime = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"--- Chain[%d] ---\n",chain);
        _applog(5,tmp42,false);
      }
      for (m = 0; m < 0xd0; m = m + 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"CORE[%03d]=%08x ",m,core_hash_clock_counter[chain][0][m]);
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
        tmp42._0_2_ = (undefined2)DAT_0007854c;
        tmp42[2] = (char)((uint)DAT_0007854c >> 0x10);
        _applog(5,tmp42,false);
      }
    }
  }
  g_logfile_no_datetime = false;
  return;
}


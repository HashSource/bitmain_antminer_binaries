
/* WARNING: Unknown calling convention */

void scanfreq_print_nonce_zero_core_chip(void)

{
  char tmp42 [2048];
  int m;
  int chain;
  int i;
  
  g_logfile_no_datetime = true;
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"-----------Chips have 0 nonce cores  -----------\n",chain);
    _applog(5,tmp42,false);
  }
  chain = 0;
  do {
    if (0xf < chain) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = '\n';
        tmp42[1] = '\n';
        tmp42[2] = '\n';
        tmp42[3] = '\0';
        _applog(5,tmp42,false);
      }
      g_logfile_no_datetime = false;
      return;
    }
    if (dev->chain_exist[chain] != 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Chain[%d]\n",chain);
        _applog(5,tmp42,false);
      }
      for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
        for (m = 0; m < 0xd0; m = m + 1) {
          if (scanfreq_info.asic_core_nonce_num[chain][i][m] == 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              snprintf(tmp42,0x800,"asic[%d] ",i);
              _applog(5,tmp42,false);
            }
            break;
          }
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = '\n';
        tmp42[1] = '\0';
        _applog(5,tmp42,false);
      }
    }
    chain = chain + 1;
  } while( true );
}


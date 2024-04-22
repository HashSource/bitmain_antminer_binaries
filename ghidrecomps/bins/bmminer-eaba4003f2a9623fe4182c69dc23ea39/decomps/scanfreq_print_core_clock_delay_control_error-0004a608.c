
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

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
        tmp42._0_3_ = (undefined3)DAT_0007854c;
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_clock_delay_control_error_chips__00078688[0];
        tmp42[1] = s_clock_delay_control_error_chips__00078688[1];
        tmp42[2] = s_clock_delay_control_error_chips__00078688[2];
        tmp42[3] = s_clock_delay_control_error_chips__00078688[3];
        tmp42[4] = s_clock_delay_control_error_chips__00078688[4];
        tmp42[5] = s_clock_delay_control_error_chips__00078688[5];
        tmp42[6] = s_clock_delay_control_error_chips__00078688[6];
        tmp42[7] = s_clock_delay_control_error_chips__00078688[7];
        tmp42[8] = s_clock_delay_control_error_chips__00078688[8];
        tmp42[9] = s_clock_delay_control_error_chips__00078688[9];
        tmp42[10] = s_clock_delay_control_error_chips__00078688[10];
        tmp42[11] = s_clock_delay_control_error_chips__00078688[11];
        tmp42[12] = s_clock_delay_control_error_chips__00078688[12];
        tmp42[13] = s_clock_delay_control_error_chips__00078688[13];
        tmp42[14] = s_clock_delay_control_error_chips__00078688[14];
        tmp42[15] = s_clock_delay_control_error_chips__00078688[15];
        tmp42[16] = s_clock_delay_control_error_chips__00078688[16];
        tmp42[17] = s_clock_delay_control_error_chips__00078688[17];
        tmp42[18] = s_clock_delay_control_error_chips__00078688[18];
        tmp42[19] = s_clock_delay_control_error_chips__00078688[19];
        tmp42[20] = s_clock_delay_control_error_chips__00078688[20];
        tmp42[21] = s_clock_delay_control_error_chips__00078688[21];
        tmp42[22] = s_clock_delay_control_error_chips__00078688[22];
        tmp42[23] = s_clock_delay_control_error_chips__00078688[23];
        tmp42[24] = s_clock_delay_control_error_chips__00078688[24];
        tmp42[25] = s_clock_delay_control_error_chips__00078688[25];
        tmp42[26] = s_clock_delay_control_error_chips__00078688[26];
        tmp42[27] = s_clock_delay_control_error_chips__00078688[27];
        tmp42[28] = s_clock_delay_control_error_chips__00078688[28];
        tmp42[29] = s_clock_delay_control_error_chips__00078688[29];
        tmp42[30] = s_clock_delay_control_error_chips__00078688[30];
        tmp42[31] = s_clock_delay_control_error_chips__00078688[31];
        tmp42._32_2_ = (undefined2)ram0x000786a8;
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


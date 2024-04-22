
void scanfreq_print_bad_chip(int chain)

{
  int iVar1;
  int chain_local;
  char tmp42 [2048];
  int n;
  int bad_chips;
  int bad_core;
  int m;
  int i;
  
  iVar1 = scanfreq_info.AsicWorkCount / 0xd0;
  g_logfile_no_datetime = true;
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"-----------Chips not return all nonce -----------\n",chain);
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"------------------ Chain[%d] ------------------\n",chain);
    _applog(5,tmp42,false);
  }
  for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
    if (scanfreq_info.asic_nonce_num[chain][i] < scanfreq_info.AsicWorkCount) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"asic[%02d]=%02d\n",i,scanfreq_info.asic_nonce_num[chain][i]);
        _applog(5,tmp42,false);
      }
      bad_core = 0;
      for (m = 0; m < 0xd0; m = m + 1) {
        if (scanfreq_info.asic_core_nonce_num[chain][i][m] != iVar1) {
          bad_core = bad_core + 1;
          if (((bad_core & 7U) == 0) &&
             (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
            tmp42[0] = '\n';
            tmp42[1] = '\0';
            _applog(5,tmp42,false);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"CORE[%03d]=%02d ",m,scanfreq_info.asic_core_nonce_num[chain][i][m]
                    );
            _applog(5,tmp42,false);
          }
        }
      }
      if ((0 < bad_core) &&
         (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
        tmp42._0_3_ = (undefined3)DAT_0007854c;
        _applog(5,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_nonce_<_180_chips:_000787c8[0];
    tmp42[1] = s_nonce_<_180_chips:_000787c8[1];
    tmp42[2] = s_nonce_<_180_chips:_000787c8[2];
    tmp42[3] = s_nonce_<_180_chips:_000787c8[3];
    tmp42[4] = s_nonce_<_180_chips:_000787c8[4];
    tmp42[5] = s_nonce_<_180_chips:_000787c8[5];
    tmp42[6] = s_nonce_<_180_chips:_000787c8[6];
    tmp42[7] = s_nonce_<_180_chips:_000787c8[7];
    tmp42[8] = s_nonce_<_180_chips:_000787c8[8];
    tmp42[9] = s_nonce_<_180_chips:_000787c8[9];
    tmp42[10] = s_nonce_<_180_chips:_000787c8[10];
    tmp42[11] = s_nonce_<_180_chips:_000787c8[11];
    tmp42[12] = s_nonce_<_180_chips:_000787c8[12];
    tmp42[13] = s_nonce_<_180_chips:_000787c8[13];
    tmp42[14] = s_nonce_<_180_chips:_000787c8[14];
    tmp42[15] = s_nonce_<_180_chips:_000787c8[15];
    tmp42[16] = s_nonce_<_180_chips:_000787c8[16];
    tmp42[17] = s_nonce_<_180_chips:_000787c8[17];
    tmp42[18] = s_nonce_<_180_chips:_000787c8[18];
    tmp42[19] = s_nonce_<_180_chips:_000787c8[19];
    _applog(5,tmp42,false);
  }
  bad_chips = 0;
  for (i = 0; i < scanfreq_info.AsicNum; i = i + 1) {
    if (scanfreq_info.asic_nonce_num[chain][i] < 0xb4) {
      bad_chips = bad_chips + 1;
      if (((bad_chips & 7U) == 0) &&
         (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
        tmp42[0] = '\n';
        tmp42[1] = '\0';
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%02d ",i);
        _applog(5,tmp42,false);
      }
    }
  }
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


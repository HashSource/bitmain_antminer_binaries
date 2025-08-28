
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scanfreq_finish(void)

{
  int iVar1;
  char tmp42 [2048];
  int index;
  float volt;
  int i;
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    tmp42[0] = '\n';
    tmp42[1] = '\n';
    tmp42[2] = '\0';
    _applog(5,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"     ********** Scan Result **********\n",0x28);
    _applog(5,tmp42,false);
  }
  scanfreq_info.all_chain_scan_success = true;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = getVolValueFromPICvoltage((uchar)scanfreq_info.scan_pic_voltage[chain]);
      if (scanfreq_info.scan_success[chain] == false) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"******Chain[%d] Failed, voltage=%.1fV  **********",chain,
                   (double)((float)(longlong)iVar1 / 100.0));
          _applog(5,tmp42,false);
        }
        scanfreq_info.all_chain_scan_success = false;
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,
                 "******Chain[%d] Success, Freq=%dM, voltage=%.1fV, NonceRate=%.1f**********",chain,
                 freq_pll_1393[scanfreq_info.scan_index[scanfreq_info.pass_freq_index[chain]]].freq)
        ;
        _applog(5,tmp42,false);
      }
      for (i = 0; i < scanfreq_info.scan_record_count[chain]; i = i + 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"%d. No=%d, Freq=%dM, NonceRate=%.1f%%",i + 1,
                   scanfreq_info.scan_freq_index_record[chain][i],
                   freq_pll_1393
                   [scanfreq_info.scan_index[scanfreq_info.scan_freq_index_record[chain][i]]].freq,
                   (double)scanfreq_info.scan_noncerate_record[chain][i]);
          _applog(5,tmp42,false);
        }
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = '\n';
        tmp42[1] = '\n';
        tmp42[2] = '\0';
        _applog(5,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"read clock delay control after test pattern ",0x2c);
    tmp42[0x2c] = '\n';
    tmp42[0x2d] = '\0';
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      dsPIC33EP16GS202_enable_pic_dc_dc((uchar)chain,'\0');
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    }
  }
  pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
  pthread_cancel(receive_id);
  pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
  return;
}


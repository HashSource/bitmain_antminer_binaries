
/* WARNING: Unknown calling convention */

int scanfreq_print_nonce_info(void)

{
  uint uVar1;
  char *str;
  char tmp42 [2048];
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] != 0) && (scanfreq_info.scan_finished[i] == false)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"-------------Chain[%d]-----------\n",i);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"total send work       : %d\n",scanfreq_info.send_work_num[i]);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"require nonce of chain: %d\n",scanfreq_info.RequiredChainNonce);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"received valid nonce  : %d\n",scanfreq_info.valid_nonce_num[i]);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"repeated nonce     : %d\n",scanfreq_info.repeated_nonce_num[i]);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"hw nonce           : %d\n",scanfreq_info.HW_nonce_num[i]);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"other error nonce  : %d\n",scanfreq_info.other_nonce_num[i]);
        _applog(5,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"total receive nonce: %d\n\n",scanfreq_info.ret_nonce_num[i]);
        _applog(5,tmp42,false);
      }
      scanfreq_print_bad_chip(i);
    }
  }
  scanfreq_print_nonce_zero_core_chip();
  if (((use_syslog != false) || (opt_log_output != false)) ||
     (str = (char *)opt_log_level, 4 < opt_log_level)) {
    uVar1 = get_crc_count();
    snprintf(tmp42,0x800,"CRC error counter=%d\n",uVar1);
    str = tmp42;
    _applog(5,str,false);
  }
  return (int)str;
}


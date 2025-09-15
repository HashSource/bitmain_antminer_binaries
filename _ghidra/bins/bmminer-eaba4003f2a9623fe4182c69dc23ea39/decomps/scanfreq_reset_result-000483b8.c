
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scanfreq_reset_result(void)

{
  char tmp42 [2048];
  int chain;
  
  if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"scanfreq_reset_resul",0x14);
    tmp42[0x14] = 't';
    tmp42[0x15] = '\0';
    _applog(5,tmp42,false);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      memset(scanfreq_info.asic_nonce_num + chain,0,0x400);
      memset(scanfreq_info.asic_core_nonce_num + chain,0,0x40000);
      scanfreq_info.send_work_num[chain] = 0;
      scanfreq_info.ret_nonce_num[chain] = 0;
      scanfreq_info.repeated_nonce_num[chain] = 0;
      scanfreq_info.other_nonce_num[chain] = 0;
      scanfreq_info.HW_nonce_num[chain] = 0;
      scanfreq_info.valid_nonce_num[chain] = 0;
      clear_nonce_return_back_flag(chain);
    }
  }
  return;
}



/* WARNING: Unknown calling convention */

void scanfreq_check_result(void)

{
  float fVar1;
  char tmp42 [2048];
  float nonce_rate;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.scan_finished[chain] == false)) {
      fVar1 = ((float)(longlong)scanfreq_info.valid_nonce_num[chain] /
              (float)(longlong)scanfreq_info.RequiredChainNonce) * DAT_0004c070;
      if (fVar1 < scanfreq_info.PassNonceRate) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"********** Chain[%d] is failed, freq=%d, nonce_rate=%f **********\n"
                   ,chain,freq_pll_1393[freq_one_board[chain]].freq);
          _applog(5,tmp42,false);
        }
        scanfreq_info.current_is_pass[chain] = false;
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"********** Chain[%d] is pass, freq=%d, nonce_rate=%f **********\n",
                   chain,freq_pll_1393[freq_one_board[chain]].freq);
          _applog(5,tmp42,false);
        }
        scanfreq_info.current_is_pass[chain] = true;
        scanfreq_info.scan_success[chain] = true;
        scanfreq_info.pass_freq_index[chain] = scanfreq_info.current_index[chain];
        scanfreq_info.pass_noncerate[chain] = fVar1;
      }
      scanfreq_info.scan_freq_index_record[chain][scanfreq_info.scan_record_count[chain]] =
           scanfreq_info.current_index[chain];
      scanfreq_info.scan_noncerate_record[chain][scanfreq_info.scan_record_count[chain]] = fVar1;
      scanfreq_info.scan_record_count[chain] = scanfreq_info.scan_record_count[chain] + 1;
    }
  }
  return;
}


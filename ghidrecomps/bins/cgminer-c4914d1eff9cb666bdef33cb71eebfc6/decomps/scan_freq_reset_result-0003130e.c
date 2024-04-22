
/* WARNING: Unknown calling convention */

void scan_freq_reset_result(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      memset(scanfreq_info.asic_nonce_num + chain,0,0x400);
      memset(scanfreq_info.asic_core_nonce_num + chain,0,0x40000);
      scanfreq_info.send_work_num[chain] = 0;
      scanfreq_info.ret_nonce_num[chain] = 0;
      scanfreq_info.repeated_nonce_num[chain] = 0;
      scanfreq_info.other_nonce_num[chain] = 0;
      scanfreq_info.HW_nonce_num[chain] = 0;
      scanfreq_info.valid_nonce_num[chain] = 0;
      san_freq_clear_nonce_return_back_flag(chain);
    }
  }
  return;
}


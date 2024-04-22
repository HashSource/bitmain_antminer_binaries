
void freq_tuning_send_work_and_check_result_all_chain(freq_tuning_info *freq_info)

{
  uint uVar1;
  freq_tuning_info *freq_info_local;
  int hw_count_threshold_for_test_done;
  int nonce_count_threshold_for_test_done;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] == false)) &&
       (freq_info->fake_done[chain] == false)) {
      chain_ValidNonce[chain] = 0x7e00;
    }
  }
  if (gBegin_get_nonce != true) {
    uVar1 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar1 | 0x10000);
    gBegin_get_nonce = true;
  }
  freq_tuning_send_work(freq_info);
  freq_tuning_wait_recv_nonce(freq_info);
  gBegin_get_nonce = false;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (freq_info->test_done[chain] == false)) &&
       (freq_info->fake_done[chain] == false)) {
      freq_tuning_init_chip_rate_table(freq_info,asic_nonce_num[chain],chain);
      if ((valid_nonce_num[chain] <
           (int)(longlong)((double)(longlong)chain_ValidNonce[chain] * DAT_00016a90)) ||
         ((int)(longlong)((double)(longlong)chain_ValidNonce[chain] * DAT_00016a98) <
          chain_hw_num[chain])) {
        freq_info->test_done[chain] = true;
      }
    }
  }
  return;
}


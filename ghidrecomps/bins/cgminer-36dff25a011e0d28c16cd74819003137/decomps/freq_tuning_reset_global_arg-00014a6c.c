
/* WARNING: Unknown calling convention */

void freq_tuning_reset_global_arg(void)

{
  memset(asic_nonce_num,0,0x2000);
  memset(asic_core_nonce_num,0,0x800000);
  memset(err_nonce_num,0,0x40);
  memset(repeated_nonce_num,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(send_work_num,0,0x40);
  memset(g_pattern_status,0,0x7e000);
  memset(extra_nonce_num,0,0x40);
  memset(crc_err_nonce_num,0,0x40);
  memset(invalid_nonce_num,0,0x40);
  memset(err_nonce_num,0,0x40);
  memset(chain_hw_num,0,0x40);
  memset(g_work_for_hw_check,0,0x1a000);
  chain_invalid_num = 0;
  asic_invalid_num = 0;
  nonce_recv_num_all._0_4_ = 0;
  nonce_recv_num_all._4_4_ = 0;
  return;
}



void reset_nonce_arg(void)

{
  memset(asic_nonce_num,0,0x4000);
  memset(asic_core_nonce_num,0,0x400000);
  memset(repeated_nonce_id,0xff,0x4000);
  memset(err_nonce_num,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(repeated_nonce_num,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(send_work_num,0,0x40);
  total_valid_nonce_num = 0;
  return;
}


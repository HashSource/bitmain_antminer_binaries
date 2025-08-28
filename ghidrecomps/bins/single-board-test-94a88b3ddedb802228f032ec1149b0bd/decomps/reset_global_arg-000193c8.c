
void reset_global_arg(void)

{
  char cVar1;
  int local_c;
  
  memset(asic_nonce_num,0,0x4000);
  memset(asic_core_nonce_num,0,0x400000);
  memset(repeated_nonce_id,0xff,0x4000);
  memset(err_nonce_num,0,0x40);
  memset(last_nonce_num,0,0x40);
  memset(repeated_nonce_num,0,0x40);
  memset(valid_nonce_num,0,0x40);
  memset(send_work_num,0,0x40);
  total_valid_nonce_num = 0;
  gName_len = 0;
  cVar1 = is_S9_Hydro();
  if (cVar1 != '\x01') {
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      cgpu[local_c + 0x271924] = 0;
    }
  }
  cgpu[0x271934] = 0x80;
  cgpu[0x27195f] = conf[0x7c];
  cgpu[0x271960] = conf[0x7c];
  cgpu[0x271961] = conf[0x7c];
  cgpu[0x271962] = conf[0x7c];
  return;
}


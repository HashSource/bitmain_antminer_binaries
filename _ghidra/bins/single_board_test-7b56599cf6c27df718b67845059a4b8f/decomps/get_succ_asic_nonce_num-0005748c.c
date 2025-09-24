
void get_succ_asic_nonce_num(uint16_t *data,int len)

{
  int len_local;
  uint16_t *data_local;
  int i;
  int max_len;
  
  max_len = 0x6c;
  if (len < 0x6c) {
    max_len = len;
  }
  for (i = 0; i < max_len; i = i + 1) {
    data[i] = g_rt.last_succ_asic_nonce_num[i];
  }
  return;
}


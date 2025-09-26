
void hmac_sha256(uint8_t *out,uint8_t *data,size_t data_len,uint8_t *key,size_t key_len)

{
  uint8_t *key_local;
  size_t data_len_local;
  uint8_t *data_local;
  uint8_t *out_local;
  uint8_t kx [64];
  uint8_t kh [32];
  sha2_context ss;
  size_t i_3;
  size_t i_2;
  size_t i_1;
  size_t i;
  
  if (((out != (uint8_t *)0x0) && (data != (uint8_t *)0x0)) && (key != (uint8_t *)0x0)) {
    key_local = key;
    if (0x40 < key_len) {
      sha2_starts(&ss);
      sha2_update(&ss,key,key_len);
      sha2_finish(&ss,kh);
      key_len = 0x20;
      key_local = kh;
    }
    for (i = 0; i < key_len; i = i + 1) {
      kx[i] = key_local[i] ^ 0x36;
    }
    for (i_1 = key_len; i_1 < 0x40; i_1 = i_1 + 1) {
      kx[i_1] = '6';
    }
    sha2_starts(&ss);
    sha2_update(&ss,kx,0x40);
    sha2_update(&ss,data,data_len);
    sha2_finish(&ss,out);
    for (i_2 = 0; i_2 < key_len; i_2 = i_2 + 1) {
      kx[i_2] = key_local[i_2] ^ 0x5c;
    }
    for (i_3 = key_len; i_3 < 0x40; i_3 = i_3 + 1) {
      kx[i_3] = '\\';
    }
    sha2_starts(&ss);
    sha2_update(&ss,kx,0x40);
    sha2_update(&ss,out,0x20);
    sha2_finish(&ss,out);
  }
  return;
}


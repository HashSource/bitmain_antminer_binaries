
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void scan_freq_stop_hash_board(void)

{
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      disable_pic_dac((uint8_t)i);
    }
  }
  return;
}


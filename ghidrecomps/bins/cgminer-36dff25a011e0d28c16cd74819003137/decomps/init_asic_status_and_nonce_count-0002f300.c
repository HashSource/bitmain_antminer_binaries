
/* WARNING: Unknown calling convention */

void init_asic_status_and_nonce_count(void)

{
  uint64_t *puVar1;
  int offset;
  int y;
  int x;
  
  for (x = 0; x < 0x10; x = x + 1) {
    if (dev->chain_exist[x] != 0) {
      offset = 0;
      for (y = 0; y < (int)(uint)dev->chain_asic_num[x]; y = y + 1) {
        if ((y & 7U) == 0) {
          dev->chain_asic_status_string[x][y + offset] = ' ';
          offset = offset + 1;
        }
        dev->chain_asic_status_string[x][y + offset] = 'o';
        puVar1 = dev->chain_asic_nonce[x] + y;
        *(undefined4 *)puVar1 = 0;
        *(undefined4 *)((int)puVar1 + 4) = 0;
      }
      dev->chain_asic_status_string[x][y + offset] = '\0';
    }
  }
  return;
}



void power_off_hash_board(int chain)

{
  int chain_local;
  int i;
  
  if (chain == (uint)All_Chain) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] != 0) {
        hashboard_power_off((uint8_t)i);
      }
    }
  }
  else {
    hashboard_power_off((uint8_t)chain);
  }
  sleep(3);
  return;
}


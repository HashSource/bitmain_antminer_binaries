
/* WARNING: Unknown calling convention */

void hash_board_power_on_with_reset(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      set_reset_hashboard(chain,1);
      sleep(3);
      hashboard_power_on((uint8_t)chain);
      sleep(2);
      set_reset_hashboard(chain,0);
      sleep(3);
    }
  }
  return;
}


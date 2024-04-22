
/* WARNING: Unknown calling convention */

int get_ideal_hash_rate_max(void)

{
  int iVar1;
  int total_rate;
  int chain;
  
  total_rate = 0;
  if (freq_mode == 2) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        total_rate = (int)((float)(longlong)total_rate +
                          freq_from_board[chain] * DAT_00025108 * DAT_0002510c);
      }
    }
    iVar1 = total_rate / 1000;
  }
  else {
    iVar1 = g_ideal_hashrate_max;
    if (g_ideal_hashrate_max == 0) {
      iVar1 = do_get_ideal_max_hash_rate();
      g_ideal_hashrate_max = iVar1;
    }
  }
  return iVar1;
}


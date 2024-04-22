
/* WARNING: Unknown calling convention */

int get_total_rate(void)

{
  int iVar1;
  int total_rate;
  int chain;
  
  total_rate = 0;
  if (freq_mode == 2) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        total_rate = (int)((float)(longlong)total_rate +
                          freq_from_board[chain] * DAT_00024d8c * DAT_00024d90);
      }
    }
    iVar1 = total_rate / 1000;
  }
  else {
    iVar1 = g_total_hashrate;
    if (g_total_hashrate == 0) {
      iVar1 = get_fixed_total_hash_rate();
      g_total_hashrate = iVar1;
    }
  }
  return iVar1;
}


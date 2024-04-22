
/* WARNING: Unknown calling convention */

int GetTotalRate(void)

{
  int iVar1;
  int total_rate;
  int chain;
  
  total_rate = 0;
  iVar1 = g_total_fixed_hashrate;
  if (freq_mode == 2) {
    for (chain = 0; chain < 8; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        total_rate = (int)((float)(longlong)total_rate +
                          freq_from_board[chain] * DAT_0001c36c * DAT_0001c370);
      }
    }
    iVar1 = total_rate / 1000;
  }
  return iVar1;
}


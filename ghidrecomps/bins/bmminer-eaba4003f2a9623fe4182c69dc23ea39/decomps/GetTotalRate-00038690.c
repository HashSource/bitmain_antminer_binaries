
/* WARNING: Unknown calling convention */

int GetTotalRate(void)

{
  int totalrate;
  int j;
  int i;
  
  totalrate = 0;
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      for (j = 0; j < 0x6c; j = j + 1) {
        if (chain_badcore_num[i][j] < 0xf) {
          totalrate = totalrate +
                      (0xd0 - chain_badcore_num[i][j]) * freq_pll_1393[last_freq[i][j * 2 + 3]].freq
          ;
        }
      }
    }
  }
  return totalrate / 1000;
}


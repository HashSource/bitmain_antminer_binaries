
int GetBoardRate(int chainIndex)

{
  int chainIndex_local;
  int totalrate;
  int j;
  
  totalrate = 0;
  if (dev->chain_exist[chainIndex] == 1) {
    for (j = 0; j < 0x6c; j = j + 1) {
      if (chain_badcore_num[chainIndex][j] < 0xf) {
        totalrate = totalrate +
                    (0xd0 - chain_badcore_num[chainIndex][j]) *
                    freq_pll_1393[last_freq[chainIndex][j * 2 + 3]].freq;
      }
    }
  }
  return totalrate / 1000;
}


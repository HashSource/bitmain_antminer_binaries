
int getChainAsicTempBadCoreNum(int chainIndex,int asicIndex)

{
  int asicIndex_local;
  int chainIndex_local;
  int badcore;
  int m;
  
  badcore = 0;
  for (m = 0; m < 0xd0; m = m + 1) {
    if (scanfreq_info.asic_core_enabled_flag[chainIndex][asicIndex][m] < 1) {
      badcore = badcore + 1;
    }
  }
  return badcore;
}


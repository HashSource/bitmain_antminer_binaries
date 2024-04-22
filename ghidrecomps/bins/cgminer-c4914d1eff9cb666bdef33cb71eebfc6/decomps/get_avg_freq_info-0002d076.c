
void get_avg_freq_info(char *infoStr)

{
  int iVar1;
  char *infoStr_local;
  int retlen;
  int chain;
  
  retlen = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar1 = sprintf(infoStr + retlen,"%d ",scan_freq_average[chain]);
      retlen = retlen + iVar1;
    }
  }
  return;
}


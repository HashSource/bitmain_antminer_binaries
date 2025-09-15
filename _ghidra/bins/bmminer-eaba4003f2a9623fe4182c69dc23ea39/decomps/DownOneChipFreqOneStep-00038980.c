
/* WARNING: Unknown calling convention */

_Bool DownOneChipFreqOneStep(void)

{
  int iVar1;
  _Bool _Var2;
  char tmp42 [2048];
  char logstr [1024];
  int max_rate_chainIndex;
  int max_freq_chipIndex;
  int max_freq;
  int board_rate;
  int j;
  
  board_rate = 0;
  max_rate_chainIndex = -1;
  j = 0;
  do {
    if (0xf < j) {
      if (max_rate_chainIndex < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Fatal Error: DownOneChipFreqOneStep has Wrong chain index=%d\n",
                   max_rate_chainIndex);
          _applog(5,tmp42,false);
        }
        _Var2 = false;
      }
      else {
        max_freq = 0;
        max_freq_chipIndex = -1;
        for (j = 0; j < (int)(uint)dev->chain_asic_num[max_rate_chainIndex]; j = j + 1) {
          if ((chain_badcore_num[max_rate_chainIndex][j] < 0xf) &&
             ((max_freq == 0 || ((uint)max_freq < (uint)last_freq[max_rate_chainIndex][j * 2 + 3])))
             ) {
            max_freq_chipIndex = j;
            max_freq = (int)last_freq[max_rate_chainIndex][j * 2 + 3];
          }
        }
        if (max_freq_chipIndex < 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,
                     "Fatal Error: DownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n",
                     max_freq_chipIndex);
            _applog(5,tmp42,false);
          }
          _Var2 = false;
        }
        else if ((uint)max_freq < 5) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,
                     "Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n",
                     max_rate_chainIndex);
            _applog(5,tmp42,false);
          }
          _Var2 = false;
        }
        else {
          last_freq[max_rate_chainIndex][max_freq_chipIndex * 2 + 3] =
               last_freq[max_rate_chainIndex][max_freq_chipIndex * 2 + 3] + 0xff;
          _Var2 = true;
        }
      }
      return _Var2;
    }
    if (dev->chain_exist[j] == 1) {
      if (dev->chain_asic_num[j] != 'l') {
        return false;
      }
      if ((board_rate == 0) || (iVar1 = GetBoardRate(j), board_rate < iVar1)) {
        board_rate = GetBoardRate(j);
        max_rate_chainIndex = j;
      }
    }
    j = j + 1;
  } while( true );
}


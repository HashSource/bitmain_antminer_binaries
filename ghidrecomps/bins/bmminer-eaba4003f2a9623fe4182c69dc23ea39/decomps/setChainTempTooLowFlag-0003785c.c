
/* WARNING: Unknown calling convention */

void setChainTempTooLowFlag(void)

{
  char tmp42 [2048];
  char logstr [1024];
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    chain_temp_toolow[i] = 0;
    if ((dev->chain_exist[i] == 1) && (0 < dev->chain_asic_maxtemp[i][0])) {
      if (lowest_testOK_temp[i] < 1) {
        if (dev->chain_asic_maxtemp[i][0] < 0x50) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Detect Chain[%d] temp too low, will ignore: temp=%d\n",i,
                     (int)dev->chain_asic_maxtemp[i][0]);
            _applog(5,tmp42,false);
          }
          chain_temp_toolow[i] = 1;
        }
      }
      else if ((int)dev->chain_asic_maxtemp[i][0] < lowest_testOK_temp[i]) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Detect Chain[%d] temp too low, will ignore: temp=%d < %d\n",i,
                   (int)dev->chain_asic_maxtemp[i][0],lowest_testOK_temp[i]);
          _applog(5,tmp42,false);
        }
        chain_temp_toolow[i] = 1;
      }
    }
  }
  CheckChainTempTooLowFlag();
  return;
}


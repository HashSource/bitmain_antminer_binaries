
/* WARNING: Unknown calling convention */

_Bool isTempTooLow(void)

{
  char tmp42 [2048];
  char logstr [1024];
  int i;
  
  i = 0;
  do {
    if (0xf < i) {
      return false;
    }
    if (((dev->chain_exist[i] == 1) && (chain_temp_toolow[i] == 0)) &&
       (0 < dev->chain_asic_temp[i][1][0])) {
      if (lowest_testOK_temp[i] < 1) {
        if (dev->chain_asic_temp[i][1][0] < 0x50) {
          if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Detect temp too low: Chain[%d] curtemp=%d\n",i,
                     (int)dev->chain_asic_temp[i][1][0]);
            _applog(5,tmp42,false);
          }
          return true;
        }
      }
      else if ((int)dev->chain_asic_temp[i][1][0] < lowest_testOK_temp[i]) {
        if (((use_syslog) || (opt_log_output)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Detect temp too low: Chain[%d] lowest_testOK_temp=%d curtemp=%d\n",i
                   ,lowest_testOK_temp[i],(int)dev->chain_asic_temp[i][1][0]);
          _applog(5,tmp42,false);
        }
        return true;
      }
    }
    i = i + 1;
  } while( true );
}


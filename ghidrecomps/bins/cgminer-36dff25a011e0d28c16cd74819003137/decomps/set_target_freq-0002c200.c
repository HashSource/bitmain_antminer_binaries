
/* WARNING: Unknown calling convention */

float set_target_freq(void)

{
  FILE *__stream;
  FILE *pFile;
  float max_freq;
  uint8_t i;
  
  max_freq = 0.0;
  if (opt_pattern) {
    for (i = '\0'; i < 0x10; i = i + '\x01') {
      if (dev->chain_exist[i] != 0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          __stream = fopen(log_file,"a+");
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s: set freq %f on chain %d\n","driver-btm-soc.c",0x1797,
                    "set_target_freq");
          }
          fclose(__stream);
        }
        if (max_freq <= freq_from_board[i]) {
          max_freq = freq_from_board[i];
        }
        increase_freq_slowly(init_freq,freq_from_board[i],freq_step,i);
      }
    }
  }
  else {
    increase_freq_slowly(init_freq,(float)(ulonglong)dev->frequency,freq_step,All_Chain);
    for (i = '\0'; i < 0x10; i = i + '\x01') {
      if (dev->chain_exist[i] != 0) {
        freq_from_board[i] = (float)(ulonglong)dev->frequency;
      }
    }
    max_freq = (float)(ulonglong)dev->frequency;
  }
  return max_freq;
}


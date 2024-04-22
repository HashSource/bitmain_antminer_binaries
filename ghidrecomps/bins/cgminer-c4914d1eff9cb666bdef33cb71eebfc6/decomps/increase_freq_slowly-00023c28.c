
void increase_freq_slowly(float init_freq,float final_freq,float freq_step,uint8_t chain)

{
  FILE *__stream;
  float fVar1;
  uint8_t chain_local;
  float freq_step_local;
  float final_freq_local;
  float init_freq_local;
  FILE *pFile;
  float freq_tmp;
  int steps;
  int i;
  
  steps = (int)((final_freq - init_freq) / freq_step);
  fVar1 = (float)(longlong)steps * freq_step + init_freq;
  if (final_freq != fVar1 && final_freq < fVar1 == (NAN(final_freq) || NAN(fVar1))) {
    steps = steps + 1;
  }
  for (i = 0; i < steps; i = i + 1) {
    freq_tmp = init_freq + (float)(longlong)(i + 1) * freq_step;
    if (freq_tmp != final_freq && freq_tmp < final_freq == (NAN(freq_tmp) || NAN(final_freq))) {
      freq_tmp = final_freq;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: \n\nIncrease frequency to %.2fM\n","driver-btm-soc.c",0x12b2,
                "increase_freq_slowly");
      }
      fclose(__stream);
    }
    if (chain == All_Chain) {
      set_pll(freq_tmp);
    }
    else {
      change_high_pll_test(chain,freq_tmp,0);
    }
    sleep(1);
  }
  return;
}



void increase_to_base_freq(float init_freq,float freq_step)

{
  _Bool _Var1;
  FILE *pFVar2;
  float fVar3;
  float freq_step_local;
  float init_freq_local;
  int final_freq [16];
  int steps [16];
  FILE *pFile;
  FILE *pFile_1;
  float freq_tmp;
  int max_steps;
  int chain;
  int i;
  
  memset(steps,0,0x40);
  max_steps = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      _Var1 = is_column_sweep();
      if (_Var1) {
        final_freq[chain] = 0x96;
      }
      else {
        final_freq[chain] = scanfreq_info.base_freq[chain];
      }
      steps[chain] = (int)(((float)(longlong)final_freq[chain] - init_freq) / freq_step);
      if ((int)((uint)((float)(longlong)steps[chain] * freq_step + init_freq <
                      (float)(longlong)final_freq[chain]) << 0x1f) < 0) {
        steps[chain] = steps[chain] + 1;
      }
      if (max_steps < steps[chain]) {
        max_steps = steps[chain];
      }
    }
  }
  for (i = 0; i < max_steps; i = i + 1) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) &&
         (i < steps[chain])) {
        freq_tmp = init_freq + (float)(longlong)(i + 1) * freq_step;
        fVar3 = (float)(longlong)final_freq[chain];
        if (freq_tmp != fVar3 && freq_tmp < fVar3 == (NAN(freq_tmp) || NAN(fVar3))) {
          freq_tmp = (float)(longlong)final_freq[chain];
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: Chain[%d] increase frequency to %.2fM\n","driver-btm-soc.c",
                    0x1f1e,"increase_to_base_freq",chain,(double)freq_tmp);
          }
          fclose(pFVar2);
        }
        change_high_pll_test((uint8_t)chain,freq_tmp,0);
      }
    }
    usleep(1000000);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: \n","driver-btm-soc.c",0x1f23,"increase_to_base_freq");
    }
    fclose(pFVar2);
  }
  return;
}


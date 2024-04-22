
void increase_freq_slowly_by_index(float init_freq,float low_freq,float high_freq)

{
  FILE *pFVar1;
  float fVar2;
  float high_freq_local;
  float low_freq_local;
  float init_freq_local;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile;
  float freq_tmp;
  int steps;
  int i;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \n init freq = %f, low_freq = %f, high_freq = %f\n",
              "driver-btm-soc.c",0x12c4,"increase_freq_slowly_by_index");
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \nstep1\n","driver-btm-soc.c",0x12c6,"increase_freq_slowly_by_index"
             );
    }
    fclose(pFVar1);
  }
  steps = (int)((low_freq - init_freq) / freq_step);
  fVar2 = (float)(longlong)steps * freq_step + init_freq;
  if (low_freq != fVar2 && low_freq < fVar2 == (NAN(low_freq) || NAN(fVar2))) {
    steps = steps + 1;
  }
  for (i = 0; i < steps; i = i + 1) {
    freq_tmp = init_freq + (float)(longlong)(i + 1) * freq_step;
    if (freq_tmp != low_freq && freq_tmp < low_freq == (NAN(freq_tmp) || NAN(low_freq))) {
      freq_tmp = low_freq;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: all chains increase frequency to %.2fM\n","driver-btm-soc.c",
                0x12d2,"increase_freq_slowly_by_index");
      }
      fclose(pFVar1);
    }
    set_pll(freq_tmp);
    sleep(1);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: \nstep2\n","driver-btm-soc.c",0x12da,"increase_freq_slowly_by_index"
             );
    }
    fclose(pFVar1);
  }
  set_pll_adjust(low_freq,high_freq);
  return;
}


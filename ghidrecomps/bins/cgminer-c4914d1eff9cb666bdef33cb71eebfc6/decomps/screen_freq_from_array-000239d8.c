
float screen_freq_from_array(float *array,_Bool is_high_freq)

{
  FILE *pFVar1;
  float fVar2;
  _Bool is_high_freq_local;
  float *array_local;
  FILE *pFile;
  FILE *pFile_1;
  int domain;
  int chain;
  float low_freq;
  float high_freq;
  
  if (is_high_freq) {
    high_freq = freq_adjust_index[0][0];
    for (chain = 0; chain < 4; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        for (domain = 0; domain < 6; domain = domain + 1) {
          if ((int)((uint)(high_freq < freq_adjust_index[chain][domain]) << 0x1f) < 0) {
            high_freq = freq_adjust_index[chain][domain];
          }
        }
      }
    }
    low_freq = high_freq;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: high_freq = %f\n","driver-btm-soc.c",0x128d,
                "screen_freq_from_array");
      }
      fclose(pFVar1);
    }
  }
  else {
    low_freq = freq_adjust_index[0][0];
    for (chain = 0; chain < 4; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        for (domain = 0; domain < 6; domain = domain + 1) {
          fVar2 = freq_adjust_index[chain][domain];
          if (low_freq != fVar2 && low_freq < fVar2 == (NAN(low_freq) || NAN(fVar2))) {
            low_freq = freq_adjust_index[chain][domain];
          }
        }
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: low_freq = %f\n","driver-btm-soc.c",0x129f,
                "screen_freq_from_array");
      }
      fclose(pFVar1);
    }
  }
  return low_freq;
}


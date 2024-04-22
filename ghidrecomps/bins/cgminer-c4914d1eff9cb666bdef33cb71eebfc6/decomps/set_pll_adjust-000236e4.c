
void set_pll_adjust(float low_freq,float final_freq)

{
  FILE *pFVar1;
  float fVar2;
  float final_freq_local;
  float low_freq_local;
  FILE *pFile;
  FILE *pFile_1;
  int local_pll_index;
  uint32_t i;
  float steps;
  float freq_tmp;
  uint8_t chip;
  uint8_t vol_region;
  uint8_t chain;
  
  if (low_freq == final_freq) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: \nno need to adjust freq,the final freq is same %f\n",
                "driver-btm-soc.c",0x1249,"set_pll_adjust");
      }
      fclose(pFVar1);
    }
  }
  else {
    for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
      if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
        steps = (final_freq - low_freq) / freq_adjust_step;
        fVar2 = freq_adjust_step * steps + low_freq;
        if (final_freq != fVar2 && final_freq < fVar2 == (NAN(final_freq) || NAN(fVar2))) {
          steps = steps + 1.0;
        }
        for (i = 0; fVar2 = (float)(ulonglong)i,
            steps != fVar2 && steps < fVar2 == (NAN(steps) || NAN(fVar2)); i = i + 1) {
          freq_tmp = low_freq + (float)(ulonglong)(i + 1) * freq_adjust_step;
          if (freq_tmp != final_freq && freq_tmp < final_freq == (NAN(freq_tmp) || NAN(final_freq)))
          {
            freq_tmp = final_freq;
          }
          for (vol_region = '\0'; vol_region < 6; vol_region = vol_region + '\x01') {
            if (freq_tmp <= freq_adjust_index[chain][vol_region]) {
              for (chip = '\0'; chip < 10; chip = chip + '\x01') {
                change_high_pll_by_aisc((uint)chain,(uint)chip + (uint)vol_region * 10,freq_tmp,0);
              }
              if (4 < log_level) {
                print_crt_time_to_file(log_file,4);
                pFVar1 = fopen(log_file,"a+");
                if (pFVar1 != (FILE *)0x0) {
                  fprintf(pFVar1,"%s:%d:%s: chain[%d] domain[%2d] to %f\n","driver-btm-soc.c",0x126e
                          ,"set_pll_adjust",(uint)chain,vol_region + 1);
                }
                fclose(pFVar1);
              }
            }
          }
          sleep(1);
        }
      }
    }
  }
  return;
}


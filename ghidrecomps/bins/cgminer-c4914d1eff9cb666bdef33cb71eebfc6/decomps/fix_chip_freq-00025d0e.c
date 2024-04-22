
/* WARNING: Unknown calling convention */

void fix_chip_freq(void)

{
  FILE *pFVar1;
  int down_count [16];
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int fixed_totalRate;
  int step_rate;
  int step;
  int min_down_count;
  int fix_chain;
  int totalRate;
  int chip;
  int chain;
  
  step = 10;
  step_rate = 0x7c;
  totalRate = get_current_total_rate();
  fixed_totalRate = 0x4844;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: total rate %d, fixed rate %d, step rate %d\n","driver-btm-soc.c",
              0x168e,"fix_chip_freq",totalRate,0x4844,0x7c);
    }
    fclose(pFVar1);
  }
  memset(down_count,0,0x40);
  while( true ) {
    if (totalRate < step_rate + fixed_totalRate) {
      return;
    }
    min_down_count = 1000;
    fix_chain = -1;
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] == 1) && (down_count[chain] < min_down_count)) {
        min_down_count = down_count[chain];
        fix_chain = chain;
      }
    }
    if (fix_chain == -1) break;
    down_count[fix_chain] = down_count[fix_chain] + 1;
    for (chip = 0; chip < 0x3c; chip = chip + 1) {
      scan_result[fix_chain].freq_eeprom[chip] = scan_result[fix_chain].freq_eeprom[chip] - step;
    }
    totalRate = get_current_total_rate();
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: chain %d down a step of %dM, rate of %dG, total rate %dG\n",
                "driver-btm-soc.c",0x16c3,"fix_chip_freq",fix_chain,step,step_rate,totalRate);
      }
      fclose(pFVar1);
    }
  }
  if (log_level < 4) {
    return;
  }
  print_crt_time_to_file(log_file,3);
  pFVar1 = fopen(log_file,"a+");
  if (pFVar1 != (FILE *)0x0) {
    fprintf(pFVar1,"%s:%d:%s: error, can not find a chain to fix\n","driver-btm-soc.c",0x16b9,
            "fix_chip_freq");
  }
  fclose(pFVar1);
  return;
}


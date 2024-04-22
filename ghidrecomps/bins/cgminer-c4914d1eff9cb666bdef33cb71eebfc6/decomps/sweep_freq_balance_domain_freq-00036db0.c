
/* WARNING: Unknown calling convention */

void sweep_freq_balance_domain_freq(void)

{
  int freq;
  FILE *pFVar1;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int rate_min_freq;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  int rate;
  int chip;
  int col;
  int row;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"\nchain %d chip rating:\n",chain);
        }
        fclose(pFVar1);
      }
      for (row = 0; row < 6; row = row + 1) {
        sweep_freq_sort_array
                  (row,scanfreq_info.chip_max_freq[chain] + row * 10,
                   scanfreq_info.chip_rate[chain] + row * 10,10);
        for (col = 0; col < 10; col = col + 1) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%d ",scanfreq_info.chip_rate[chain][col + row * 10]);
            }
            fclose(pFVar1);
          }
        }
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
    }
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (rate = 1; rate < 0xb; rate = rate + 1) {
        freq = sweep_freq_get_rate_min_freq(chain,rate);
        sweep_freq_set_rate_freq(chain,rate,freq);
      }
    }
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"\nchain %d balanced freq:\n",chain);
        }
        fclose(pFVar1);
      }
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%d ",
                    *(undefined4 *)
                     (scanfreq_info.workdataPathPrefix +
                     (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18));
          }
          fclose(pFVar1);
        }
        if (((chip + 1) % 10 == 0) && (3 < log_level)) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
    }
  }
  return;
}


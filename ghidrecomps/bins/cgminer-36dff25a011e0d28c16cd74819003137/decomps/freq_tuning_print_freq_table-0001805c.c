
void freq_tuning_print_freq_table(freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  int extraout_r1;
  int extraout_r1_00;
  freq_tuning_info *freq_info_local;
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_5;
  FILE *pFile_1;
  FILE *pFile;
  int asic;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: print_freq_table...\n","freq_tuning.c",0x62f,
              "freq_tuning_print_freq_table");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain[%d]:\n",chain);
        }
        fclose(pFVar1);
      }
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"Freq%02d=%03d  ",asic,freq_info->freq_table[chain][asic]);
          }
          fclose(pFVar1);
        }
        __aeabi_idivmod(asic + 1,freq_info->asic_num_per_vol_domain * 3);
        if (extraout_r1 == 0) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fputc(10,pFVar1);
            }
            fclose(pFVar1);
          }
        }
        else {
          __aeabi_idivmod(asic + 1,freq_info->asic_num_per_vol_domain);
          if ((extraout_r1_00 == 0) && (3 < log_level)) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fwrite(&DAT_000985cc,1,3,pFVar1);
            }
            fclose(pFVar1);
          }
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
  return;
}


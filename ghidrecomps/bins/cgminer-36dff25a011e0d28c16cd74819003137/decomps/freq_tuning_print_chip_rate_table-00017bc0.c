
void freq_tuning_print_chip_rate_table(freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  freq_tuning_info *freq_info_local;
  FILE *pFile_3;
  FILE *pFile_8;
  FILE *pFile_6;
  FILE *pFile_7;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int scan_level;
  int asic;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: print_chip_rate_table...\n","freq_tuning.c",0x60e,
              "freq_tuning_print_chip_rate_table");
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
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fwrite(&DAT_0009857c,1,3,pFVar1);
        }
        fclose(pFVar1);
      }
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1," Asic%02d",asic + 1);
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
      for (scan_level = 0; (scan_level < 8 && (freq_info->scan_level_table[scan_level] != 0));
          scan_level = scan_level + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%03d",freq_info->scan_level_table[scan_level]);
          }
          fclose(pFVar1);
        }
        for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1," %7d",freq_info->chip_rate_table[chain][scan_level][asic]);
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


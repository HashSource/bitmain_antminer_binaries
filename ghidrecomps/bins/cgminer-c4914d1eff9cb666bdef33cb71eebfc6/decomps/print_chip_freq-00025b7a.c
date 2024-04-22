
/* WARNING: Unknown calling convention */

void print_chip_freq(void)

{
  FILE *pFVar1;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile_3;
  FILE *pFile;
  int chip;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain %d freq:\n",chain);
        }
        fclose(pFVar1);
      }
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%d ",scan_result[chain].freq_eeprom[chip]);
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


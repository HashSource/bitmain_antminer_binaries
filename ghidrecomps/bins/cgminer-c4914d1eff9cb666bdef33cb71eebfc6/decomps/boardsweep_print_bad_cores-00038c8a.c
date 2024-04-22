
/* WARNING: Unknown calling convention */

void boardsweep_print_bad_cores(void)

{
  FILE *pFVar1;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_4;
  char *bad_core_log;
  int bad_core_num;
  int chip;
  int m;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen("/var/log/bad_cores","a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"\nchain %d freq %d: \n",i,scanfreq_info.base_freq[i]);
        }
        fclose(pFVar1);
      }
      for (chip = 0; chip < scanfreq_info.AsicNum; chip = chip + 1) {
        bad_core_num = 0;
        if (3 < log_level) {
          pFVar1 = fopen("/var/log/bad_cores","a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"[chip %02d]\n",chip);
          }
          fclose(pFVar1);
        }
        for (m = 0; m < 0xd0; m = m + 1) {
          bad_core_num = bad_core_num + 1;
          if (3 < log_level) {
            pFVar1 = fopen("/var/log/bad_cores","a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"[%03d %d] ",m,scanfreq_info.asic_core_nonce_num[i][chip][m]);
            }
            fclose(pFVar1);
          }
          if ((bad_core_num % 0xd == 0) && (3 < log_level)) {
            pFVar1 = fopen("/var/log/bad_cores","a+");
            if (pFVar1 != (FILE *)0x0) {
              fputc(10,pFVar1);
            }
            fclose(pFVar1);
          }
        }
      }
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen("/var/log/bad_cores","a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}


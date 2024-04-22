
/* WARNING: Unknown calling convention */

void sweep_freq_print_chip_max_freq(void)

{
  FILE *pFVar1;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int j;
  int i;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: chip max freq:\n","freq_scan.c",0xbc8,
              "sweep_freq_print_chip_max_freq");
    }
    fclose(pFVar1);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain[%d]:\n",i);
        }
        fclose(pFVar1);
      }
      for (j = 0; j < 0x3c; j = j + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%03d  ",scanfreq_info.chip_max_freq[i][j]);
          }
          fclose(pFVar1);
        }
        if (((j + 1) % 10 == 0) && (3 < log_level)) {
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


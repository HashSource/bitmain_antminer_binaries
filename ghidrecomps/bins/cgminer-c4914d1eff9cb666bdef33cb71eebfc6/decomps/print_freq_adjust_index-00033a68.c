
/* WARNING: Unknown calling convention */

void print_freq_adjust_index(void)

{
  FILE *pFVar1;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t vol_region;
  uint32_t chain;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fwrite("freq to test:\n",1,0xe,pFVar1);
    }
    fclose(pFVar1);
  }
  if (5 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      for (vol_region = 0; vol_region < 6; vol_region = vol_region + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"V[%02d]:%3.0f ",vol_region + 1,freq_adjust_index[chain] + vol_region,
                    (double)freq_adjust_index[chain][vol_region]);
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
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  return;
}


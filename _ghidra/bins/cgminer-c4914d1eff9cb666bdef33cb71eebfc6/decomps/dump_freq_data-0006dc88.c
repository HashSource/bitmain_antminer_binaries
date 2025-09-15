
void dump_freq_data(uint8_t chain,uint32_t *freq)

{
  FILE *pFVar1;
  uint32_t *freq_local;
  uint8_t chain_local;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile;
  int k;
  int l;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"chain [%d] freq data per ASIC:\n",(uint)chain);
    }
    fclose(pFVar1);
  }
  for (l = 0; l < 6; l = l + 1) {
    for (k = 0; k < 10; k = k + 1) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"IC[%03d]:%d ",(l * 0x3c) / 6 + k,freq[k + (l * 0x3c) / 6]);
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
  return;
}


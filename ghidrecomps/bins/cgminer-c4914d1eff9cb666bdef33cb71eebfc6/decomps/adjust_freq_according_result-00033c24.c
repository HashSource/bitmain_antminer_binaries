
void adjust_freq_according_result(int freq_scan_times,working_mode_e working_mode)

{
  FILE *pFVar1;
  working_mode_e working_mode_local;
  int freq_scan_times_local;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      adjust_freq_by_chain(chain,freq_scan_times,working_mode);
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


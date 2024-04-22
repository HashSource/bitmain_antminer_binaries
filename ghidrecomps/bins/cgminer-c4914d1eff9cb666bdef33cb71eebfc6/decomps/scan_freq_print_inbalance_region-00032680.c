
void scan_freq_print_inbalance_region(int freq_scan_times)

{
  FILE *pFVar1;
  int freq_scan_times_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  
  memset(inbalance_info_record,0,0x50);
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      scan_freq_print_inbalance_region_by_chain(chain,freq_scan_times);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"vol num = %d\n",(uint)(byte)inbalance_info_record[chain].len);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"inbalance vol = %d,%d,%d,%d\n",
                  (uint)(byte)inbalance_info_record[chain].vol0,
                  (uint)(byte)inbalance_info_record[chain].vol1,
                  (uint)(byte)inbalance_info_record[chain].vol2,
                  (uint)(byte)inbalance_info_record[chain].vol3);
        }
        fclose(pFVar1);
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



/* WARNING: Unknown calling convention */

void sweep_freq_print_current_column(void)

{
  FILE *pFVar1;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile_4;
  FILE *pFile;
  int column;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: current column freq level\n","freq_scan.c",0xacb,
              "sweep_freq_print_current_column");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"Chain %d:  ",chain);
        }
        fclose(pFVar1);
      }
      for (column = 0; column < 10; column = column + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%02d ",(uint)scanfreq_info.domain_freq_level[chain][column]);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,",  current column %d\n",(uint)scanfreq_info.current_column[chain]);
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


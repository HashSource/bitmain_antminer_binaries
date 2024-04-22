
_Bool scan_freq_check_result(int chain)

{
  FILE *pFVar1;
  int chain_local;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  int column;
  int m;
  int i;
  
  column = 0;
  i = 0;
  do {
    if (scanfreq_info.AsicNum <= i) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: check ok: chain %d \n","freq_scan.c",0x455,
                  "scan_freq_check_result",chain);
        }
        fclose(pFVar1);
      }
      return true;
    }
    if ((check_column_nonce == false) ||
       (column = get_logical_column_by_chip_no(i),
       column == (uint)scanfreq_info.current_column[chain])) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"check chain %d column %d asic %d",chain,column,i);
        }
        fclose(pFVar1);
      }
      for (m = 0; m < 0xd0; m = m + 1) {
        if (scanfreq_info.asic_core_nonce_num[chain][i][m] < 2) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"check fail: chain %d asic %d core %d return %d nonce",chain,i,m,
                      scanfreq_info.asic_core_nonce_num[chain][i][m]);
            }
            fclose(pFVar1);
          }
          return false;
        }
      }
    }
    i = i + 1;
  } while( true );
}


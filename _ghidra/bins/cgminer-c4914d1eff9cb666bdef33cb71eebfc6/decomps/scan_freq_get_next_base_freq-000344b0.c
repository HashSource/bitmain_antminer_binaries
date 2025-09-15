
void scan_freq_get_next_base_freq(working_mode_e *working_mode)

{
  FILE *pFVar1;
  working_mode_e *working_mode_local;
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_1;
  int chain;
  
  chain = 0;
  do {
    if (0xf < chain) {
      return;
    }
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      if (1 < scanfreq_info.base_freq_index[chain] + 1) {
        scanfreq_info.last_all_pass = true;
        if (log_level < 4) {
          scanfreq_info.last_all_pass = true;
          return;
        }
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] has no more base freq to test! finish!\n",
                  "freq_scan.c",0x90a,"scan_freq_get_next_base_freq",chain);
        }
        fclose(pFVar1);
        return;
      }
      scanfreq_info.base_freq_index[chain] = scanfreq_info.base_freq_index[chain] + 1;
      scanfreq_info.base_freq[chain] = scan_base_freq[scanfreq_info.base_freq_index[chain]];
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d] get next base freq %d\n","freq_scan.c",0x918,
                  "scan_freq_get_next_base_freq",chain,scanfreq_info.base_freq[chain]);
        }
        fclose(pFVar1);
      }
      if (scanfreq_info.base_freq_index[chain] == 1) {
        *working_mode = MODE2;
      }
      else if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: error,only 2 mode in T11\n","freq_scan.c",0x920,
                  "scan_freq_get_next_base_freq");
        }
        fclose(pFVar1);
      }
      init_freq_adjust_index(g_sweep_config_hpf.sweep_max_freq);
    }
    chain = chain + 1;
  } while( true );
}



void sweep_freq_get_next_freq(working_mode_e working_mode)

{
  byte bVar1;
  bool bVar2;
  _Bool _Var3;
  int iVar4;
  FILE *pFVar5;
  int iVar6;
  uint column;
  int iVar7;
  working_mode_e working_mode_local;
  FILE *pFile_1;
  FILE *pFile;
  int next_freq;
  FILE *pFile_2;
  int current_column;
  int max_freq;
  _Bool is_all_current_column_finish;
  int chain;
  
  bVar2 = true;
  iVar6 = g_sweep_config_hpf.sweep_max_freq;
  if (working_mode == MODE1) {
    iVar6 = g_sweep_config_eco.sweep_max_freq;
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) &&
       (column = (uint)scanfreq_info.current_column[chain],
       scanfreq_info.current_column_finish[chain][column] == false)) {
      iVar4 = scanfreq_info.base_freq[chain];
      iVar7 = scanfreq_info.freq_step * (scanfreq_info.domain_freq_level[chain][column] + 2);
      _Var3 = sweep_freq_all_chip_failed(chain,column);
      if ((_Var3) || (iVar6 < iVar7 + iVar4)) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s:  ----- chain %d column %d finished ----\n","freq_scan.c",0xb00
                    ,"sweep_freq_get_next_freq",chain,column);
          }
          fclose(pFVar5);
        }
        scanfreq_info.current_column_finish[chain][column] = true;
        if ((column == 9) && (scanfreq_info.test_done[chain] = true, 3 < log_level)) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s:  ********* chain[%d] scan finish ********* \n","freq_scan.c",
                    0xb05,"sweep_freq_get_next_freq",chain);
          }
          fclose(pFVar5);
        }
      }
      else {
        scanfreq_info.domain_freq_level[chain][column] =
             scanfreq_info.domain_freq_level[chain][column] + '\x02';
      }
    }
  }
  chain = 0;
  do {
    if (0xf < chain) {
LAB_000359ec:
      if (bVar2) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: all chain current column finished\n","freq_scan.c",0xb1d,
                    "sweep_freq_get_next_freq");
          }
          fclose(pFVar5);
        }
        for (chain = 0; chain < 0x10; chain = chain + 1) {
          if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
            bVar1 = scanfreq_info.current_column[chain];
            scanfreq_info.domain_freq_level[chain][bVar1] = '\0';
            scanfreq_info.current_column[chain] = bVar1 + 1;
            scanfreq_info.need_init = true;
          }
        }
      }
      return;
    }
    if (((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) &&
       (scanfreq_info.current_column_finish[chain][scanfreq_info.current_column[chain]] != true)) {
      bVar2 = false;
      goto LAB_000359ec;
    }
    chain = chain + 1;
  } while( true );
}


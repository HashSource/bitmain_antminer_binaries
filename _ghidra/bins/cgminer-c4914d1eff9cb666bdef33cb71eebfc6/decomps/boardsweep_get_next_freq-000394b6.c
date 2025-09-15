
void boardsweep_get_next_freq(working_mode_e working_mode)

{
  FILE *__stream;
  int iVar1;
  int iVar2;
  working_mode_e working_mode_local;
  FILE *pFile;
  int next_freq;
  int max_freq;
  int chain;
  
  iVar1 = g_sweep_config_hpf.sweep_max_freq;
  if (working_mode == MODE1) {
    iVar1 = g_sweep_config_eco.sweep_max_freq;
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) && (scanfreq_info.test_done[chain] == false)) {
      iVar2 = scanfreq_info.freq_step * 2 + scanfreq_info.base_freq[chain];
      if (iVar1 < iVar2) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          __stream = fopen(log_file,"a+");
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s:  ----- chain %d sweep finished ----\n","freq_scan.c",0xf8f,
                    "boardsweep_get_next_freq",chain);
          }
          fclose(__stream);
        }
        scanfreq_info.test_done[chain] = true;
      }
      else {
        scanfreq_info.base_freq[chain] = iVar2;
      }
    }
  }
  return;
}


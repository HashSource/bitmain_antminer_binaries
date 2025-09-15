
/* WARNING: Unknown calling convention */

int asic_sweep_stat_end(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int offset;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  FILE *pFile_4;
  FILE *pFile;
  int level_num;
  int succeed_freq_cnt;
  int level;
  int chip;
  int chain;
  
  if (asic_sweep_state == (uint8_t *)0x0) {
    iVar2 = 0;
  }
  else {
    sweep_failed_base_freq = false;
    sweep_failed_middle_freq = false;
    sweep_failed_few_succeed_freq = false;
    memset(is_asic_bad,0,0x3c0);
    iVar2 = __aeabi_idiv(g_sweep_config_hpf.sweep_max_freq - g_sweep_config_hpf.sweep_min_freq,
                         scanfreq_info.freq_step);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: level_num = %d\n","freq_scan.c",0xdd7,"asic_sweep_stat_end",iVar2)
        ;
      }
      fclose(pFVar1);
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        for (chip = 0; chip < 0x3c; chip = chip + 1) {
          succeed_freq_cnt = 0;
          for (level = 0; level <= iVar2; level = level + 2) {
            iVar3 = chip * 0x28 + chain * 0x960 + level;
            if ((iVar3 < 0x9600) && (asic_sweep_state[iVar3] == '\0')) {
              succeed_freq_cnt = succeed_freq_cnt + 1;
            }
          }
          if (succeed_freq_cnt < 2) {
            is_asic_bad[chain][chip] = true;
            scanfreq_info.sweep_failed_few_succeed_freq[chain] = true;
            sweep_failed_few_succeed_freq = true;
            freq_scan_error_code_set(0xe,chain);
          }
        }
      }
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"\nchain %d bad chips: ",chain);
          }
          fclose(pFVar1);
        }
        for (chip = 0; chip < 0x3c; chip = chip + 1) {
          if ((is_asic_bad[chain][chip] != false) && (3 < log_level)) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"[chip %02d] ",chip);
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
    free(asic_sweep_state);
    asic_sweep_state = (uint8_t *)0x0;
    if (((sweep_failed_few_succeed_freq == false) && (sweep_failed_base_freq == false)) &&
       (sweep_failed_middle_freq == false)) {
      iVar2 = 0;
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,
                  "%s:%d:%s: sweep failed caused by bad chip , few_succeed_freq %d, base_freq %d, middle_freq %d\n"
                  ,"freq_scan.c",0xe2a,"asic_sweep_stat_end",(uint)sweep_failed_few_succeed_freq,
                  (uint)sweep_failed_base_freq,(uint)sweep_failed_middle_freq);
        }
        fclose(pFVar1);
      }
      iVar2 = -1;
    }
  }
  return iVar2;
}


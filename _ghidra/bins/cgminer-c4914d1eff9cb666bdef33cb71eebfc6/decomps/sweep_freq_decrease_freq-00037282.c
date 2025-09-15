
void sweep_freq_decrease_freq(working_mode_e working_mode)

{
  FILE *pFVar1;
  int iVar2;
  working_mode_e working_mode_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int max_freq;
  int chip;
  int chain;
  
  iVar2 = g_sweep_config_hpf.sweep_max_freq;
  if (working_mode == MODE1) {
    iVar2 = g_sweep_config_eco.sweep_max_freq;
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"\nchain %d decreased freq:\n",chain);
        }
        fclose(pFVar1);
      }
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        if (iVar2 == *(int *)(scanfreq_info.workdataPathPrefix +
                             (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18)) {
          *(int *)(scanfreq_info.workdataPathPrefix +
                  (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) =
               *(int *)(scanfreq_info.workdataPathPrefix +
                       (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) + -5;
        }
        else {
          *(int *)(scanfreq_info.workdataPathPrefix +
                  (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) =
               *(int *)(scanfreq_info.workdataPathPrefix +
                       (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18) + -10;
        }
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%d ",
                    *(undefined4 *)
                     (scanfreq_info.workdataPathPrefix +
                     (int)(&UNK_00011958 + chip + chain * 0x100) * 4 + -0x18));
          }
          fclose(pFVar1);
        }
        if (((chip + 1) % 10 == 0) && (3 < log_level)) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
      }
    }
  }
  return;
}



void tuning_backup(void *param_1)

{
  FILE *pFVar1;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: tuning_backup enter\n","board_frq_tuning.c",0xd3);
    }
    fclose(pFVar1);
  }
  if (param_1 == (void *)0x0) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: invalid parameter!\n","board_frq_tuning.c",0xd7);
      }
      fclose(pFVar1);
    }
  }
  else {
    memcpy(param_1,chain_vol_value,0x40);
    memcpy((void *)((int)param_1 + 0x40),last_success_freq,0x4000);
    memcpy((void *)((int)param_1 + 0x4040),asic_core_enabled_flag,0x400000);
  }
  return;
}


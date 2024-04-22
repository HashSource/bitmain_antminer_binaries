
void tuning_restore(void *param_1,int param_2)

{
  FILE *pFVar1;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: tuning_restore enter\n","board_frq_tuning.c",0xe3);
    }
    fclose(pFVar1);
  }
  if (param_1 == (void *)0x0) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: invalid parameter!\n","board_frq_tuning.c",0xe7);
      }
      fclose(pFVar1);
    }
  }
  else {
    memcpy(chain_vol_value,param_1,0x40);
    memcpy(last_success_freq,(void *)((int)param_1 + 0x40),0x4000);
    memcpy(asic_core_enabled_flag,(void *)((int)param_1 + 0x4040),0x400000);
    set_vol_and_frq(param_2,*(undefined4 *)(chain_vol_value + param_2 * 4),
                    *(undefined4 *)(last_success_freq + param_2 * 0x400));
  }
  return;
}


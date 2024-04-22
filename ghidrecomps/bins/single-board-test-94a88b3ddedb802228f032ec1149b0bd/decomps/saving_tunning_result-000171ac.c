
void saving_tunning_result(int param_1)

{
  FILE *pFVar1;
  int iVar2;
  uint local_c;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: saving_tunning_result enter\n","board_frq_tuning.c",0x61b);
    }
    fclose(pFVar1);
  }
  memcpy(last_success_freq,(void *)(param_1 + 8),0x4000);
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
       ((iVar2 = is_S9_Hydro(), iVar2 == 0 ||
        (iVar2 = get_board_index_S9_Hydro(local_c,0), iVar2 == local_c)))) {
      save_freq_toPIC(local_c,last_success_freq + local_c * 0x400);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: save_freq_toPIC on chain[%d]\n","board_frq_tuning.c",0x62b,local_c)
          ;
        }
        fclose(pFVar1);
      }
      search_over[local_c] = 1;
      *(undefined4 *)(searchFreqMode + local_c * 4) = 0x19;
      testDone[local_c] = 1;
    }
  }
  saving_ideal_hash_rate(param_1);
  saving_voltage(param_1);
  set_reset_allhashboard(1);
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      disable_pic_dac(local_c & 0xff);
      sleep(1);
      enable_pic_dac(local_c & 0xff);
      sleep(1);
    }
  }
  set_reset_allhashboard(0);
  return;
}


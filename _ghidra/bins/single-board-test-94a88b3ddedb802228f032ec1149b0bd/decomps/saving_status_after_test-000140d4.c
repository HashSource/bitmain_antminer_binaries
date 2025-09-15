
void saving_status_after_test(int param_1)

{
  char cVar1;
  FILE *__stream;
  uint local_c;
  
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: saving_status_after_test enter\n","board_frq_tuning.c",0x23f);
    }
    fclose(__stream);
  }
  copyAsicCoreEnabledFlagFromTemp(param_1);
  save_freq_toPIC(param_1,last_success_freq + param_1 * 0x400);
  search_over[param_1] = 1;
  *(undefined4 *)(searchFreqMode + param_1 * 4) = 0x19;
  testDone[param_1] = 1;
  if (conf._144_4_ != 0) {
    cVar1 = check_fan();
    if (cVar1 != '\x01') {
      stop_scan(&DAT_0012d630);
    }
  }
  set_reset_allhashboard(1);
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      disable_pic_dac(local_c & 0xff);
    }
  }
  sleep(1);
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      enable_pic_dac(local_c & 0xff);
    }
  }
  sleep(1);
  set_reset_allhashboard(0);
  return;
}


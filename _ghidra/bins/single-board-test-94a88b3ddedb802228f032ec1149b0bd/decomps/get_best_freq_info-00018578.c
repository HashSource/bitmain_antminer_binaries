
void get_best_freq_info(int param_1,int param_2,int param_3)

{
  int aiStack_a4 [32];
  FILE *local_24;
  FILE *local_20;
  int local_1c;
  FILE *local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  memset(aiStack_a4,0,0x80);
  for (local_c = 0; local_c < param_3; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
      if ((*(int *)(cgpu + (local_10 + 0x9c638) * 4) != 0) &&
         (aiStack_a4[local_10 * 2] <
          *(int *)(param_2 + local_c * 0x585dc + (local_10 + 0x16166) * 4))) {
        aiStack_a4[local_10 * 2] = *(int *)(param_2 + local_c * 0x585dc + (local_10 + 0x16166) * 4);
        aiStack_a4[local_10 * 2 + 1] = local_c;
      }
    }
  }
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (3 < log_level)) {
      local_18 = fopen(log_file,"a+");
      if (local_18 != (FILE *)0x0) {
        fprintf(local_18,"%s:%d: chain: %d, max ideal rate: %d, vol level index: %d\n",
                "board_frq_tuning.c",0x804,local_c,aiStack_a4[local_c * 2],
                aiStack_a4[local_c * 2 + 1]);
      }
      fclose(local_18);
    }
  }
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      local_1c = aiStack_a4[local_c * 2 + 1];
      *(undefined4 *)(param_1 + (local_c + 0x15002) * 4) =
           *(undefined4 *)(param_2 + local_1c * 0x585dc + (local_c + 0x15002) * 4);
      *(undefined4 *)(param_1 + (local_c + 0x16166) * 4) =
           *(undefined4 *)(param_2 + local_1c * 0x585dc + (local_c + 0x16166) * 4);
      memcpy((void *)(param_1 + local_c * 0x400 + 8),
             (void *)(local_c * 0x400 + 8 + param_2 + local_1c * 0x585dc),0x400);
      memcpy((void *)(param_1 + local_c * 0x50 + 0x54088),
             (void *)(local_c * 0x50 + 0x54088 + param_2 + local_1c * 0x585dc),0x50);
      memcpy((void *)(param_1 + local_c * 0x5000 + 0x4008),
             (void *)(local_c * 0x5000 + 0x4008 + param_2 + local_1c * 0x585dc),0x5000);
      local_14 = *(int *)(param_1 + (local_c + 0x16166) * 4) + local_14;
      if (3 < log_level) {
        local_20 = fopen(log_file,"a+");
        if (local_20 != (FILE *)0x0) {
          fprintf(local_20,"%s:%d: chain[%d] max hash rate = %d\n","board_frq_tuning.c",0x814,
                  local_c,*(undefined4 *)(param_1 + (local_c + 0x16166) * 4));
        }
        fclose(local_20);
      }
    }
  }
  if (3 < log_level) {
    local_24 = fopen(log_file,"a+");
    if (local_24 != (FILE *)0x0) {
      fprintf(local_24,"%s:%d: total hash rate = %d\n","board_frq_tuning.c",0x817,local_14);
    }
    fclose(local_24);
  }
  if (g_is_low_power_hashrate_scan != '\x01') {
    set_total_hash_rate(local_14);
  }
  return;
}


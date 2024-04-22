
undefined4 check_one_asic_reg(uint param_1,undefined param_2,undefined param_3)

{
  undefined local_2c;
  undefined uStack_2b;
  undefined uStack_2a;
  undefined4 uStack_29;
  FILE *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  
  local_10 = 0;
  local_1c = 0;
  local_14 = 0x80000000;
  local_2c = 0;
  uStack_2b = 0;
  uStack_2a = 0;
  uStack_29 = 0;
  local_18 = 0;
  clear_register_value_buf();
  local_18 = 0;
  if ((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) {
    local_20 = param_1;
    read_asic_register(param_1 & 0xff,0,param_3,param_2);
    while (local_10 < 4) {
      pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
      local_1c = *(uint *)(reg_value_buf + 8);
      pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
      if (local_1c == 0) {
        usleep(10000);
        local_10 = local_10 + 1;
      }
      else {
        local_18 = local_1c + local_18;
        local_10 = 0;
        if (300 < local_18) {
          if (3 < log_level) {
            local_24 = fopen(log_file,"a+");
            if (local_24 != (FILE *)0x0) {
              fprintf(local_24,"%s:%d: Fatal Error: reg_processed_counter=%d on Chain[%d]\n",
                      "driver-bitmain.c",0x93a,local_18,local_20);
            }
            fclose(local_24);
          }
          return 0;
        }
        for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
          pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
          if (*(byte *)((*(int *)(reg_value_buf + 4) + 5) * 8 + reg_value_buf + 5) == local_20) {
            memset(&local_2c,0,7);
            uStack_29 = CONCAT31(uStack_29._1_3_,
                                 (char)*(undefined4 *)
                                        (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
            uStack_2a = (undefined)
                        ((uint)*(undefined4 *)
                                (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 8);
            uStack_2b = (undefined)
                        ((uint)*(undefined4 *)
                                (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 0x10);
            local_2c = (undefined)
                       ((uint)*(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8)
                       >> 0x18);
            local_14 = *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8);
            *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
            *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
            if (0x1fe < *(uint *)(reg_value_buf + 4)) {
              *(undefined4 *)(reg_value_buf + 4) = 0;
            }
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
          else {
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
        }
      }
    }
    local_10 = 0;
    clear_register_value_buf();
  }
  else {
    local_14 = 0;
  }
  return local_14;
}


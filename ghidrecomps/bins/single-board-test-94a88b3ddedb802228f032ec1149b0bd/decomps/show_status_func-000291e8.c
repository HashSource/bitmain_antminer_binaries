
undefined4 show_status_func(void)

{
  FILE *pFVar1;
  uint local_18;
  char local_13;
  char local_12;
  char local_11;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_18 = 100;
LAB_00029444:
  do {
    if (ExitFlag == '\x01') {
      showExit = 1;
      return 0;
    }
    local_c = local_c + 1;
    if (gIsReadTemp == '\0') {
      local_18 = 100;
    }
    else {
      if (local_c < 0x1e) {
        usleep(100000);
        goto LAB_00029444;
      }
      local_11 = '\0';
      local_12 = '\0';
      local_13 = '}';
      pthread_mutex_lock((pthread_mutex_t *)temp_work_mutex);
      usleep(10000);
      for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
        if ((*(int *)(cgpu + (local_10 + 0x9c638) * 4) != 0) && (testDone[local_10] == '\0')) {
          if (gIsReadTemp != '\0') {
            pthread_mutex_lock((pthread_mutex_t *)read_temp_mutex);
            local_12 = read_asic_temperature(local_10);
            if ((char)board_temp[local_10] < local_12) {
              board_temp[local_10] = local_12;
            }
            pthread_mutex_unlock((pthread_mutex_t *)read_temp_mutex);
          }
          if (local_11 < local_12) {
            local_11 = local_12;
          }
          if (local_12 < local_13) {
            local_13 = local_12;
          }
        }
      }
      pthread_mutex_unlock((pthread_mutex_t *)temp_work_mutex);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: get top_temp=%d low_temp=%d\n","main.c",0xccd,(int)local_11,
                  (int)local_13);
        }
        fclose(pFVar1);
      }
      if ((local_11 == '\0') || (local_13 == '\0')) {
        local_18 = 100;
      }
      else if (local_13 < 'K') {
        if ((int)local_18 < 0x1f) {
          if ((int)local_18 < 0xb) {
            local_18 = 0;
          }
          else {
            local_18 = local_18 - 10;
          }
        }
        else {
          local_18 = 0x1e;
        }
      }
      else if ('K' < local_13) {
        local_18 = (int)local_13 - 0x2d;
      }
      if ('U' < local_11) {
        local_18 = 100;
      }
      set_PWM(local_18 & 0xff);
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: set fan PWM=%d\n","main.c",0xcee,local_18);
        }
        fclose(pFVar1);
      }
    }
    local_c = 0;
    usleep(100000);
  } while( true );
}


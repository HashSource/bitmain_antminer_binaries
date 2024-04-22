
undefined4 send_func(uint param_1)

{
  uint local_134 [5];
  uint auStack_120 [8];
  uint auStack_100 [13];
  undefined local_cc;
  byte local_cb;
  undefined local_ca;
  undefined local_c9;
  int local_c8;
  byte abStack_c4 [96];
  byte local_64 [52];
  FILE *local_30;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  
  local_20 = 0;
  memset(local_64,0,0x34);
  local_64[0] = 0xff;
  memset(abStack_c4 + 0x2c,0,0x34);
  abStack_c4[44] = 0xff;
  memset(auStack_100,0,0x34);
  memset(local_134,0,0x34);
  local_1c = 0;
  local_24 = param_1;
  printf("%s: start on chain[%d]...\n","send_func",param_1);
  local_1c = 0x54;
  local_18 = 0;
  do {
    while( true ) {
      if (ExitFlag == '\x01') {
        sendExit[local_24] = 1;
        return 0;
      }
      if (StartSendFlag[local_24] == '\x01') break;
      local_1c = 0x54;
      local_18 = 0;
      usleep(100000);
    }
    while ((local_18 < *(int *)(chain_DataCount + local_24 * 4) && (StartSendFlag[local_24] != '\0')
           )) {
      local_c = 0;
      while (local_c < local_1c) {
        if (StartSendFlag[local_24] == '\0') break;
        local_20 = get_buffer_space();
        if ((local_20 & 1 << (local_24 & 0xff)) == 0) {
          usleep(5000);
        }
        else {
          if (cgpu._2562268_4_ == 0) {
            memset(local_134,0,0xd);
            local_28 = *(int *)(cgpu + (local_c + 0xa8) * 4);
            local_2c = local_18 * 0x34 + local_28;
            memset(&local_cc,0,0x34);
            local_cc = 1;
            local_cb = (byte)local_24 | 0x80;
            local_ca = 0;
            local_c9 = 0;
            local_c8 = local_18;
            for (local_10 = 0; local_10 < 0xc; local_10 = local_10 + 1) {
              abStack_c4[local_10] = *(byte *)(local_10 + local_2c + 8);
            }
            for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
              abStack_c4[local_10 + 0xc] = *(byte *)(local_10 + local_2c + 0x14);
            }
            local_134[0] = (uint)local_cb << 0x10 | 0x1000000;
            local_134[1] = local_18;
            for (local_14 = 2; local_14 < 5; local_14 = local_14 + 1) {
              local_134[local_14] =
                   (uint)abStack_c4[(local_14 - 2) * 4 + 2] << 8 |
                   (uint)abStack_c4[(local_14 - 2) * 4] << 0x18 |
                   (uint)abStack_c4[(local_14 - 2) * 4 + 1] << 0x10 |
                   (uint)abStack_c4[(local_14 - 2) * 4 + 3];
            }
            for (local_14 = 5; local_14 < 0xd; local_14 = local_14 + 1) {
              local_134[local_14] =
                   (uint)abStack_c4[(local_14 - 5) * 4 + 0xe] << 8 |
                   (uint)abStack_c4[(local_14 - 5) * 4 + 0xc] << 0x18 |
                   (uint)abStack_c4[(local_14 - 5) * 4 + 0xd] << 0x10 |
                   (uint)abStack_c4[(local_14 - 5) * 4 + 0xf];
            }
            pthread_mutex_lock((pthread_mutex_t *)temp_work_mutex);
            set_TW_write_command_vil(local_134);
            pthread_mutex_unlock((pthread_mutex_t *)temp_work_mutex);
          }
          else {
            memset(auStack_100,0,0xd);
            local_28 = *(int *)(cgpu + (local_c + 0xa8) * 4);
            local_2c = local_18 * 0x34 + local_28;
            memset(local_64,0,0x34);
            local_64[0] = 1;
            local_64[1] = (byte)local_24 | 0x80;
            for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
              local_64[local_10 + 4] = *(byte *)(local_10 + local_2c + 0x14);
            }
            for (local_10 = 0; local_10 < 0xc; local_10 = local_10 + 1) {
              local_64[local_10 + 0x28] = *(byte *)(local_10 + local_2c + 8);
            }
            for (local_14 = 0; local_14 < 0xd; local_14 = local_14 + 1) {
              auStack_100[local_14] =
                   (uint)local_64[local_14 * 4 + 2] << 8 |
                   (uint)local_64[local_14 * 4] << 0x18 | (uint)local_64[local_14 * 4 + 1] << 0x10 |
                   (uint)local_64[local_14 * 4 + 3];
              if (local_14 == 9) {
                auStack_100[9] = local_18;
              }
            }
            pthread_mutex_lock((pthread_mutex_t *)temp_work_mutex);
            set_TW_write_command(auStack_100);
            pthread_mutex_unlock((pthread_mutex_t *)temp_work_mutex);
          }
          local_c = local_c + 1;
          *(int *)(send_work_num + local_24 * 4) = *(int *)(send_work_num + local_24 * 4) + 1;
        }
      }
      local_18 = local_18 + 1;
    }
    StartSendFlag[local_24] = 0;
    if (3 < log_level) {
      local_30 = fopen(log_file,"a+");
      if (local_30 != (FILE *)0x0) {
        fprintf(local_30,"%s:%d: get send work num :%d on Chain[%d]\n","main.c",0xf5b,
                *(undefined4 *)(send_work_num + local_24 * 4),local_24);
      }
      fclose(local_30);
    }
  } while( true );
}


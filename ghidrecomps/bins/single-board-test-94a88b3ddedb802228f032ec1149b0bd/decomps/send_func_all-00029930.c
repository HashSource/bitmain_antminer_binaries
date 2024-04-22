
undefined4 send_func_all(void)

{
  char acStack_1c4 [16];
  uint local_1b4 [5];
  uint auStack_1a0 [8];
  uint auStack_180 [13];
  undefined local_14c;
  byte local_14b;
  undefined local_14a;
  undefined local_149;
  int local_148;
  byte local_144 [96];
  byte local_e4 [52];
  int aiStack_b0 [16];
  int aiStack_70 [16];
  FILE *local_30;
  FILE *local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  char local_15;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_20 = 0;
  memset(local_e4,0,0x34);
  local_e4[0] = 0xff;
  memset(local_144 + 0x2c,0,0x34);
  local_144[44] = 0xff;
  memset(auStack_180,0,0x34);
  memset(local_1b4,0,0x34);
  local_15 = '\0';
  local_1c = 0;
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    aiStack_b0[local_c] = 0;
    aiStack_70[local_c] = 0;
    acStack_1c4[local_c] = StartSendFlag[local_c];
  }
  do {
    if (local_15 == '\x01') {
      for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
        if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (StartSendFlag[local_c] == '\x01')) {
          StartSendFlag[local_c] = 0;
          if (3 < log_level) {
            local_30 = fopen(log_file,"a+");
            if (local_30 != (FILE *)0x0) {
              fprintf(local_30,"%s:%d: get send work num :%d on Chain[%d]\n","main.c",0xea3,
                      *(undefined4 *)(send_work_num + local_c * 4),local_c);
            }
            fclose(local_30);
          }
          sendExit[local_c] = 1;
        }
      }
      return 0;
    }
    for (local_14 = 0; (int)local_14 < 0x10; local_14 = local_14 + 1) {
      if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) && (acStack_1c4[local_14] == '\x01')) {
        while (aiStack_70[local_14] < 0x54) {
          local_20 = get_buffer_space();
          if ((local_20 & 1 << (local_14 & 0xff)) == 0) {
            local_1c = local_1c + 1;
            break;
          }
          local_1c = 0;
          if (cgpu._2562268_4_ == 0) {
            memset(local_1b4,0,0xd);
            local_24 = *(int *)(cgpu + (aiStack_70[local_14] + 0xa8) * 4);
            local_28 = aiStack_b0[local_14] * 0x34 +
                       *(int *)(cgpu + (aiStack_70[local_14] + 0xa8) * 4);
            memset(&local_14c,0,0x34);
            local_14c = 1;
            local_14b = (byte)local_14 | 0x80;
            local_14a = 0;
            local_149 = 0;
            local_148 = aiStack_b0[local_14];
            for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
              local_144[local_c] = *(byte *)(local_c + local_28 + 8);
            }
            for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
              local_144[local_c + 0xc] = *(byte *)(local_c + local_28 + 0x14);
            }
            local_1b4[0] = (uint)local_14b << 0x10 | 0x1000000;
            local_1b4[1] = local_148;
            for (local_10 = 2; local_10 < 5; local_10 = local_10 + 1) {
              local_1b4[local_10] =
                   (uint)local_144[(local_10 - 2) * 4 + 2] << 8 |
                   (uint)local_144[(local_10 - 2) * 4] << 0x18 |
                   (uint)local_144[(local_10 - 2) * 4 + 1] << 0x10 |
                   (uint)local_144[(local_10 - 2) * 4 + 3];
            }
            for (local_10 = 5; local_10 < 0xd; local_10 = local_10 + 1) {
              local_1b4[local_10] =
                   (uint)local_144[(local_10 - 5) * 4 + 0xe] << 8 |
                   (uint)local_144[(local_10 - 5) * 4 + 0xc] << 0x18 |
                   (uint)local_144[(local_10 - 5) * 4 + 0xd] << 0x10 |
                   (uint)local_144[(local_10 - 5) * 4 + 0xf];
            }
            pthread_mutex_lock((pthread_mutex_t *)temp_work_mutex);
            set_TW_write_command_vil(local_1b4);
            pthread_mutex_unlock((pthread_mutex_t *)temp_work_mutex);
            aiStack_70[local_14] = aiStack_70[local_14] + 1;
          }
          else {
            memset(auStack_180,0,0xd);
            local_24 = *(int *)(cgpu + (aiStack_70[local_14] + 0xa8) * 4);
            local_28 = aiStack_b0[local_14] * 0x34 +
                       *(int *)(cgpu + (aiStack_70[local_14] + 0xa8) * 4);
            memset(local_e4,0,0x34);
            local_e4[0] = 1;
            local_e4[1] = (byte)local_14 | 0x80;
            for (local_c = 0; local_c < 0x20; local_c = local_c + 1) {
              local_e4[local_c + 4] = *(byte *)(local_c + local_28 + 0x14);
            }
            for (local_c = 0; local_c < 0xc; local_c = local_c + 1) {
              local_e4[local_c + 0x28] = *(byte *)(local_c + local_28 + 8);
            }
            for (local_10 = 0; local_10 < 0xd; local_10 = local_10 + 1) {
              auStack_180[local_10] =
                   (uint)local_e4[local_10 * 4 + 2] << 8 |
                   (uint)local_e4[local_10 * 4] << 0x18 | (uint)local_e4[local_10 * 4 + 1] << 0x10 |
                   (uint)local_e4[local_10 * 4 + 3];
              if (local_10 == 9) {
                auStack_180[9] = aiStack_b0[local_14];
              }
            }
            pthread_mutex_lock((pthread_mutex_t *)temp_work_mutex);
            set_TW_write_command(auStack_180);
            pthread_mutex_unlock((pthread_mutex_t *)temp_work_mutex);
            aiStack_70[local_14] = aiStack_70[local_14] + 1;
          }
          *(int *)(send_work_num + local_14 * 4) = *(int *)(send_work_num + local_14 * 4) + 1;
        }
        if (0x53 < aiStack_70[local_14]) {
          aiStack_70[local_14] = 0;
          aiStack_b0[local_14] = aiStack_b0[local_14] + 1;
          if (*(int *)(chain_DataCount + local_14 * 4) <= aiStack_b0[local_14]) {
            acStack_1c4[local_14] = '\0';
          }
        }
        if (2000 < local_1c) {
          if (3 < log_level) {
            local_2c = fopen(log_file,"a+");
            if (local_2c != (FILE *)0x0) {
              fprintf(local_2c,"%s:%d: Fatal Error: send work timeout\n","main.c",0xe88);
            }
            fclose(local_2c);
          }
          break;
        }
      }
    }
    usleep(5000);
    local_15 = '\x01';
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      if (((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (StartSendFlag[local_c] == '\x01')) &&
         (aiStack_b0[local_c] < *(int *)(chain_DataCount + local_c * 4))) {
        local_15 = '\0';
      }
    }
  } while( true );
}



void check_asic_reg(byte param_1)

{
  undefined local_3c;
  undefined uStack_3b;
  undefined uStack_3a;
  undefined4 uStack_39;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  ushort local_1e;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  
  local_14 = 0;
  local_1e = 0;
  local_3c = 0;
  uStack_3b = 0;
  uStack_3a = 0;
  uStack_39 = 0;
  local_18 = 0;
  local_1c = 0;
  clear_register_value_buf();
  local_c = 0;
  do {
    if (0xf < (int)local_c) {
      return;
    }
    local_1c = 0;
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) && (testDone[local_c] != '\x01')) {
      read_asic_register(local_c & 0xff,1,0,param_1);
      local_18 = 0;
      while (local_14 < 0x12) {
        pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
        local_1e = (ushort)*(undefined4 *)(reg_value_buf + 8);
        pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        if (local_1e == 0) {
          usleep(100000);
          local_14 = local_14 + 1;
        }
        else {
          local_1c = (uint)local_1e + local_1c;
          local_14 = 0;
          if (600 < local_1c) {
            if (log_level < 4) {
              return;
            }
            local_30 = fopen(log_file,"a+");
            if (local_30 != (FILE *)0x0) {
              fprintf(local_30,"%s:%d: Fatal Error: reg_processed_counter=%d on Chain[%d]\n",
                      "driver-bitmain.c",0x80e,local_1c,local_c);
            }
            fclose(local_30);
            return;
          }
          for (local_10 = 0; local_10 < (int)(uint)local_1e; local_10 = local_10 + 1) {
            pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
            if (*(byte *)((*(int *)(reg_value_buf + 4) + 5) * 8 + reg_value_buf + 5) == local_c) {
              memset(&local_3c,0,7);
              uStack_39 = CONCAT31(uStack_39._1_3_,
                                   (char)*(undefined4 *)
                                          (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
              uStack_3a = (undefined)
                          ((uint)*(undefined4 *)
                                  (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 8);
              uStack_3b = (undefined)
                          ((uint)*(undefined4 *)
                                  (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 0x10);
              local_3c = (undefined)
                         ((uint)*(undefined4 *)
                                 (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 0x18);
              if (param_1 == CHIP_ADDRESS) {
                cgpu[local_c + 0x271924] = cgpu[local_c + 0x271924] + '\x01';
              }
              if (param_1 == PLL_PARAMETER) {
                if (3 < log_level) {
                  local_24 = fopen(log_file,"a+");
                  if (local_24 != (FILE *)0x0) {
                    fprintf(local_24,"%s:%d: chain[%d]: the asic[%d] freq is 0x%x\n",
                            "driver-bitmain.c",0x842,local_c,local_18,
                            *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
                  }
                  fclose(local_24);
                }
                local_18 = local_18 + 1;
              }
              if (param_1 == TICKET_MASK) {
                if ((*(int *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) != 0) &&
                   (3 < log_level)) {
                  local_28 = fopen(log_file,"a+");
                  if (local_28 != (FILE *)0x0) {
                    fprintf(local_28,"%s:%d: chain[%d]: the asic[%d] TICKET_MASK is 0x%x\n",
                            "driver-bitmain.c",0x84b,local_c,local_18,
                            *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
                  }
                  fclose(local_28);
                }
                local_18 = local_18 + 1;
              }
              if (param_1 == HASH_COUNTING_NUMBER) {
                if ((*(int *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) != 0) &&
                   (3 < log_level)) {
                  local_2c = fopen(log_file,"a+");
                  if (local_2c != (FILE *)0x0) {
                    fprintf(local_2c,"%s:%d: chain[%d]: the asic[%d] HCN is 0x%x\n",
                            "driver-bitmain.c",0x855,local_c,local_18,
                            *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
                  }
                  fclose(local_2c);
                }
                local_18 = local_18 + 1;
              }
              *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
              *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
              if (0x1fe < *(uint *)(reg_value_buf + 4)) {
                *(undefined4 *)(reg_value_buf + 4) = 0;
              }
              pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
            }
            else {
              *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
              *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
              if (0x1fe < *(uint *)(reg_value_buf + 4)) {
                *(undefined4 *)(reg_value_buf + 4) = 0;
              }
              pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
            }
          }
        }
      }
      local_14 = 0;
      if (param_1 == CHIP_ADDRESS) {
        if ((uint)cgpu._2562392_4_ < (uint)(byte)cgpu[local_c + 0x271924]) {
          cgpu._2562392_4_ = ZEXT14((byte)cgpu[local_c + 0x271924]);
        }
        if (3 < log_level) {
          local_34 = fopen(log_file,"a+");
          if (local_34 != (FILE *)0x0) {
            fprintf(local_34,"%s:%d: %s: chain J%d has %d ASIC\n","driver-bitmain.c",0x878,
                    "check_asic_reg",local_c + 1,(uint)(byte)cgpu[local_c + 0x271924]);
          }
          fclose(local_34);
        }
      }
      clear_register_value_buf();
    }
    local_c = local_c + 1;
  } while( true );
}



void check_asic_reg_oneChain(uint param_1,byte param_2)

{
  undefined local_34;
  undefined uStack_33;
  undefined uStack_32;
  undefined4 uStack_31;
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  uint local_20;
  ushort local_1a;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_1a = 0;
  local_34 = 0;
  uStack_33 = 0;
  uStack_32 = 0;
  uStack_31 = 0;
  local_14 = 0;
  local_18 = 0;
  clear_register_value_buf();
  local_18 = 0;
  if ((*(int *)(cgpu + (param_1 + 0x9c638) * 4) == 1) && (testDone[param_1] != '\x01')) {
    local_20 = param_1;
    read_asic_register(param_1 & 0xff,1,0,param_2);
    local_14 = 0;
    while (local_10 < 0x12) {
      pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
      local_1a = (ushort)*(undefined4 *)(reg_value_buf + 8);
      pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
      if (local_1a == 0) {
        usleep(100000);
        local_10 = local_10 + 1;
      }
      else {
        local_18 = (uint)local_1a + local_18;
        local_10 = 0;
        if (600 < local_18) {
          if (log_level < 4) {
            return;
          }
          local_28 = fopen(log_file,"a+");
          if (local_28 != (FILE *)0x0) {
            fprintf(local_28,"%s:%d: Fatal Error: reg_processed_counter=%d on Chain[%d]\n",
                    "driver-bitmain.c",0x8af,local_18,local_20);
          }
          fclose(local_28);
          return;
        }
        for (local_c = 0; local_c < (int)(uint)local_1a; local_c = local_c + 1) {
          pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
          if (*(byte *)((*(int *)(reg_value_buf + 4) + 5) * 8 + reg_value_buf + 5) == local_20) {
            memset(&local_34,0,7);
            uStack_31 = CONCAT31(uStack_31._1_3_,
                                 (char)*(undefined4 *)
                                        (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
            uStack_32 = (undefined)
                        ((uint)*(undefined4 *)
                                (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 8);
            uStack_33 = (undefined)
                        ((uint)*(undefined4 *)
                                (reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8) >> 0x10);
            local_34 = (undefined)
                       ((uint)*(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8)
                       >> 0x18);
            if (param_2 == CHIP_ADDRESS) {
              cgpu[local_20 + 0x271924] = cgpu[local_20 + 0x271924] + '\x01';
            }
            if (param_2 == PLL_PARAMETER) {
              if (3 < log_level) {
                local_24 = fopen(log_file,"a+");
                if (local_24 != (FILE *)0x0) {
                  fprintf(local_24,"%s:%d: %s: the asic freq is 0x%x\n","driver-bitmain.c",0x8e6,
                          "check_asic_reg_oneChain",
                          *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 5) * 8));
                }
                fclose(local_24);
              }
              local_14 = local_14 + 1;
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
    local_10 = 0;
    if (param_2 == CHIP_ADDRESS) {
      if ((uint)cgpu._2562392_4_ < (uint)(byte)cgpu[local_20 + 0x271924]) {
        cgpu._2562392_4_ = ZEXT14((byte)cgpu[local_20 + 0x271924]);
      }
      if (3 < log_level) {
        local_2c = fopen(log_file,"a+");
        if (local_2c != (FILE *)0x0) {
          fprintf(local_2c,"%s:%d: %s: chain J%d has %d ASIC\n","driver-bitmain.c",0x907,
                  "check_asic_reg_oneChain",local_20 + 1,(uint)(byte)cgpu[local_20 + 0x271924]);
        }
        fclose(local_2c);
      }
    }
    clear_register_value_buf();
  }
  return;
}


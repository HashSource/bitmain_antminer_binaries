
undefined4 receive_func(void)

{
  uint local_50;
  uint local_4c;
  FILE *local_48;
  FILE *local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_27;
  byte local_26;
  byte local_25;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  byte local_15;
  uint local_14;
  
  local_14 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_50 = 0;
  local_4c = 0;
  local_25 = 0;
  local_15 = 0;
  local_26 = 0;
  local_27 = 0;
  local_2c = conf._92_4_;
  local_30 = conf._96_4_;
  local_34 = conf._100_4_;
  local_38 = conf._104_4_;
  local_3c = calculate_asic_number(0x54);
  memset(repeated_nonce_id,0xff,0x4000);
  memset(last_nonce,0,0x40);
  memset(llast_nonce,0,0x40);
  memset(work_id,0,0x40);
  memset(m_nonce,0,0x40);
  while (ExitFlag != '\x01') {
    if (start_receive == '\x01') {
      local_24 = 0;
      local_20 = get_nonce_number_in_fifo();
      local_20 = local_20 & 0x1ff;
      if (local_20 == 0) {
        usleep(1000);
      }
      else {
        local_24 = local_20;
        for (local_14 = 0; local_14 < local_24; local_14 = local_14 + 1) {
          get_return_nonce(&local_50);
          if ((int)local_50 < 0) {
            if ((gBegin_get_nonce != '\0') && ((local_50 & 0x80) != 0)) {
              local_40 = local_50 & 0xf;
              if ((local_40 < 0x10) &&
                 ((*(int *)(cgpu + (local_40 + 0x9c638) * 4) != 0 && (testDone[local_40] == '\0'))))
              {
                if (cgpu._2562268_4_ == 0) {
                  *(uint *)(work_id + local_40 * 4) = local_50 >> 0x10 & 0x7fff;
                }
                else {
                  *(uint *)(work_id + local_40 * 4) = local_50 >> 0x10 & 0x7fff;
                }
                if ((local_4c == *(uint *)(last_nonce + local_40 * 4)) ||
                   (local_4c == *(uint *)(llast_nonce + local_40 * 4))) {
                  *(int *)(last_nonce_num + local_40 * 4) =
                       *(int *)(last_nonce_num + local_40 * 4) + 1;
                }
                else {
                  local_25 = (byte)(local_4c >> 0x19);
                  if (local_25 < 0x54) {
                    *(undefined4 *)(llast_nonce + local_40 * 4) =
                         *(undefined4 *)(last_nonce + local_40 * 4);
                    *(uint *)(last_nonce + local_40 * 4) = local_4c;
                    local_27 = local_25;
                    local_26 = local_25;
                    if (*(uint *)(work_id + local_40 * 4) < 5000) {
                      *(undefined4 *)(m_nonce + local_40 * 4) =
                           *(undefined4 *)
                            (*(int *)(work_id + local_40 * 4) * 0x34 +
                             *(int *)(cgpu + (local_25 + 0xa8) * 4) + 4);
                      if (local_4c == *(uint *)(m_nonce + local_40 * 4)) {
                        if (*(int *)(work_id + local_40 * 4) ==
                            *(int *)(repeated_nonce_id + ((uint)local_25 + local_40 * 0x100) * 4)) {
                          *(int *)(repeated_nonce_num + local_40 * 4) =
                               *(int *)(repeated_nonce_num + local_40 * 4) + 1;
                        }
                        else {
                          *(undefined4 *)
                           (repeated_nonce_id + ((uint)local_25 + local_40 * 0x100) * 4) =
                               *(undefined4 *)(work_id + local_40 * 4);
                          *(int *)(asic_nonce_num + ((uint)local_25 + local_40 * 0x100) * 4) =
                               *(int *)(asic_nonce_num + (local_40 * 0x100 + (uint)local_25) * 4) +
                               1;
                          *(int *)(valid_nonce_num + local_40 * 4) =
                               *(int *)(valid_nonce_num + local_40 * 4) + 1;
                          total_valid_nonce_num = total_valid_nonce_num + 1;
                          local_15 = (byte)local_4c & 0x7f;
                          if ((0x38 < local_15) && (0x3f < local_15)) {
                            local_15 = local_15 - 7;
                          }
                          *(int *)(asic_core_nonce_num +
                                  ((uint)local_15 + ((uint)local_25 + local_40 * 0x100) * 0x100) * 4
                                  ) = *(int *)(asic_core_nonce_num +
                                              ((local_40 * 0x100 + (uint)local_25) * 0x100 +
                                              (uint)local_15) * 4) + 1;
                        }
                      }
                      else {
                        *(int *)(err_nonce_num + local_40 * 4) =
                             *(int *)(err_nonce_num + local_40 * 4) + 1;
                      }
                    }
                  }
                }
              }
              else if (3 < log_level) {
                local_44 = fopen(log_file,"a+");
                if (local_44 != (FILE *)0x0) {
                  fprintf(local_44,"%s:%d: Error chain index=%d of nonce!!!\n","main.c",0xfae,
                          local_40);
                }
                fclose(local_44);
              }
            }
          }
          else {
            if (7 < log_level) {
              local_48 = fopen(log_file,"a+");
              if (local_48 != (FILE *)0x0) {
                fprintf(local_48,"%s:%d: FPGA recv : buf[0]=0x%08x buf[1]=0x%08x\n","main.c",0x1071,
                        local_50,local_4c);
              }
              fclose(local_48);
            }
            pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
            if (reg_value_buf[2] < 0x1ff) {
              reg_value_buf[(*reg_value_buf + 5) * 2] = local_4c;
              *(byte *)(reg_value_buf + (*reg_value_buf + 5) * 2 + 1) =
                   (byte)(local_50 >> 0x18) & 0x1f;
              *(byte *)((int)reg_value_buf + (*reg_value_buf + 5) * 8 + 5) = (byte)local_50 & 0xf;
              *reg_value_buf = *reg_value_buf + 1;
              reg_value_buf[2] = reg_value_buf[2] + 1;
              if (0x1fe < *reg_value_buf) {
                *reg_value_buf = 0;
              }
            }
            else {
              printf("%s: reg_value_buf buffer is full!\n","receive_func");
            }
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
        }
      }
    }
    else {
      local_14 = 0;
      local_1c = 0;
      local_20 = 0;
      local_24 = 0;
      local_50 = 0;
      local_4c = 0;
      local_25 = 0;
      local_15 = 0;
      local_26 = 0;
      local_27 = 0;
      local_2c = conf._92_4_;
      local_30 = conf._96_4_;
      local_34 = conf._100_4_;
      local_38 = conf._104_4_;
      memset(repeated_nonce_id,0xff,0x4000);
      memset(last_nonce,0,0x40);
      memset(llast_nonce,0,0x40);
      memset(work_id,0,0x40);
      memset(m_nonce,0,0x40);
      usleep(100000);
    }
  }
  receiveExit = 1;
  return 0;
}


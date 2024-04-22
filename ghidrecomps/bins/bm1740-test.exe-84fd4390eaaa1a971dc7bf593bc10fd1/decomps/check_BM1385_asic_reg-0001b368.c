
void check_BM1385_asic_reg(byte param_1,undefined4 param_2,char param_3,undefined param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  undefined local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_1c = 0;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_18 = 0;
  local_c = 0;
  local_14 = 0;
  local_10 = 0;
  clear_register_value_buf();
  printf("%s: check chain J%d \n","check_BM1385_asic_reg",param_1 + 1);
  read_BM1385_asic_register(param_1,0,param_3,param_4);
  if (param_3 == '\0') {
    cgpu[param_1 + 0x202fc] = 0;
  }
  while (local_c < 3) {
    usleep(300000);
    pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
    local_14 = *(uint *)(reg_value_buf + 8);
    pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
    if (local_14 == 0) {
      usleep(100000);
      local_c = local_c + 1;
      printf("%s: no asic address register come back for %d time.\n","check_BM1385_asic_reg",local_c
            );
    }
    else {
      local_c = 0;
      for (local_10 = 0; local_10 < local_14; local_10 = local_10 + 1) {
        pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
        if (param_1 == *(byte *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8 + 5)) {
          memset(&local_1c,0,5);
          local_19 = (undefined)
                     *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8);
          local_1a = (undefined)
                     ((uint)*(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8)
                     >> 8);
          local_1b = (undefined)
                     ((uint)*(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8)
                     >> 0x10);
          local_1c = (undefined)
                     ((uint)*(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8)
                     >> 0x18);
          uVar1 = CRC5(&local_1c,0x23);
          if (uVar1 == *(byte *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8 + 4)) {
            if (param_3 == '\0') {
              cgpu[param_1 + 0x202fc] = cgpu[param_1 + 0x202fc] + '\x01';
            }
            if (param_3 == '\f') {
              printf("%s: the asic freq is 0x%08x\n","check_BM1385_asic_reg",
                     *(undefined4 *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8));
            }
            *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
            *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
            if (*(int *)(reg_value_buf + 4) == 0x200) {
              *(undefined4 *)(reg_value_buf + 4) = 0;
            }
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
          else {
            *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
            *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
            if (*(int *)(reg_value_buf + 4) == 0x200) {
              *(undefined4 *)(reg_value_buf + 4) = 0;
            }
            uVar2 = CRC5(&local_1c,0x23);
            printf("%s: crc is 0x%x, but it should be 0x%x\n","check_BM1385_asic_reg",uVar2,
                   (uint)*(byte *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8 + 4));
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
        }
        else {
          *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
          *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
          if (*(int *)(reg_value_buf + 4) == 0x200) {
            *(undefined4 *)(reg_value_buf + 4) = 0;
          }
          printf("%s: the return data is from chain%d, but it should be from chain%d\n",
                 "check_BM1385_asic_reg",
                 (uint)*(byte *)(reg_value_buf + (*(int *)(reg_value_buf + 4) + 2) * 8 + 5),
                 (uint)param_1);
          pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        }
      }
    }
  }
  local_c = 0;
  if (param_3 == '\0') {
    if ((uint)cgpu._131844_4_ < (uint)(byte)cgpu[param_1 + 0x202fc]) {
      cgpu._131844_4_ = ZEXT14((byte)cgpu[param_1 + 0x202fc]);
    }
    printf("%s: chain J%d has %d ASIC\n","check_BM1385_asic_reg",param_1 + 1,
           (uint)(byte)cgpu[param_1 + 0x202fc]);
  }
  clear_register_value_buf();
  return;
}


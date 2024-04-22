
uint check_BM1722_asic_reg(byte param_1,undefined param_2,char param_3,undefined param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_28;
  undefined2 local_24;
  undefined local_22;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_28 = 0;
  local_24 = 0;
  local_22 = 0;
  local_14 = 0;
  local_20 = 0;
  local_18 = 0;
  local_1c = 0x80000000;
  clear_register_value_buf();
  get_BM1722_asic_register(param_1,param_2,param_3,param_4);
  if (param_3 == '\0') {
    cgpu[param_1 + 0x1004b8] = 0;
  }
  while (local_14 < 3) {
    usleep(50000);
    pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
    local_20 = *(uint *)(reg_value_buf + 8);
    pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
    if (local_20 == 0) {
      local_14 = local_14 + 1;
    }
    else {
      local_14 = 0;
      for (local_18 = 0; local_18 < local_20; local_18 = local_18 + 1) {
        pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
        if (param_1 == *(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x19)) {
          memset(&local_28,0,7);
          puVar3 = (undefined4 *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x10);
          local_28 = *puVar3;
          local_24 = *(undefined2 *)(puVar3 + 1);
          local_22 = *(undefined *)((int)puVar3 + 6);
          uVar1 = CRC5(&local_28,0x33);
          if (uVar1 == *(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x18)) {
            if (param_3 == '\0') {
              cgpu[param_1 + 0x1004b8] = cgpu[param_1 + 0x1004b8] + '\x01';
            }
            local_1c = (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x13) |
                       (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x10) <<
                       0x18 | (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 +
                                             0x11) << 0x10 |
                       (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x12) << 8
            ;
            *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
            *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
            if (*(int *)(reg_value_buf + 4) == 0x201) {
              *(undefined4 *)(reg_value_buf + 4) = 0;
            }
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
          else {
            *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
            *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
            if (*(int *)(reg_value_buf + 4) == 0x201) {
              *(undefined4 *)(reg_value_buf + 4) = 0;
            }
            uVar2 = CRC5(&local_28,0x33);
            printf("%s: crc is 0x%x, but it should be 0x%x\n","check_BM1722_asic_reg",uVar2,
                   (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x18));
            pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
          }
        }
        else {
          *(int *)(reg_value_buf + 4) = *(int *)(reg_value_buf + 4) + 1;
          *(int *)(reg_value_buf + 8) = *(int *)(reg_value_buf + 8) + -1;
          if (*(int *)(reg_value_buf + 4) == 0x201) {
            *(undefined4 *)(reg_value_buf + 4) = 0;
          }
          printf("%s: the return data is from chain%d, but it should be from chain%d\n",
                 "check_BM1722_asic_reg",
                 (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x19),
                 (uint)param_1);
          pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        }
      }
    }
  }
  local_14 = 0;
  if (param_3 == '\0') {
    if ((uint)cgpu._1049788_4_ < (uint)(byte)cgpu[param_1 + 0x1004b8]) {
      cgpu._1049788_4_ = ZEXT14((byte)cgpu[param_1 + 0x1004b8]);
    }
    printf("%s: chain J%d has %d ASIC\n","check_BM1722_asic_reg",param_1 + 1,
           (uint)(byte)cgpu[param_1 + 0x1004b8]);
  }
  clear_register_value_buf();
  return local_1c;
}


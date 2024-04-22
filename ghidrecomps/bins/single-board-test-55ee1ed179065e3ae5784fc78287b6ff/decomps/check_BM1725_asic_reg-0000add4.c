
uint check_BM1725_asic_reg(byte param_1,undefined param_2,char param_3,undefined param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  local_38 = 0;
  local_34 = 0;
  local_24 = 0;
  local_30 = 0;
  local_28 = 0;
  local_2c = 0x80000000;
  clear_register_value_buf();
  get_BM1725_asic_register(param_1,param_2,param_3,param_4);
  if (param_3 == '\0') {
    cgpu[param_1 + 0x1004b8] = 0;
  }
  while (local_24 < 3) {
    usleep(50000);
    pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
    local_30 = *(uint *)(reg_value_buf + 8);
    pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
    if (local_30 == 0) {
      local_24 = local_24 + 1;
    }
    else {
      local_24 = 0;
      for (local_28 = 0; local_28 < local_30; local_28 = local_28 + 1) {
        pthread_mutex_lock((pthread_mutex_t *)reg_mutex);
        if (param_1 == *(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x19)) {
          memset(&local_38,0,8);
          puVar3 = (undefined4 *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x10);
          local_38 = *puVar3;
          local_34 = puVar3[1];
          uVar1 = CRC5(&local_38,0x3b);
          if (uVar1 == *(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x18)) {
            if (param_3 == '\0') {
              cgpu[param_1 + 0x1004b8] = cgpu[param_1 + 0x1004b8] + '\x01';
              printf("%s: the asic num is %d, the asic address is 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n"
                     ,"check_BM1725_asic_reg",(uint)(byte)cgpu[param_1 + 0x1004b8],
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x10),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x11),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x12),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x13),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x14),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x15),
                     (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x16),
                     (uint)*(byte *)(*(int *)(reg_value_buf + 4) * 10 + reg_value_buf + 0x17));
            }
            local_2c = (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x13) |
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
            uVar2 = CRC5(&local_38,0x3b);
            printf("%s: crc is 0x%x, but it should be 0x%x\n","check_BM1725_asic_reg",uVar2,
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
                 "check_BM1725_asic_reg",
                 (uint)*(byte *)(reg_value_buf + *(int *)(reg_value_buf + 4) * 10 + 0x19),
                 (uint)param_1);
          pthread_mutex_unlock((pthread_mutex_t *)reg_mutex);
        }
      }
    }
  }
  local_24 = 0;
  if (param_3 == '\0') {
    if ((uint)cgpu._1049788_4_ < (uint)(byte)cgpu[param_1 + 0x1004b8]) {
      cgpu._1049788_4_ = ZEXT14((byte)cgpu[param_1 + 0x1004b8]);
    }
    printf("%s: chain J%d has %d ASIC\n","check_BM1725_asic_reg",param_1 + 1,
           (uint)(byte)cgpu[param_1 + 0x1004b8]);
  }
  clear_register_value_buf();
  return local_2c;
}


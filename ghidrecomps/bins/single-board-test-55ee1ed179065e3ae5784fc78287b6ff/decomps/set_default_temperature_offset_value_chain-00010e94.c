
void set_default_temperature_offset_value_chain(byte param_1)

{
  char local_1d;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  local_1c = 0;
  local_1d = '\0';
  printf("\n--- %s\n","set_default_temperature_offset_value_chain");
  for (local_c = 0; local_14 = 0, local_c < 3; local_c = local_c + 1) {
    local_18 = 0;
    if (local_c == 0) {
      local_10 = (uint)Conf[208];
      local_1d = *(char *)((int)&gT1_offset_value + (uint)param_1);
      local_18 = *(byte *)((int)&gT1_offset_value + (uint)param_1) | 0x1991100;
    }
    if (local_c == 1) {
      local_10 = (uint)Conf[209];
      local_1d = *(char *)((int)&gT2_offset_value + (uint)param_1);
      local_18 = *(byte *)((int)&gT2_offset_value + (uint)param_1) | 0x1991100;
    }
    if (local_c == 2) {
      local_10 = (uint)Conf[210];
      local_1d = *(char *)((int)&gT3_offset_value + (uint)param_1);
      local_18 = *(byte *)((int)&gT3_offset_value + (uint)param_1) | 0x1991100;
    }
    if (local_10 != 0) {
      enable_read_temperature_from_asic_chain
                (param_1,(gChain_Asic_Interval & 0xff) * (local_10 - 1 & 0xff) & 0xff);
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_1c = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_1c = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        local_14 = local_14 + 1;
      } while (((local_1c & 0xc0000000) != 0) && (local_14 < read_loop));
      local_14 = 0;
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0,local_18);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0,local_18);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_1c = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_1c = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        local_14 = local_14 + 1;
      } while (((local_1c & 0xc0000000) != 0) && (local_14 < read_loop));
      local_14 = 0;
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0,0x1981100);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0,0x1981100);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_1c = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_1c = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_10 - 1),0x20,0);
        }
        local_14 = local_14 + 1;
      } while (((local_1c & 0xc0000000) != 0) && (local_14 < read_loop));
      if ((char)local_1c != local_1d) {
        if (local_c == 0) {
          *(undefined *)((int)&Sensor1_OK + (uint)param_1) = 0;
          puts("!!! sensor1 is error!\n");
        }
        if (local_c == 1) {
          *(undefined *)((int)&Sensor2_OK + (uint)param_1) = 0;
          puts("!!! sensor2 is error!\n");
        }
        if (local_c == 2) {
          *(undefined *)((int)&Sensor3_OK + (uint)param_1) = 0;
          puts("!!! sensor3 is error!\n");
        }
      }
    }
  }
  return;
}


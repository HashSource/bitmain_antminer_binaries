
void get_temperature_offset_value_from_asic_chain(byte param_1)

{
  char cVar1;
  char local_2c [8];
  uint local_24;
  uint local_20;
  char local_19;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_10 = 0xffffffff;
  local_18 = 0;
  local_2c[0] = '\0';
  local_2c[1] = '\0';
  local_2c[2] = '\0';
  local_2c[3] = '\0';
  local_2c[4] = '\0';
  local_2c[5] = '\0';
  local_2c[6] = 0;
  local_2c[7] = 0;
  local_19 = '\0';
  local_20 = 0;
  local_24 = 0;
  printf("\n--- %s\n","get_temperature_offset_value_from_asic_chain");
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    if (local_c == 0) {
      local_14 = (uint)Conf[208];
    }
    if (local_c == 1) {
      local_14 = (uint)Conf[209];
    }
    if (local_c == 2) {
      local_14 = (uint)Conf[210];
    }
    if (local_14 != 0) {
      enable_read_temperature_from_asic_chain
                (param_1,(gChain_Asic_Interval & 0xff) * (local_14 - 1 & 0xff) & 0xff);
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_10 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_10 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        local_18 = local_18 + 1;
      } while (((local_10 & 0xc0000000) != 0) && (local_18 < read_loop));
      local_18 = 0;
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1980100);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1980100);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_10 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_10 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        local_18 = local_18 + 1;
      } while (((local_10 & 0xc0000000) != 0) && (local_18 < read_loop));
      local_18 = 0;
      if ((local_10 & 0xc0000000) == 0) {
        local_24 = local_10 & 0xff;
        printf("ASIC temperature is %d\n",local_24);
      }
      else {
        *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
        printf("%s: Can\'t read out ASIC TEMP. ret = 0x%08x\n",
               "get_temperature_offset_value_from_asic_chain",local_10);
      }
      local_10 = 0xffffffff;
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1980000);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1980000);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_10 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_10 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0);
        }
        local_18 = local_18 + 1;
      } while (((local_10 & 0xc0000000) != 0) && (local_18 < read_loop));
      local_18 = 0;
      if ((local_10 & 0xc0000000) == 0) {
        local_20 = local_10 & 0xff;
        printf("local_temp is %d\n",local_20);
      }
      else {
        *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
        printf("%s: Can\'t read out HASH BOARD TEMP. ret = 0x%08x\n",
               "get_temperature_offset_value_from_asic_chain",local_10);
      }
      if (*(char *)((int)&gNotReadOutTemp + (uint)param_1) == '\0') {
        local_19 = (char)local_20 - (char)local_24;
      }
      else {
        local_19 = '\0';
      }
      cVar1 = (char)local_14;
      if (local_c == 0) {
        cgpu[1049792] = local_19;
        local_2c[1] = local_19;
        *(char *)((int)&gT1_offset_value + (uint)param_1) = local_19;
        local_2c[0] = cVar1;
      }
      if (local_c == 1) {
        cgpu[1049793] = local_19;
        local_2c[3] = local_19;
        *(char *)((int)&gT2_offset_value + (uint)param_1) = local_19;
        local_2c[2] = cVar1;
      }
      if (local_c == 2) {
        cgpu[1049794] = local_19;
        local_2c[5] = local_19;
        *(char *)((int)&gT3_offset_value + (uint)param_1) = local_19;
        local_2c[4] = cVar1;
      }
      printf("temp_offset_value = %d\n",(int)local_19);
    }
  }
  local_2c[6] = Conf[252] | 0x20;
  local_2c[7] = (char)Conf._256_4_;
  if (1 < (uint)Conf._108_4_) {
    putchar(10);
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      printf("offset_value[%d] = %d\n",local_c,(int)local_2c[local_c]);
    }
  }
  return;
}


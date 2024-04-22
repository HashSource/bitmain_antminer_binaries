
void enable_extended_mode_of_temperature_sensor_chain(byte param_1)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  printf("\n--- %s\n","enable_extended_mode_of_temperature_sensor_chain");
  for (local_c = 0; local_18 = 0, local_c < 3; local_c = local_c + 1) {
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
      if ((local_10 & 0xc0000000) == 0) {
        if (Conf._116_4_ == 0x6ba) {
          set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1990904);
        }
        else if (Conf._116_4_ == 0x6bd) {
          set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_14 - 1),0x20,0,0x1990904);
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
        if ((local_10 & 0xc0000000) != 0) {
          *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
          printf("%s: Can\'t set extended mode. ret = 0x%08x\n",
                 "enable_extended_mode_of_temperature_sensor_chain",local_10);
        }
      }
      else {
        *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
        printf("%s: Can\'t read out GENERAL_I2C_COMMAND. ret = 0x%08x\n",
               "enable_extended_mode_of_temperature_sensor_chain",local_10);
      }
    }
  }
  return;
}


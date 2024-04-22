
void read_asic_temperature(byte param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_18 = 0xffffffff;
  *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 0;
  for (local_14 = 0; local_20 = 0, local_14 < 3; local_14 = local_14 + 1) {
    if (local_14 == 0) {
      local_1c = (uint)Conf[208];
    }
    if (local_14 == 1) {
      local_1c = (uint)Conf[209];
    }
    if (local_14 == 2) {
      local_1c = (uint)Conf[210];
    }
    if (local_1c != 0) {
      enable_read_temperature_from_asic_chain
                (param_1,(gChain_Asic_Interval & 0xff) * (local_1c - 1 & 0xff) & 0xff);
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_18 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_18 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        local_20 = local_20 + 1;
      } while (((local_18 & 0xc0000000) != 0) && (local_20 < read_loop));
      local_20 = 0;
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0,0x1980100);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0,0x1980100);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_18 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_18 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        local_20 = local_20 + 1;
      } while (((local_18 & 0xc0000000) != 0) && (local_20 < read_loop));
      local_20 = 0;
      if ((local_18 & 0xc0000000) == 0) {
        uVar2 = local_18 & 0xff;
        printf("\n\nASIC %d TEMP is : %d\n",local_1c,uVar2);
        if (local_14 == 0) {
          *(uint *)(Sensor1_temp + (uint)param_1 * 4) = uVar2;
        }
        if (local_14 == 1) {
          *(uint *)(Sensor2_temp + (uint)param_1 * 4) = uVar2;
        }
        if (local_14 == 2) {
          *(uint *)(Sensor3_temp + (uint)param_1 * 4) = uVar2;
        }
        if (Conf[211] == local_1c) {
          if (uVar2 < Conf[212]) {
            if (*(char *)((int)&gStartTest + (uint)param_1) != '\x01') {
              printf("\nASIC %d temperature is %d, waiting it raise to start temperature %d\n\n",
                     local_1c,uVar2,(uint)Conf[212]);
            }
          }
          else {
            if (*(char *)((int)&gStartTest + (uint)param_1) != '\x01') {
              printf("\nBegin test!!! Start sensor is %d, ASIC temperature is %d\n\n",local_1c,uVar2
                    );
            }
            *(undefined *)((int)&gStartTest + (uint)param_1) = 1;
          }
        }
      }
      else {
        printf("%s: do not read out ASIC %d temperature\n\n","read_asic_temperature",local_1c);
        *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
      }
      if (Conf._116_4_ == 0x6ba) {
        set_BM1722_asic_register(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0,0x1980000);
      }
      else if (Conf._116_4_ == 0x6bd) {
        set_BM1725_asic_register(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0,0x1980000);
      }
      do {
        if (Conf._116_4_ == 0x6ba) {
          local_18 = check_BM1722_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        else if (Conf._116_4_ == 0x6bd) {
          local_18 = check_BM1725_asic_reg(param_1,gChain_Asic_Interval * (local_1c - 1),0x20,0);
        }
        local_20 = local_20 + 1;
      } while (((local_18 & 0xc0000000) != 0) && (local_20 < read_loop));
      if ((local_18 & 0xc0000000) == 0) {
        printf("ASIC %d Hash Board temperature is %d\n\n",local_1c,local_18 & 0xff);
      }
      else {
        printf("%s: do not read out ASIC %d Hash Board temperature\n\n","read_asic_temperature",
               local_1c);
        *(undefined *)((int)&gNotReadOutTemp + (uint)param_1) = 1;
      }
    }
  }
  uVar1 = __udivsi3((((*(int *)(Sensor1_temp + (uint)param_1 * 4) +
                       *(int *)(Sensor2_temp + (uint)param_1 * 4) +
                      *(int *)(Sensor3_temp + (uint)param_1 * 4)) -
                     *(int *)(last_Sensor1_temp + (uint)param_1 * 4)) -
                    *(int *)(last_Sensor2_temp + (uint)param_1 * 4)) -
                    *(int *)(last_Sensor3_temp + (uint)param_1 * 4),gSensor_number);
  *(undefined4 *)(temp_change + (uint)param_1 * 4) = uVar1;
  if ((0 < *(int *)(temp_change + (uint)param_1 * 4)) ||
     (*(int *)(temp_change + (uint)param_1 * 4) < 0)) {
    *(undefined4 *)(last_Sensor1_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor1_temp + (uint)param_1 * 4);
    *(undefined4 *)(last_Sensor2_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor2_temp + (uint)param_1 * 4);
    *(undefined4 *)(last_Sensor3_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor3_temp + (uint)param_1 * 4);
  }
  *(undefined4 *)(highest_temp + (uint)param_1 * 4) =
       *(undefined4 *)(Sensor1_temp + (uint)param_1 * 4);
  if (*(int *)(highest_temp + (uint)param_1 * 4) < *(int *)(Sensor2_temp + (uint)param_1 * 4)) {
    *(undefined4 *)(highest_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor2_temp + (uint)param_1 * 4);
  }
  if (*(int *)(highest_temp + (uint)param_1 * 4) < *(int *)(Sensor3_temp + (uint)param_1 * 4)) {
    *(undefined4 *)(highest_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor3_temp + (uint)param_1 * 4);
  }
  *(undefined4 *)(lowest_temp + (uint)param_1 * 4) =
       *(undefined4 *)(Sensor1_temp + (uint)param_1 * 4);
  if ((*(int *)(Sensor2_temp + (uint)param_1 * 4) < *(int *)(lowest_temp + (uint)param_1 * 4)) &&
     (*(int *)(Sensor2_temp + (uint)param_1 * 4) != 0)) {
    *(undefined4 *)(lowest_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor2_temp + (uint)param_1 * 4);
  }
  if ((*(int *)(Sensor3_temp + (uint)param_1 * 4) < *(int *)(lowest_temp + (uint)param_1 * 4)) &&
     (*(int *)(Sensor3_temp + (uint)param_1 * 4) != 0)) {
    *(undefined4 *)(lowest_temp + (uint)param_1 * 4) =
         *(undefined4 *)(Sensor3_temp + (uint)param_1 * 4);
  }
  if (*(int *)(gGlobalHighestTemp + (uint)param_1 * 4) < *(int *)(highest_temp + (uint)param_1 * 4))
  {
    *(undefined4 *)(gGlobalHighestTemp + (uint)param_1 * 4) =
         *(undefined4 *)(highest_temp + (uint)param_1 * 4);
  }
  printf("\ngGlobalHighestTemp is %d\n\n",*(undefined4 *)(gGlobalHighestTemp + (uint)param_1 * 4));
  if ((int)(uint)Conf[214] < *(int *)(highest_temp + (uint)param_1 * 4)) {
    *(undefined *)((int)&gHigherThanAlarmTemp + (uint)param_1) = 1;
  }
  uVar2 = *(int *)(highest_temp + (uint)param_1 * 4) - *(int *)(lowest_temp + (uint)param_1 * 4);
  if (((uint)Conf._220_4_ < uVar2) &&
     (*(undefined *)((int)&gHigherThanMaxTempGap + (uint)param_1) = 1,
     *(int *)(gMaxTempGap_value + (uint)param_1 * 4) < (int)uVar2)) {
    *(uint *)(gMaxTempGap_value + (uint)param_1 * 4) = uVar2;
    printf("gMaxTempGap_value is %d\n\n",*(undefined4 *)(gMaxTempGap_value + (uint)param_1 * 4));
  }
  return;
}


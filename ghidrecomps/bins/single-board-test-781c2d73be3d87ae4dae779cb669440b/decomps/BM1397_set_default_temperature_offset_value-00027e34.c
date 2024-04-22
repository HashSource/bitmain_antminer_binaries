
/* WARNING: Unknown calling convention */

void BM1397_set_default_temperature_offset_value(uchar which_chain)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_40;
  
  printf("\n--- %s\n",DAT_000280ac);
  iVar8 = 1;
  iVar6 = 0;
  local_40 = 0;
  bVar2 = 0;
  do {
    uVar5 = Conf.TempSensor1;
    bVar4 = gT1_offset_value;
    if ((iVar6 == 0) || (uVar5 = Conf.TempSensor2, bVar4 = gT2_offset_value, iVar6 == 1)) {
      uVar7 = gSensor_i2c_addr_high_4_bit | 0x1011100 | (uint)bVar4;
      local_40 = uVar5;
    }
    else if (iVar6 == 2) {
      uVar7 = gSensor_i2c_addr_high_4_bit | 0x1011100 | (uint)(byte)gT3_offset_value;
      local_40 = Conf.TempSensor3;
      bVar4 = gT3_offset_value;
    }
    else {
      uVar7 = 0;
      bVar4 = bVar2;
    }
    if (local_40 == 0) {
LAB_00027eba:
      if (iVar8 == 3) {
        return;
      }
    }
    else {
      cVar1 = (char)local_40 + -1;
      uVar5 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',
                        gBM1397_MISC_CONTROL_reg | 0x4030,false);
      check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',false);
      do {
        uVar5 = uVar5 + 1;
        uVar3 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
        if ((uVar3 & 0xc0000000) == 0) break;
      } while (uVar5 < read_loop);
      uVar5 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',uVar7,false);
      do {
        uVar5 = uVar5 + 1;
        uVar7 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
        if ((uVar7 & 0xc0000000) == 0) break;
      } while (uVar5 < read_loop);
      uVar5 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefeeeff | 0x1001100,false);
      do {
        uVar5 = uVar5 + 1;
        uVar7 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
        if ((uVar7 & 0xc0000000) == 0) break;
      } while (uVar5 < read_loop);
      if (bVar4 == (byte)uVar7) goto LAB_00027eba;
      if (iVar6 == 0) {
        Sensor1_OK = '\0';
        puts("!!! sensor1 is error!\n");
        goto LAB_00027eba;
      }
      if (iVar6 != 1) {
        if (iVar6 == 2) {
          Sensor3_OK = '\0';
          (*(code *)PTR_puts_0003015c)("!!! sensor3 is error!\n");
          return;
        }
        goto LAB_00027eba;
      }
      Sensor2_OK = '\0';
      puts("!!! sensor2 is error!\n");
    }
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 1;
    bVar2 = bVar4;
  } while( true );
}


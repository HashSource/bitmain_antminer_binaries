
/* WARNING: Unknown calling convention */

void BM1397_get_temperature_offset_value_from_asic(uchar which_chain)

{
  uchar uVar1;
  uchar uVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  uint which_sensor;
  int local_3c;
  int local_38;
  undefined4 local_34;
  uchar offset_value [8];
  
  local_34 = &gBM1397_MISC_CONTROL_reg;
  local_38 = 0;
  iVar9 = 0;
  local_3c = 0;
  offset_value[0] = '\0';
  offset_value[1] = '\0';
  offset_value[2] = '\0';
  offset_value[3] = '\0';
  offset_value[4] = '\0';
  offset_value[5] = '\0';
  offset_value[6] = '\0';
  offset_value[7] = '\0';
  printf("\n--- %s\n",DAT_00027e24);
  do {
    uVar8 = Conf.TempSensor1;
    if ((iVar9 != 0) && (uVar8 = Conf.TempSensor2, iVar9 != 1)) {
      uVar8 = Conf.TempSensor3;
    }
    if (uVar8 != 0) {
      uVar2 = (uchar)uVar8;
      cVar3 = uVar2 + 0xff;
      uVar8 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar3,'\x18',*local_34 | 0x4030,
                        false);
      check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar3,'\x18',false);
      do {
        uVar8 = uVar8 + 1;
        uVar5 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar3,'\x1c',false);
        if ((uVar5 & 0xc0000000) == 0) break;
      } while (uVar8 < read_loop);
      uVar8 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar3,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefefeff | 0x1000100,false);
      do {
        uVar8 = uVar8 + 1;
        uVar5 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar3,'\x1c',false);
        if ((uVar5 & 0xc0000000) == 0) {
          local_38 = (uVar5 & 0xff) - 0x40;
          printf("\nASIC temperature is %d\n",local_38);
          goto LAB_00027cf8;
        }
      } while (uVar8 < read_loop);
      gNotReadOutTemp = true;
      printf("%s: Can\'t read out ASIC TEMP. ret = 0x%08x\n",DAT_00027e24,uVar5);
LAB_00027cf8:
      uVar8 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar3,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefeffff | 0x1000000,false);
      do {
        uVar8 = uVar8 + 1;
        uVar5 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar3,'\x1c',false);
        if ((uVar5 & 0xc0000000) == 0) {
          local_3c = (uVar5 & 0xff) - 0x40;
          printf("\nPCB temperature is %d\n",local_3c);
          goto LAB_00027d58;
        }
      } while (uVar8 < read_loop);
      gNotReadOutTemp = true;
      printf("%s: Can\'t read out HASH BOARD TEMP. ret = 0x%08x\n",DAT_00027e24,uVar5);
LAB_00027d58:
      if (gNotReadOutTemp == false) {
        uVar5 = (uint)(char)(local_3c - local_38);
        uVar8 = local_3c - local_38 & 0xff;
      }
      else {
        uVar5 = 0;
        uVar8 = uVar5;
      }
      cVar3 = (char)uVar5;
      cVar4 = (char)uVar8;
      if (iVar9 == 0) {
        uVar1 = *DAT_00027e2c;
        gT1_offset_value = cVar3;
        *DAT_00027e2c = cVar4 + uVar1;
        offset_value[1] = cVar4 + uVar1;
        offset_value[0] = uVar2;
      }
      else if (iVar9 == 1) {
        offset_value[2] = uVar2;
        uVar2 = *DAT_00027e30;
        gT2_offset_value = cVar3;
        *DAT_00027e30 = cVar4 + uVar2;
        offset_value[3] = cVar4 + uVar2;
      }
      else {
        uVar1 = *DAT_00027e28;
        gT3_offset_value = cVar3;
        *DAT_00027e28 = cVar4 + uVar1;
        offset_value._4_2_ = CONCAT11(cVar4 + uVar1,uVar2);
      }
      printf("\ntemp_offset_value = %d\n",uVar5);
    }
    iVar9 = iVar9 + 1;
    if (iVar9 == 3) {
      pbVar7 = (byte *)((int)&local_34 + 3);
      offset_value._4_3_ = CONCAT12((char)Conf.sensor_model,(short)offset_value._4_4_) | 0x200000;
      offset_value[7] = '\0';
      putchar(10);
      iVar9 = 0;
      do {
        pbVar7 = pbVar7 + 1;
        iVar6 = iVar9 + 1;
        printf("offset_value[%d] = %d\n",iVar9,(uint)*pbVar7);
        iVar9 = iVar6;
      } while (iVar6 != 8);
      if ((pattern_test_time == '\0') && (Conf.AsicNum != 1)) {
        AT24C02_save_offset_value(gI2c,gChain,offset_value);
      }
      return;
    }
  } while( true );
}


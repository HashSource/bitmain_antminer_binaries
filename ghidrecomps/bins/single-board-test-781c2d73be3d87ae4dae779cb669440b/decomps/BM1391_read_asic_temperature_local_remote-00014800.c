
/* WARNING: Unknown calling convention */

void BM1391_read_asic_temperature_local_remote(uchar which_chain)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  uint which_sensor;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  uint local_44;
  int local_38;
  int *local_34;
  
  local_38 = 0;
  iVar10 = 0;
  local_34 = &Sensor2_temp;
  puVar11 = DAT_00014bac;
  do {
    if (iVar10 == 0) {
      local_44 = Conf.TempSensor1;
    }
    else {
      local_44 = Conf.TempSensor2;
      if (iVar10 != 1) {
        local_44 = Conf.TempSensor3;
      }
    }
    if (local_44 != 0) {
      cVar2 = (char)local_44 + -1;
      uVar6 = 0;
      BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x18',
                        gBM1391_MISC_CONTROL_reg | 0x4030,false);
      check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x18',false);
      do {
        uVar6 = uVar6 + 1;
        uVar4 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) break;
      } while (uVar6 < read_loop);
      uVar6 = 0;
      BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefefeff | 0x1000100,false);
      do {
        uVar6 = uVar6 + 1;
        uVar4 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) {
          local_38 = (uVar4 & 0xff) - 0x40;
          printf("\nASIC %d TEMP is : %d\n",local_44,local_38);
          iVar7 = local_38;
          if (iVar10 != 0) {
            piVar5 = local_34;
            if (iVar10 != 1) {
              piVar5 = &Sensor3_temp;
            }
            *piVar5 = local_38;
            iVar7 = Sensor1_temp;
          }
          Sensor1_temp = iVar7;
          if (local_44 == Conf.StartSensor) {
            if (local_38 < Conf.StartTemp) {
              if (gStartTest == false) {
                printf("\nASIC %d temperature is %d, waiting it raise to start temperature %d\n\n",
                       local_44,local_38);
              }
            }
            else {
              if (gStartTest == false) {
                printf("\nBegin test!!! Start sensor is %d, ASIC temperature is %d\n\n",local_44);
              }
              gStartTest = true;
            }
          }
          goto LAB_00014a70;
        }
      } while (uVar6 < read_loop);
      printf("\n!!! %s: do not read out ASIC %d temperature\n\n",DAT_00014ba8,local_44);
      gNotReadOutTemp = true;
      *puVar11 = 0;
LAB_00014a70:
      uVar6 = 0;
      BM1391_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefeffff | 0x1000000,false);
      do {
        uVar6 = uVar6 + 1;
        uVar4 = check_BM1391_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) {
          iVar7 = (uVar4 & 0xff) - 0x40;
          printf("\nASIC %d Hash Board temperature is %d\n\n",local_44,iVar7);
          printf("temp_offset_value = %d\n\n",(int)(char)((char)iVar7 - (char)local_38));
          goto LAB_0001486e;
        }
      } while (uVar6 < read_loop);
      printf("\n!!! %s: do not read out ASIC %d Hash Board temperature\n\n",DAT_00014ba8,local_44);
      gNotReadOutTemp = true;
      *puVar11 = 0;
    }
LAB_0001486e:
    iVar8 = Sensor3_temp;
    iVar9 = Sensor2_temp;
    iVar7 = Sensor1_temp;
    iVar10 = iVar10 + 1;
    puVar11 = puVar11 + 1;
    if (iVar10 == 3) {
      iVar10 = Sensor1_temp;
      temp_change = __udivsi3((((Sensor1_temp + Sensor2_temp + Sensor3_temp) - last_Sensor1_temp) -
                              last_Sensor2_temp) - last_Sensor3_temp,gSensor_number);
      if (temp_change != 0) {
        last_Sensor1_temp = iVar10;
        last_Sensor2_temp = iVar9;
        last_Sensor3_temp = iVar8;
      }
      if (highest_temp < iVar7) {
        highest_temp = iVar10;
      }
      if (highest_temp < iVar9) {
        highest_temp = iVar9;
      }
      if (highest_temp < iVar8) {
        highest_temp = iVar8;
      }
      iVar3 = highest_temp;
      piVar5 = (int *)0xe78;
      bVar14 = iVar9 == 0;
      iVar10 = iVar9;
      if (!bVar14) {
        iVar10 = iVar7 - iVar9;
      }
      bVar12 = iVar10 < 0;
      bVar1 = iVar7 != iVar9;
      bVar13 = !bVar14 && SBORROW4(iVar7,iVar9);
      if ((bVar14 || !bVar1) || bVar12 != bVar13) {
        piVar5 = &lowest_temp;
      }
      if ((!bVar14 && bVar1) && bVar12 == bVar13) {
        piVar5 = (int *)((uint)piVar5 & 0xffff | 0x230000);
      }
      if ((!bVar14 && bVar1) && bVar12 == bVar13) {
        iVar7 = iVar9;
      }
      if ((bVar14 || !bVar1) || bVar12 != bVar13) {
        *piVar5 = iVar7;
      }
      if ((!bVar14 && bVar1) && bVar12 == bVar13) {
        *piVar5 = iVar9;
      }
      iVar10 = iVar8;
      if (iVar8 != 0) {
        iVar10 = iVar8 - iVar7;
      }
      if (iVar10 < 0 != (iVar8 != 0 && SBORROW4(iVar8,iVar7))) {
        *piVar5 = iVar8;
        iVar7 = iVar8;
      }
      if (gGlobalHighestTemp < iVar3) {
        gGlobalHighestTemp = iVar3;
      }
      uVar6 = iVar3 - iVar7;
      if (Conf.AlarmTemp < iVar3) {
        gHigherThanAlarmTemp = true;
      }
      if ((Conf.MaxTempGap < uVar6) &&
         (gHigherThanMaxTempGap = true, gMaxTempGap_value < (int)uVar6)) {
        gMaxTempGap_value = uVar6;
        (*(code *)PTR_printf_00030118)("gMaxTempGap_value is %d\n\n",uVar6);
        return;
      }
      return;
    }
  } while( true );
}


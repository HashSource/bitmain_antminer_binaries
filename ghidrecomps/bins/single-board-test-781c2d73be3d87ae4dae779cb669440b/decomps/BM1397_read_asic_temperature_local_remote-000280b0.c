
/* WARNING: Unknown calling convention */

void BM1397_read_asic_temperature_local_remote(uchar which_chain)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint which_sensor;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined *local_48;
  int *local_38;
  
  local_48 = DAT_000283d4;
  iVar12 = 0;
  local_38 = &Sensor3_temp;
  do {
    uVar6 = Conf.TempSensor3;
    if (((iVar12 != 2) && (uVar6 = Conf.TempSensor4, iVar12 != 3)) &&
       (uVar6 = Conf.TempSensor1, iVar12 == 1)) {
      uVar6 = Conf.TempSensor2;
    }
    if (uVar6 != 0) {
      cVar2 = (char)uVar6 + -1;
      uVar11 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x18',
                        gBM1397_MISC_CONTROL_reg | 0x4030,false);
      check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x18',false);
      do {
        uVar11 = uVar11 + 1;
        uVar4 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) break;
      } while (uVar11 < read_loop);
      uVar11 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefefeff | 0x1000100,false);
      do {
        uVar11 = uVar11 + 1;
        uVar4 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) {
          iVar8 = (uVar4 & 0xff) - 0x40;
          printf("\nASIC %d TEMP is : %d\n",uVar6,iVar8);
          iVar7 = iVar8;
          iVar9 = Sensor2_temp;
          if ((iVar12 != 0) && (iVar7 = Sensor1_temp, iVar9 = iVar8, iVar12 != 1)) {
            piVar5 = local_38;
            if (iVar12 != 2) {
              piVar5 = &Sensor4_temp;
            }
            *piVar5 = iVar8;
            iVar7 = Sensor1_temp;
            iVar9 = Sensor2_temp;
          }
          Sensor2_temp = iVar9;
          Sensor1_temp = iVar7;
          if (uVar6 == Conf.StartSensor) {
            if (iVar8 < Conf.StartTemp) {
              if (gStartTest == false) {
                printf("\nASIC %d temperature is %d, waiting it raise to start temperature %d\n\n",
                       uVar6,iVar8);
              }
            }
            else {
              if (gStartTest == false) {
                printf("\nBegin test!!! Start sensor is %d, ASIC temperature is %d\n\n",uVar6,iVar8)
                ;
              }
              gStartTest = true;
            }
          }
          goto LAB_00028376;
        }
      } while (uVar11 < read_loop);
      printf("\n!!! %s: do not read out ASIC %d temperature\n\n",DAT_0002849c,uVar6);
      gNotReadOutTemp = true;
      *local_48 = 0;
LAB_00028376:
      uVar11 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefeffff | 0x1000000,false);
      do {
        uVar11 = uVar11 + 1;
        uVar4 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar2,'\x1c',false);
        if ((uVar4 & 0xc0000000) == 0) {
          printf("\nASIC %d Hash Board temperature is %d\n\n",uVar6,(uVar4 & 0xff) - 0x40);
          goto LAB_0002812e;
        }
      } while (uVar11 < read_loop);
      printf("\n!!! %s: do not read out ASIC %d Hash Board temperature\n\n",DAT_0002849c,uVar6);
      gNotReadOutTemp = true;
      *local_48 = 0;
    }
LAB_0002812e:
    iVar10 = Sensor4_temp;
    iVar8 = Sensor3_temp;
    iVar9 = Sensor2_temp;
    iVar7 = Sensor1_temp;
    iVar12 = iVar12 + 1;
    local_48 = local_48 + 1;
    if (iVar12 == 4) {
      iVar12 = Sensor1_temp;
      temp_change = __udivsi3(((((Sensor1_temp + Sensor2_temp + Sensor3_temp + Sensor4_temp) -
                                last_Sensor1_temp) - last_Sensor2_temp) - last_Sensor3_temp) -
                              last_Sensor4_temp,gSensor_number);
      if (temp_change != 0) {
        last_Sensor1_temp = iVar12;
        last_Sensor2_temp = iVar9;
        last_Sensor3_temp = iVar8;
        last_Sensor4_temp = iVar10;
      }
      piVar5 = (int *)0xe78;
      if (highest_temp < iVar7) {
        highest_temp = iVar12;
      }
      if (highest_temp < iVar9) {
        highest_temp = iVar9;
      }
      if (highest_temp < iVar8) {
        highest_temp = iVar8;
      }
      if (highest_temp < iVar10) {
        highest_temp = iVar10;
      }
      iVar3 = highest_temp;
      bVar15 = iVar9 == 0;
      iVar12 = iVar9;
      if (!bVar15) {
        iVar12 = iVar7 - iVar9;
      }
      bVar13 = iVar12 < 0;
      bVar1 = iVar7 != iVar9;
      bVar14 = !bVar15 && SBORROW4(iVar7,iVar9);
      if ((bVar15 || !bVar1) || bVar13 != bVar14) {
        piVar5 = &lowest_temp;
      }
      if ((!bVar15 && bVar1) && bVar13 == bVar14) {
        piVar5 = (int *)((uint)piVar5 & 0xffff | 0x230000);
      }
      if ((!bVar15 && bVar1) && bVar13 == bVar14) {
        iVar7 = iVar9;
      }
      if ((bVar15 || !bVar1) || bVar13 != bVar14) {
        *piVar5 = iVar7;
      }
      if ((!bVar15 && bVar1) && bVar13 == bVar14) {
        *piVar5 = iVar9;
      }
      uVar6 = iVar8;
      if (iVar8 != 0) {
        uVar6 = 1;
      }
      iVar12 = iVar8;
      if (iVar8 != 0) {
        iVar12 = iVar8 - iVar7;
      }
      if (iVar12 < 0 != (iVar8 != 0 && SBORROW4(iVar8,iVar7))) {
        *piVar5 = iVar8;
        iVar7 = iVar8;
      }
      if (iVar10 < iVar7) {
        uVar6 = uVar6 & 1;
      }
      else {
        uVar6 = 0;
      }
      if (uVar6 != 0) {
        *piVar5 = iVar10;
        iVar7 = iVar10;
      }
      uVar6 = iVar3 - iVar7;
      if (gGlobalHighestTemp < iVar3) {
        gGlobalHighestTemp = iVar3;
      }
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


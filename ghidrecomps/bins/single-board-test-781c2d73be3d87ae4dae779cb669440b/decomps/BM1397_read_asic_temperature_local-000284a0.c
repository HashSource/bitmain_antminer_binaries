
/* WARNING: Unknown calling convention */

void BM1397_read_asic_temperature_local(uchar which_chain)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint which_sensor;
  
  iVar5 = 0;
  do {
    uVar6 = Conf.TempSensor1;
    if (((iVar5 != 0) && (uVar6 = Conf.TempSensor2, iVar5 != 1)) &&
       (uVar6 = Conf.TempSensor3, iVar5 != 2)) {
      uVar6 = Conf.TempSensor4;
    }
    if (uVar6 != 0) {
      cVar1 = (char)uVar6 + -1;
      uVar3 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',
                        gBM1397_MISC_CONTROL_reg | 0x4030,false);
      check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x18',false);
      do {
        uVar3 = uVar3 + 1;
        uVar2 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
        if ((uVar2 & 0xc0000000) == 0) break;
      } while (uVar3 < read_loop);
      uVar3 = 0;
      BM1397_set_config(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',
                        gSensor_i2c_addr_high_4_bit & 0xfefeffff | 0x1000000,false);
      do {
        uVar3 = uVar3 + 1;
        uVar2 = check_BM1397_asic_reg(which_chain,(char)gChain_Asic_Interval * cVar1,'\x1c',false);
        if ((uVar2 & 0xc0000000) == 0) {
          iVar4 = (uVar2 & 0xff) - 0x40;
          if (highest_temp < iVar4) {
            highest_temp = iVar4;
          }
          if (iVar5 == 0) {
            if (iVar4 == -0x40) {
LAB_000286ce:
              iVar4 = 0;
            }
            else {
              uVar3 = gSensor_read_ok_counter[which_chain][0];
              Sensor1_temp = iVar4;
              gSensor_OK[which_chain][0] = true;
              gSensor_read_ok_counter[which_chain][0] = uVar3 + 1;
            }
LAB_0002861e:
            printf("\nASIC %d Hash Board temperature is %d\n",uVar6,iVar4);
            if (uVar6 != Conf.StartSensor) goto LAB_000284fa;
          }
          else {
            if (iVar5 == 1) {
              if (iVar4 == -0x40) goto LAB_000286ce;
              uVar3 = gSensor_read_ok_counter[which_chain][1];
              Sensor2_temp = iVar4;
              gSensor_OK[which_chain][1] = true;
              gSensor_read_ok_counter[which_chain][1] = uVar3 + 1;
              goto LAB_0002861e;
            }
            if (iVar5 == 2) {
              if (iVar4 == -0x40) goto LAB_000286ce;
              uVar3 = gSensor_read_ok_counter[which_chain][2];
              Sensor3_temp = iVar4;
              gSensor_OK[which_chain][2] = true;
              gSensor_read_ok_counter[which_chain][2] = uVar3 + 1;
              goto LAB_0002861e;
            }
            if (iVar4 != -0x40) {
              uVar3 = gSensor_read_ok_counter[which_chain][3];
              Sensor4_temp = iVar4;
              gSensor_OK[which_chain][3] = true;
              gSensor_read_ok_counter[which_chain][3] = uVar3 + 1;
              goto LAB_0002861e;
            }
            printf("\nASIC %d Hash Board temperature is %d\n",uVar6,0);
            if (uVar6 != Conf.StartSensor) {
              return;
            }
            iVar4 = 0;
          }
          if (iVar4 < Conf.StartTemp) {
            if (gStartTest == false) {
              printf("\nASIC %d Hash Board temperature is %d, waiting it raise to start temperature %d\n\n"
                     ,uVar6,iVar4);
            }
          }
          else {
            if (gStartTest == false) {
              printf("\nBegin test!!! Start sensor is %d, Hash Board temperature is %d\n\n",uVar6,
                     iVar4);
            }
            gStartTest = true;
          }
          goto LAB_000284fa;
        }
      } while (uVar3 < read_loop);
      printf("%s: do not read out ASIC %d Hash Boardtemperature. ret = 0x%08x\n\n",DAT_00028730,
             uVar6,uVar2);
      gNotReadOutTemp = true;
    }
LAB_000284fa:
    iVar5 = iVar5 + 1;
    if (iVar5 == 4) {
      return;
    }
  } while( true );
}


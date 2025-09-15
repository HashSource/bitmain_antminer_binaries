
int8_t do_calibration_sensor_offset(uchar device,uchar chip_addr,int chain,int temp_chip_index)

{
  char cVar1;
  char cVar2;
  uchar data;
  int16_t iVar3;
  uint uVar4;
  FILE *pFVar5;
  int iVar6;
  int temp_chip_index_local;
  int chain_local;
  uchar chip_addr_local;
  uchar device_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int8_t middle;
  int16_t ret;
  int8_t local;
  int8_t offset;
  int wait_times;
  
  wait_times = 0;
  device_local = device;
  if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
     (dev->TempChipType[chain][temp_chip_index] != 'U')) {
    DEVICEADDR[chain] = -0x68;
    device_local = DEVICEADDR[chain];
    uVar4 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
    dev->TempChipType[chain][temp_chip_index] = (uchar)uVar4;
    if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
       (dev->TempChipType[chain][temp_chip_index] != 'U')) {
      DEVICEADDR[chain] = -0x66;
      device_local = DEVICEADDR[chain];
      uVar4 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
      dev->TempChipType[chain][temp_chip_index] = (uchar)uVar4;
      if ((dev->TempChipType[chain][temp_chip_index] != '\x1a') &&
         (dev->TempChipType[chain][temp_chip_index] != 'U')) {
        DEVICEADDR[chain] = -100;
        device_local = DEVICEADDR[chain];
        uVar4 = check_reg_temp(device_local,0xfe,'\0','\0',chip_addr,chain);
        dev->TempChipType[chain][temp_chip_index] = (uchar)uVar4;
      }
    }
  }
  if (dev->TempChipType[chain][temp_chip_index] == '\x1a') {
    is218_Temp = true;
  }
  check_reg_temp(device_local,9,'\x04','\x01',chip_addr,chain);
  do {
    check_reg_temp(device_local,0x11,'\0','\x01',chip_addr,chain);
    uVar4 = check_reg_temp(device_local,0,'\0','\0',chip_addr,chain);
    iVar3 = get_local((ushort)uVar4 & 0xff);
    cVar2 = (char)iVar3;
    uVar4 = check_reg_temp(device_local,1,'\0','\0',chip_addr,chain);
    cVar1 = (char)uVar4 + -0x40;
    if (cVar2 < ')') {
      iVar6 = (int)cVar2 - (int)cVar1;
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 8) {
LAB_0001563e:
        if ((2 < wait_times) && (3 < log_level)) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: calibrate at risk...\n","temperature.c",0x195,
                    "do_calibration_sensor_offset");
          }
          fclose(pFVar5);
        }
        data = calc_offset_simple((int)cVar1,(int)cVar2);
        check_reg_temp(device_local,0x11,data,'\x01',chip_addr,chain);
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar5 = fopen(log_file,"a+");
          if (pFVar5 != (FILE *)0x0) {
            fprintf(pFVar5,"%s:%d:%s: Chain[%d] Chip[%d]:local:%hhd remote:%hhd offset:%hhd \n",
                    "temperature.c",0x1a9,"do_calibration_sensor_offset",chain,(chip_addr >> 2) + 1,
                    (int)cVar2,(int)cVar1,(int)(char)data);
          }
          fclose(pFVar5);
        }
        return data;
      }
    }
    if (2 < wait_times) goto LAB_0001563e;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar5 = fopen(log_file,"a+");
      if (pFVar5 != (FILE *)0x0) {
        fprintf(pFVar5,"%s:%d:%s: too hot! local:%d, remote:%d,  wait 20s......\n","temperature.c",
                0x18d,"do_calibration_sensor_offset",(int)cVar2,(int)cVar1);
      }
      fclose(pFVar5);
    }
    set_PWM('d');
    sleep(0x14);
    wait_times = wait_times + 1;
  } while( true );
}


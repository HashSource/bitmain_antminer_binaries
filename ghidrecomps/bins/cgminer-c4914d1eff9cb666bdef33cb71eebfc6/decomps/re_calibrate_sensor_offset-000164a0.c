
int8_t re_calibrate_sensor_offset(uchar device,int chain)

{
  uchar chain_00;
  _Bool _Var1;
  int8_t iVar2;
  FILE *pFVar3;
  int chain_local;
  uchar device_local;
  int8_t sensor_offset [4];
  uint8_t sensor_pos [4];
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_5;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  uint32_t sensor_num;
  TEMP_SENSOR_TYPE sensor_type;
  int i;
  
  sensor_pos[0] = '\0';
  sensor_pos[1] = '\0';
  sensor_pos[2] = '\0';
  sensor_pos[3] = '\0';
  sensor_offset[0] = '\0';
  sensor_offset[1] = '\0';
  sensor_offset[2] = '\0';
  sensor_offset[3] = '\0';
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: start to calibrate the temp senosr offset value\n","temperature.c",
              0x298,"re_calibrate_sensor_offset");
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: chain[%d] temp chip I2C addr=0x%02x\n","temperature.c",0x29a,
              "re_calibrate_sensor_offset",chain,(uint)device);
    }
    fclose(pFVar3);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Warning: Chain[%d] has no temp offset in PIC! will fix it\n",
              "temperature.c",0x29d,"re_calibrate_sensor_offset",chain);
    }
    fclose(pFVar3);
  }
  sensor_type = TMP451;
  sensor_num = 2;
  _Var1 = is_T11();
  if (_Var1) {
    sensor_pos[0] = '\x1f';
    sensor_pos[1] = '(';
  }
  else {
    sensor_pos[0] = '\x1f';
    sensor_pos[1] = '(';
    sensor_pos[2] = '\0';
    sensor_pos[3] = '\0';
  }
  dev->chain_asic_temp_num[chain] = '\x02';
  for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
    dev->TempChipAddr[chain][i] = (sensor_pos[i] + '?') * '\x04';
  }
  for (i = 0; chain_00 = (uchar)chain, i < dev->chain_asic_temp_num[chain]; i = i + 1) {
    set_misc_control(chain_00,'\0',dev->TempChipAddr[chain][i],1);
    check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Chain[%d] use default temp chip[%d] \n","temperature.c",0x2c0,
                "re_calibrate_sensor_offset",chain,(dev->TempChipAddr[chain][i] >> 2) + 1);
      }
      fclose(pFVar3);
    }
    iVar2 = do_calibration_sensor_offset(device,dev->TempChipAddr[chain][i],chain,i);
    middle_Offset[chain][i] = iVar2;
    sensor_offset[i] = middle_Offset[chain][i];
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: Chain[%d] Chip[%d] get middle temp offset=%d typeID=%02x\n",
                "temperature.c",0x2c5,"re_calibrate_sensor_offset",chain,
                (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                (uint)dev->TempChipType[chain][i]);
      }
      fclose(pFVar3);
    }
  }
  _Var1 = eeprom_set_temp_sensor_type(chain_00,sensor_type);
  if (!_Var1) {
    stop_scan(3,chain_00);
  }
  _Var1 = eeprom_set_temp_sensor_num(chain_00,(uint8_t)sensor_num);
  if (!_Var1) {
    stop_scan(3,chain_00);
  }
  _Var1 = eeprom_set_temp_sensor_pos(chain_00,sensor_pos,sensor_num);
  if (!_Var1) {
    stop_scan(3,chain_00);
  }
  _Var1 = eeprom_set_temp_sensor_data(chain_00,(uint8_t *)sensor_offset,sensor_num);
  if (!_Var1) {
    stop_scan(3,chain_00);
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: temp sensor info save,done!\n","temperature.c",0x2d5,
              "re_calibrate_sensor_offset");
    }
    fclose(pFVar3);
  }
  return '\0';
}


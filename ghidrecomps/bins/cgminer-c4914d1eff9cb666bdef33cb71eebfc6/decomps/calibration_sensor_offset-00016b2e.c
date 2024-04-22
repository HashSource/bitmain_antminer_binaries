
int8_t calibration_sensor_offset(uchar device,int chain)

{
  temp_info_t temp_info;
  temp_info_t temp_info_00;
  _Bool _Var1;
  FILE *pFVar2;
  uint uVar3;
  TEMP_SENSOR_TYPE TVar4;
  int in_stack_ffffff9c;
  uint in_stack_ffffffa0;
  undefined4 in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  int chain_local;
  uchar device_local;
  int8_t sensor_pos [4];
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  FILE *pFile_1;
  uint32_t ret;
  int i;
  
  sensor_pos[0] = '\0';
  sensor_pos[1] = '\0';
  sensor_pos[2] = '\0';
  sensor_pos[3] = '\0';
  check_eeprom_calibration_data(chain);
  temp_info.num = in_stack_ffffff9c;
  temp_info.type = *(undefined4 *)(::temp_info[chain].offset + 2);
  temp_info.pos[0] = (char)in_stack_ffffffa0;
  temp_info.pos[1] = (char)(in_stack_ffffffa0 >> 8);
  temp_info.pos[2] = (char)(in_stack_ffffffa0 >> 0x10);
  temp_info.pos[3] = (char)(in_stack_ffffffa0 >> 0x18);
  temp_info.pos[4] = (char)in_stack_ffffffa4;
  temp_info.pos[5] = (char)((uint)in_stack_ffffffa4 >> 8);
  temp_info.offset[0] = (char)((uint)in_stack_ffffffa4 >> 0x10);
  temp_info.offset[1] = (char)((uint)in_stack_ffffffa4 >> 0x18);
  temp_info.offset[2] = (char)in_stack_ffffffa8;
  temp_info.offset[3] = (char)((uint)in_stack_ffffffa8 >> 8);
  temp_info.offset[4] = (char)((uint)in_stack_ffffffa8 >> 0x10);
  temp_info.offset[5] = (char)((uint)in_stack_ffffffa8 >> 0x18);
  _Var1 = is_tempsensor_data_correct(temp_info);
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        in_stack_ffffff9c = chain;
        fprintf(pFVar2,"%s:%d:%s: chain[%d] temp info,OK\n","temperature.c",0x2f7,
                "calibration_sensor_offset");
      }
      fclose(pFVar2);
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        in_stack_ffffff9c = chain;
        fprintf(pFVar2,"%s:%d:%s: chain[%d] temp info,Bad. Reload from eeprom..\n","temperature.c",
                0x2f2,"calibration_sensor_offset");
      }
      fclose(pFVar2);
    }
    get_temp_info_from_eeprom_by_chain(chain);
  }
  TVar4 = ::temp_info[chain].type;
  if (TVar4 == TMP441B) {
    DEVICEADDR[chain] = -0x66;
  }
  else if (TVar4 == TMP411C) {
    DEVICEADDR[chain] = -100;
  }
  else if (TVar4 == TMP451) {
    DEVICEADDR[chain] = -0x68;
  }
  else {
    DEVICEADDR[chain] = -0x68;
  }
  device_local = DEVICEADDR[chain];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      in_stack_ffffffa0 = (uint)device_local;
      in_stack_ffffff9c = chain;
      fprintf(pFVar2,"%s:%d:%s: chain[%d] temp chip I2C addr=0x%02x\n","temperature.c",0x30c,
              "calibration_sensor_offset");
    }
    fclose(pFVar2);
  }
  if (((::temp_info[chain].type != TMP451) && (::temp_info[chain].type != TMP461)) &&
     (chip_hasNoMiddle = true, 3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      in_stack_ffffff9c = chain;
      fprintf(pFVar2,"%s:%d:%s: chain[%d] has no middle temp, use special fix mode.\n",
              "temperature.c",0x312,"calibration_sensor_offset");
    }
    fclose(pFVar2);
  }
  temp_info_00.num = in_stack_ffffff9c;
  temp_info_00.type = *(undefined4 *)(::temp_info[chain].offset + 2);
  temp_info_00.pos[0] = (char)in_stack_ffffffa0;
  temp_info_00.pos[1] = (char)(in_stack_ffffffa0 >> 8);
  temp_info_00.pos[2] = (char)(in_stack_ffffffa0 >> 0x10);
  temp_info_00.pos[3] = (char)(in_stack_ffffffa0 >> 0x18);
  temp_info_00.pos[4] = (char)in_stack_ffffffa4;
  temp_info_00.pos[5] = (char)((uint)in_stack_ffffffa4 >> 8);
  temp_info_00.offset[0] = (char)((uint)in_stack_ffffffa4 >> 0x10);
  temp_info_00.offset[1] = (char)((uint)in_stack_ffffffa4 >> 0x18);
  temp_info_00.offset[2] = (char)in_stack_ffffffa8;
  temp_info_00.offset[3] = (char)((uint)in_stack_ffffffa8 >> 8);
  temp_info_00.offset[4] = (char)((uint)in_stack_ffffffa8 >> 0x10);
  temp_info_00.offset[5] = (char)((uint)in_stack_ffffffa8 >> 0x18);
  _Var1 = is_tempsensor_data_correct(temp_info_00);
  if (_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: get temp info from eeprom,just use it!\n","temperature.c",0x318,
                "calibration_sensor_offset");
      }
      fclose(pFVar2);
    }
    dev->chain_asic_temp_num[chain] = (char)::temp_info[chain].num;
    for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
      dev->TempChipAddr[chain][i] = (uchar)(((int)::temp_info[chain].pos[i] - 1U & 0xff) << 2);
      middle_Offset[chain][i] = ::temp_info[chain].offset[i];
      set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][i],1);
      check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
      uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
      dev->TempChipType[chain][i] = (uchar)uVar3;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Chain[%d] chip[%d] use PIC middle temp offset=%d, typeID=%02x\n"
                  ,"temperature.c",0x329,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar2);
      }
      if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
         (dev->TempChipType[chain][i] != 'A')) {
        chip_hasNoMiddle = true;
        DEVICEADDR[chain] = -0x68;
        device_local = DEVICEADDR[chain];
        uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
        dev->TempChipType[chain][i] = (uchar)uVar3;
        if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
           (dev->TempChipType[chain][i] != 'A')) {
          DEVICEADDR[chain] = -0x66;
          device_local = DEVICEADDR[chain];
          uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
          dev->TempChipType[chain][i] = (uchar)uVar3;
          if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
             (dev->TempChipType[chain][i] != 'A')) {
            DEVICEADDR[chain] = -100;
            device_local = DEVICEADDR[chain];
            uVar3 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
            dev->TempChipType[chain][i] = (uchar)uVar3;
          }
        }
      }
      if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
         (dev->TempChipType[chain][i] != 'A')) {
        dev->chain_asic_temp_num[chain] = '\0';
        if (log_level < 4) {
          return '\0';
        }
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: wrong temp chip type!!!\n","temperature.c",0x353,
                  "calibration_sensor_offset");
        }
        fclose(pFVar2);
        return '\0';
      }
      if (dev->TempChipType[chain][i] != 'U') {
        is218_Temp = true;
      }
      do_calibration_sensor_offset_by_eeprom(device_local,dev->TempChipAddr[chain][i],chain,i);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Chain[%d] Chip[%d] get middle temp offset=%d typeID=%02x\n",
                  "temperature.c",0x35d,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar2);
      }
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Warning: Chain[%d] has no temp info ! we will fix it\n",
                "temperature.c",0x362,"calibration_sensor_offset",chain);
      }
      fclose(pFVar2);
    }
    dev->chain_asic_temp_num[chain] = '\x02';
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
    for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
      dev->TempChipAddr[chain][i] = (uchar)(((int)sensor_pos[i] - 1U & 0xff) << 2);
      middle_Offset[chain][i] = -5;
    }
    for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
      set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][i],1);
      check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Chain[%d] use default temp chip[%d] \n","temperature.c",0x382,
                  "calibration_sensor_offset",chain,(dev->TempChipAddr[chain][i] >> 2) + 1);
        }
        fclose(pFVar2);
      }
      do_calibration_sensor_offset_by_eeprom(device_local,dev->TempChipAddr[chain][i],chain,i);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Chain[%d] Chip[%d] get middle temp offset=%d typeID=%02x\n",
                  "temperature.c",0x387,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar2);
      }
    }
  }
  return '\0';
}


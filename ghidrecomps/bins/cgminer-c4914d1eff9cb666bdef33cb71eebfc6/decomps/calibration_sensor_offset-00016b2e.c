
int8_t calibration_sensor_offset(uchar device,int chain)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  _Bool _Var13;
  TEMP_SENSOR_TYPE TVar23;
  FILE *pFVar14;
  TEMP_SENSOR_TYPE TVar24;
  uint uVar15;
  uint32_t uVar25;
  uint32_t uVar26;
  char cVar27;
  char cVar28;
  char cVar31;
  char cVar32;
  char cVar35;
  char cVar36;
  char cVar39;
  char cVar40;
  temp_info_t *ptVar16;
  undefined4 uVar17;
  TEMP_SENSOR_TYPE TVar18;
  undefined4 uVar19;
  temp_info_t tVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined1 auVar41 [12];
  undefined1 auVar42 [12];
  undefined8 uVar43;
  undefined8 uVar44;
  undefined4 in_stack_00000000;
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
  undefined4 uVar29;
  undefined4 uVar30;
  undefined3 uVar33;
  undefined3 uVar34;
  undefined2 uVar37;
  undefined2 uVar38;
  
  sensor_pos[0] = '\0';
  sensor_pos[1] = '\0';
  sensor_pos[2] = '\0';
  sensor_pos[3] = '\0';
  check_eeprom_calibration_data(chain);
  ptVar16 = temp_info + chain;
  uVar1 = ptVar16->type;
  uVar2 = ptVar16->num;
  uVar3 = ptVar16->pos[0];
  uVar4 = ptVar16->pos[1];
  uVar5 = ptVar16->pos[2];
  uVar6 = ptVar16->pos[3];
  register0x0000002b = uVar6;
  register0x0000002a = uVar5;
  register0x00000029 = uVar4;
  register0x00000028 = uVar3;
  register0x00000024 = uVar2;
  TVar23 = uVar1;
  uVar17 = *(undefined4 *)(temp_info[chain].pos + 4);
  uVar21 = CONCAT44(in_stack_00000000,uVar17);
  tVar20 = (temp_info_t)CONCAT812(uVar21,auVar41);
  _Var13 = is_tempsensor_data_correct(tVar20);
  if (_Var13) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar14 = fopen(log_file,"a+");
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: chain[%d] temp info,OK\n","temperature.c",0x2f7,
                "calibration_sensor_offset",chain);
      }
      fclose(pFVar14);
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar14 = fopen(log_file,"a+");
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: chain[%d] temp info,Bad. Reload from eeprom..\n","temperature.c",
                0x2f2,"calibration_sensor_offset",chain);
      }
      fclose(pFVar14);
    }
    get_temp_info_from_eeprom_by_chain(chain);
  }
  TVar18 = temp_info[chain].type;
  if (TVar18 == TMP441B) {
    DEVICEADDR[chain] = -0x66;
  }
  else if (TVar18 == TMP411C) {
    DEVICEADDR[chain] = -100;
  }
  else if (TVar18 == TMP451) {
    DEVICEADDR[chain] = -0x68;
  }
  else {
    DEVICEADDR[chain] = -0x68;
  }
  device_local = DEVICEADDR[chain];
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar14 = fopen(log_file,"a+");
    if (pFVar14 != (FILE *)0x0) {
      fprintf(pFVar14,"%s:%d:%s: chain[%d] temp chip I2C addr=0x%02x\n","temperature.c",0x30c,
              "calibration_sensor_offset",chain,(uint)device_local);
    }
    fclose(pFVar14);
  }
  if (((temp_info[chain].type != TMP451) && (temp_info[chain].type != TMP461)) &&
     (chip_hasNoMiddle = true, 3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar14 = fopen(log_file,"a+");
    if (pFVar14 != (FILE *)0x0) {
      fprintf(pFVar14,"%s:%d:%s: chain[%d] has no middle temp, use special fix mode.\n",
              "temperature.c",0x312,"calibration_sensor_offset",chain);
    }
    fclose(pFVar14);
  }
  ptVar16 = temp_info + chain;
  uVar7 = ptVar16->type;
  uVar8 = ptVar16->num;
  uVar9 = ptVar16->pos[0];
  uVar10 = ptVar16->pos[1];
  uVar11 = ptVar16->pos[2];
  uVar12 = ptVar16->pos[3];
  register0x0000002b = uVar12;
  register0x0000002a = uVar11;
  register0x00000029 = uVar10;
  register0x00000028 = uVar9;
  register0x00000024 = uVar8;
  TVar24 = uVar7;
  uVar19 = *(undefined4 *)(temp_info[chain].pos + 4);
  in_stack_00000000 = in_stack_00000000;
  uVar22 = CONCAT44(in_stack_00000000,uVar19);
  tVar20 = (temp_info_t)CONCAT812(uVar22,auVar42);
  _Var13 = is_tempsensor_data_correct(tVar20);
  if (_Var13) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar14 = fopen(log_file,"a+");
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: get temp info from eeprom,just use it!\n","temperature.c",0x318,
                "calibration_sensor_offset");
      }
      fclose(pFVar14);
    }
    dev->chain_asic_temp_num[chain] = (char)temp_info[chain].num;
    for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
      dev->TempChipAddr[chain][i] = (temp_info[chain].pos[i] + -1) * '\x04';
      middle_Offset[chain][i] = temp_info[chain].offset[i];
      set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][i],1);
      check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
      uVar15 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
      dev->TempChipType[chain][i] = (uchar)uVar15;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar14 = fopen(log_file,"a+");
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,
                  "%s:%d:%s: Chain[%d] chip[%d] use PIC middle temp offset=%d, typeID=%02x\n",
                  "temperature.c",0x329,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar14);
      }
      if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
         (dev->TempChipType[chain][i] != 'A')) {
        chip_hasNoMiddle = true;
        DEVICEADDR[chain] = -0x68;
        device_local = DEVICEADDR[chain];
        uVar15 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
        dev->TempChipType[chain][i] = (uchar)uVar15;
        if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
           (dev->TempChipType[chain][i] != 'A')) {
          DEVICEADDR[chain] = -0x66;
          device_local = DEVICEADDR[chain];
          uVar15 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
          dev->TempChipType[chain][i] = (uchar)uVar15;
          if (((dev->TempChipType[chain][i] != '\x1a') && (dev->TempChipType[chain][i] != 'U')) &&
             (dev->TempChipType[chain][i] != 'A')) {
            DEVICEADDR[chain] = -100;
            device_local = DEVICEADDR[chain];
            uVar15 = check_reg_temp(device_local,0xfe,'\0','\0',dev->TempChipAddr[chain][i],chain);
            dev->TempChipType[chain][i] = (uchar)uVar15;
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
        pFVar14 = fopen(log_file,"a+");
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: wrong temp chip type!!!\n","temperature.c",0x353,
                  "calibration_sensor_offset");
        }
        fclose(pFVar14);
        return '\0';
      }
      if (dev->TempChipType[chain][i] != 'U') {
        is218_Temp = true;
      }
      do_calibration_sensor_offset_by_eeprom(device_local,dev->TempChipAddr[chain][i],chain,i);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar14 = fopen(log_file,"a+");
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: Chain[%d] Chip[%d] get middle temp offset=%d typeID=%02x\n",
                  "temperature.c",0x35d,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar14);
      }
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar14 = fopen(log_file,"a+");
      if (pFVar14 != (FILE *)0x0) {
        fprintf(pFVar14,"%s:%d:%s: Warning: Chain[%d] has no temp info ! we will fix it\n",
                "temperature.c",0x362,"calibration_sensor_offset",chain);
      }
      fclose(pFVar14);
    }
    dev->chain_asic_temp_num[chain] = '\x02';
    _Var13 = is_T11();
    if (_Var13) {
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
      dev->TempChipAddr[chain][i] = (sensor_pos[i] + -1) * '\x04';
      middle_Offset[chain][i] = -5;
    }
    for (i = 0; i < dev->chain_asic_temp_num[chain]; i = i + 1) {
      set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][i],1);
      check_asic_reg_with_addr(0x18,dev->TempChipAddr[chain][i],chain,1);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar14 = fopen(log_file,"a+");
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: Chain[%d] use default temp chip[%d] \n","temperature.c",0x382,
                  "calibration_sensor_offset",chain,(dev->TempChipAddr[chain][i] >> 2) + 1);
        }
        fclose(pFVar14);
      }
      do_calibration_sensor_offset_by_eeprom(device_local,dev->TempChipAddr[chain][i],chain,i);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar14 = fopen(log_file,"a+");
        if (pFVar14 != (FILE *)0x0) {
          fprintf(pFVar14,"%s:%d:%s: Chain[%d] Chip[%d] get middle temp offset=%d typeID=%02x\n",
                  "temperature.c",0x387,"calibration_sensor_offset",chain,
                  (dev->TempChipAddr[chain][i] >> 2) + 1,(int)middle_Offset[chain][i],
                  (uint)dev->TempChipType[chain][i]);
        }
        fclose(pFVar14);
      }
    }
  }
  return '\0';
}


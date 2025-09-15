
_Bool is_eeprom_tempsensor_data_correct(uint8_t chain)

{
  _Bool _Var1;
  int iVar2;
  uint8_t chain_local;
  int8_t sensor_offset [6];
  uint8_t sensor_pos [6];
  uint32_t sensor_num;
  TEMP_SENSOR_TYPE sensor_type;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_4;
  FILE *pFile_6;
  FILE *pFile_10;
  FILE *pFile_11;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_5;
  FILE *pFile_3;
  FILE *pFile;
  int i;
  
  i = 0;
  sensor_type = 0;
  sensor_num = 0;
  sensor_pos[0] = '\0';
  sensor_pos[1] = '\0';
  sensor_pos[2] = '\0';
  sensor_pos[3] = '\0';
  sensor_pos[4] = '\0';
  sensor_pos[5] = '\0';
  sensor_offset[0] = '\0';
  sensor_offset[1] = '\0';
  sensor_offset[2] = '\0';
  sensor_offset[3] = '\0';
  sensor_offset[4] = '\0';
  sensor_offset[5] = '\0';
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: check sensor info ...\n","temperature.c",0x246,
              "is_eeprom_tempsensor_data_correct");
    }
    fclose((FILE *)pFile);
  }
  _Var1 = eeprom_get_temp_sensor_type(chain,&sensor_type);
  if (_Var1) {
    if (sensor_type == TMP451) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile_3 = (FILE *)fopen(log_file,"a+");
        if (pFile_3 != (FILE *)0x0) {
          fprintf((FILE *)pFile_3,"%s:%d:%s: sensor type is TMP451\n","temperature.c",0x255,
                  "is_eeprom_tempsensor_data_correct");
        }
        fclose((FILE *)pFile_3);
      }
      usleep(100000);
      _Var1 = eeprom_get_temp_sensor_pos(chain,sensor_pos,&sensor_num);
      if (_Var1) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_5 = (FILE *)fopen(log_file,"a+");
          if (pFile_5 != (FILE *)0x0) {
            fprintf((FILE *)pFile_5,"%s:%d:%s: %d\n","temperature.c",0x261,
                    "is_eeprom_tempsensor_data_correct",sensor_num);
          }
          fclose((FILE *)pFile_5);
        }
        if (sensor_num == 0) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFile_6 = (FILE *)fopen(log_file,"a+");
            if (pFile_6 != (FILE *)0x0) {
              fprintf((FILE *)pFile_6,"%s:%d:%s: sensor num is %d, error\n","temperature.c",0x265,
                      "is_eeprom_tempsensor_data_correct",0);
            }
            fclose((FILE *)pFile_6);
          }
          _Var1 = false;
        }
        else if ((sensor_num == 0) || (1 < sensor_num)) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFile_8 = (FILE *)fopen(log_file,"a+");
            if (pFile_8 != (FILE *)0x0) {
              fprintf((FILE *)pFile_8,"%s:%d:%s: sensor num is %d\n","temperature.c",0x26f,
                      "is_eeprom_tempsensor_data_correct",sensor_num);
            }
            fclose((FILE *)pFile_8);
          }
          dev->chain_asic_temp_num[chain] = '\x04';
          for (i = 0; (uint)i < sensor_num; i = i + 1) {
            if ((sensor_pos[i] == '\0') || (0x3c < sensor_pos[i])) {
              return false;
            }
          }
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFile_9 = (FILE *)fopen(log_file,"a+");
            if (pFile_9 != (FILE *)0x0) {
              fprintf((FILE *)pFile_9,"%s:%d:%s: sensor pos = %d, %d, %d, %d\n","temperature.c",
                      0x278,"is_eeprom_tempsensor_data_correct",sensor_pos._0_4_ & 0xff,
                      (uint)sensor_pos._0_4_ >> 8 & 0xff,(uint)sensor_pos._0_4_ >> 0x10 & 0xff,
                      (uint)sensor_pos._0_4_ >> 0x18);
            }
            fclose((FILE *)pFile_9);
          }
          usleep(100000);
          _Var1 = eeprom_get_temp_sensor_data(chain,(uint8_t *)sensor_offset,&sensor_num);
          if (_Var1) {
            for (i = 0; (uint)i < sensor_num; i = i + 1) {
              iVar2 = (int)sensor_offset[i];
              if (iVar2 < 0) {
                iVar2 = -iVar2;
              }
              if (0x32 < iVar2) {
                return false;
              }
            }
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_11 = (FILE *)fopen(log_file,"a+");
              if (pFile_11 != (FILE *)0x0) {
                fprintf((FILE *)pFile_11,"%s:%d:%s: chain[%d] temp sensor info, correct!\n",
                        "temperature.c",0x28a,"is_eeprom_tempsensor_data_correct",(uint)chain);
              }
              fclose((FILE *)pFile_11);
            }
            _Var1 = true;
          }
          else {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_10 = (FILE *)fopen(log_file,"a+");
              if (pFile_10 != (FILE *)0x0) {
                fprintf((FILE *)pFile_10,"%s:%d:%s: get temp sensor offset,error!\n","temperature.c"
                        ,0x27f,"is_eeprom_tempsensor_data_correct");
              }
              fclose((FILE *)pFile_10);
            }
            _Var1 = false;
          }
        }
        else {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFile_7 = (FILE *)fopen(log_file,"a+");
            if (pFile_7 != (FILE *)0x0) {
              fprintf((FILE *)pFile_7,"%s:%d:%s: sensor num is less than expected:%d\n",
                      "temperature.c",0x26a,"is_eeprom_tempsensor_data_correct",sensor_num);
            }
            fclose((FILE *)pFile_7);
          }
          _Var1 = false;
        }
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_4 = (FILE *)fopen(log_file,"a+");
          if (pFile_4 != (FILE *)0x0) {
            fprintf((FILE *)pFile_4,"%s:%d:%s: get temp sensor pos,error!\n","temperature.c",0x25c,
                    "is_eeprom_tempsensor_data_correct");
          }
          fclose((FILE *)pFile_4);
        }
        _Var1 = false;
      }
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile_2 = (FILE *)fopen(log_file,"a+");
        if (pFile_2 != (FILE *)0x0) {
          fprintf((FILE *)pFile_2,"%s:%d:%s: sensor type is not TMP451,error\n","temperature.c",
                  0x251,"is_eeprom_tempsensor_data_correct");
        }
        fclose((FILE *)pFile_2);
      }
      _Var1 = false;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        fprintf((FILE *)pFile_1,"%s:%d:%s: get temp sensor type,error!\n","temperature.c",0x24a,
                "is_eeprom_tempsensor_data_correct");
      }
      fclose((FILE *)pFile_1);
    }
    _Var1 = false;
  }
  return _Var1;
}



_Bool is_tempsensor_data_correct(temp_info_t temp_info)

{
  TEMP_SENSOR_TYPE TVar1;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  uint32_t i;
  undefined1 auStack_8 [6];
  undefined1 auStack_2 [2];
  
  TVar1 = temp_info.type;
  if (temp_info.type == TMP451) {
    if ((temp_info.num == 0) || (6 < temp_info.num)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        temp_info.type = (TEMP_SENSOR_TYPE)fopen(log_file,"a+");
        if (temp_info.type != 0) {
          fprintf((FILE *)temp_info.type,"%s:%d:%s: Bad,temp_info.num = %d\n","temperature.c",0x209,
                  "is_tempsensor_data_correct",temp_info.num);
        }
        fclose((FILE *)temp_info.type);
      }
      temp_info.type._0_1_ = 0;
    }
    else {
      i = 0;
      while (i < temp_info.num) {
        temp_info._12_4_ = (int)auStack_8 + i;
        if (*(char *)temp_info._12_4_ < '\x01') {
LAB_000158a6:
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            temp_info.type = (TEMP_SENSOR_TYPE)fopen(log_file,"a+");
            if (temp_info.type != 0) {
              temp_info._12_4_ = (int)auStack_8 + i;
              temp_info._12_4_ = SEXT14(*(char *)temp_info._12_4_);
              fprintf((FILE *)temp_info.type,"%s:%d:%s: Bad,temp_info.pos[%d] = %d\n",
                      "temperature.c",0x211,"is_tempsensor_data_correct",i,temp_info._12_4_);
            }
            fclose((FILE *)temp_info.type);
          }
          temp_info.type._0_1_ = 0;
          return (_Bool)(undefined1)temp_info.type;
        }
        temp_info._12_4_ = (int)auStack_8 + i;
        if ('<' < *(char *)temp_info._12_4_) goto LAB_000158a6;
        temp_info._12_4_ = (int)auStack_2 + i;
        temp_info._12_4_ = SEXT14(*(char *)temp_info._12_4_);
        if ((int)temp_info._12_4_ < 0) {
          temp_info._12_4_ = -temp_info._12_4_;
        }
        if (9 < (int)temp_info._12_4_) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            temp_info.type = (TEMP_SENSOR_TYPE)fopen(log_file,"a+");
            if (temp_info.type != 0) {
              temp_info._12_4_ = (int)auStack_2 + i;
              temp_info._12_4_ = SEXT14(*(char *)temp_info._12_4_);
              fprintf((FILE *)temp_info.type,"%s:%d:%s: Bad,temp_info.pos[%d] = %d\n",
                      "temperature.c",0x217,"is_tempsensor_data_correct",i,temp_info._12_4_);
            }
            fclose((FILE *)temp_info.type);
          }
          temp_info.type._0_1_ = 0;
          return (_Bool)(undefined1)temp_info.type;
        }
        temp_info._12_4_ = i + 1;
        i = temp_info._12_4_;
      }
      temp_info.type._0_1_ = TMP451;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      temp_info.type = (TEMP_SENSOR_TYPE)fopen(log_file,"a+");
      if (temp_info.type != 0) {
        fprintf((FILE *)temp_info.type,"%s:%d:%s: Bad,temp_info.type = %d\n","temperature.c",0x203,
                "is_tempsensor_data_correct",TVar1);
      }
      fclose((FILE *)temp_info.type);
    }
    temp_info.type._0_1_ = 0;
  }
  return (_Bool)(undefined1)temp_info.type;
}


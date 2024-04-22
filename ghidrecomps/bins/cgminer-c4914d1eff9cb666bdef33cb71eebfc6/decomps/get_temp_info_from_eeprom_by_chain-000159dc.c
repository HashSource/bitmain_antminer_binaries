
void get_temp_info_from_eeprom_by_chain(uint32_t chain)

{
  uint8_t chain_00;
  _Bool _Var1;
  FILE *pFVar2;
  uint32_t chain_local;
  FILE *pFile_5;
  FILE *pFile_8;
  FILE *pFile_9;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int i;
  
  chain_00 = (uint8_t)chain;
  _Var1 = eeprom_get_temp_sensor_type(chain_00,&temp_info[chain].type);
  if ((!_Var1) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: get temp sensor type,error!\n","temperature.c",0x226,
              "get_temp_info_from_eeprom_by_chain");
    }
    fclose(pFVar2);
  }
  _Var1 = eeprom_get_temp_sensor_pos(chain_00,(uint8_t *)temp_info[chain].pos,&temp_info[chain].num)
  ;
  if ((!_Var1) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: get temp sensor pos&num,error!\n","temperature.c",0x22b,
              "get_temp_info_from_eeprom_by_chain");
    }
    fclose(pFVar2);
  }
  _Var1 = eeprom_get_temp_sensor_data
                    (chain_00,(uint8_t *)temp_info[chain].offset,&temp_info[chain].num);
  if ((!_Var1) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: get temp sensor offset&num,error!\n","temperature.c",0x230,
              "get_temp_info_from_eeprom_by_chain");
    }
    fclose(pFVar2);
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"sensor type = %d,sensor num = %d\n",temp_info[chain].type,temp_info[chain].num
             );
    }
    fclose(pFVar2);
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fwrite("sensor pos:",1,0xb,pFVar2);
    }
    fclose(pFVar2);
  }
  for (i = 0; i < 6; i = i + 1) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2," %d ",(int)temp_info[chain].pos[i]);
      }
      fclose(pFVar2);
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fwrite("sensor offset:",1,0xe,pFVar2);
    }
    fclose(pFVar2);
  }
  for (i = 0; i < 6; i = i + 1) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2," %d ",(int)temp_info[chain].offset[i]);
      }
      fclose(pFVar2);
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  return;
}


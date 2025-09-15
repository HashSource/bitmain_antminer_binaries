
void _eeprom_dump_fileds(eeprom_layout_t *eeprom_buf)

{
  FILE *pFVar1;
  eeprom_layout_t *eeprom_buf_local;
  FILE *pFile_3;
  FILE *pFile_19;
  FILE *pFile_18;
  FILE *pFile_22;
  FILE *pFile_21;
  FILE *pFile_20;
  FILE *pFile_17;
  int mode_count_max;
  FILE *pFile_16;
  FILE *pFile_15;
  FILE *pFile_14;
  FILE *pFile_7;
  FILE *pFile_8;
  FILE *pFile_9;
  FILE *pFile_10;
  FILE *pFile_11;
  FILE *pFile_12;
  FILE *pFile_13;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int mode;
  int i;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%04x\n","fixture_header",(uint)eeprom_buf->fixture_header);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%04x\n","fixture_version",(uint)eeprom_buf->fixture_version);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : ","hash_board_sn");
    }
    fclose(pFVar1);
  }
  for (i = 0; (uint)i < 0x14; i = i + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc((uint)eeprom_buf->hash_board_sn[i],pFVar1);
      }
      fclose(pFVar1);
    }
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%04x\n","pcb_version",(uint)eeprom_buf->pcb_version);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%04x\n","bom_version",(uint)eeprom_buf->bom_version);
    }
    fclose(pFVar1);
  }
  if (eeprom_buf->temp_sensor_type == '\x01') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP451");
      }
      fclose(pFVar1);
    }
  }
  else if (eeprom_buf->temp_sensor_type == '\x02') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP461");
      }
      fclose(pFVar1);
    }
  }
  else if (eeprom_buf->temp_sensor_type == '\x03') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP421");
      }
      fclose(pFVar1);
    }
  }
  else if (eeprom_buf->temp_sensor_type == '\x04') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP431");
      }
      fclose(pFVar1);
    }
  }
  else if (eeprom_buf->temp_sensor_type == '\x05') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","ECT218");
      }
      fclose(pFVar1);
    }
  }
  else if (eeprom_buf->temp_sensor_type == '\x06') {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP441B");
      }
      fclose(pFVar1);
    }
  }
  else if ((eeprom_buf->temp_sensor_type == '\a') && (3 < log_level)) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : %s\n","temp_sensor_type","TMP411C");
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%02x\n","product_id",(uint)eeprom_buf->product_id);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%-30s : 0x%04x\n","cgminer_header",(uint)eeprom_buf->cgminer_header);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fputc(10,pFVar1);
    }
    fclose(pFVar1);
  }
  for (mode = 0; mode < 3; mode = mode + 1) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"[Tuning Result Mode %d]:\n",mode);
      }
      fclose(pFVar1);
    }
    for (i = 0; i < 0x30; i = i + 1) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"IC[%02d]:%03d ",i,(uint)eeprom_buf->tuning_ret[mode].freq[i] * 5);
        }
        fclose(pFVar1);
      }
      if (((i + 1U & 3) == 0) && (3 < log_level)) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s: %d\n","voltage",(uint)eeprom_buf->tuning_ret[mode].voltage);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s: %d\n","hash_rate",eeprom_buf->tuning_ret[mode].hash_rate);
      }
      fclose(pFVar1);
    }
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fputc(10,pFVar1);
      }
      fclose(pFVar1);
    }
  }
  return;
}


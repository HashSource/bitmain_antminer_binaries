
void travel_eeprom_store(uint8_t chain,_Bool debug)

{
  uint8_t uVar1;
  double dVar2;
  _Bool debug_local;
  uint8_t chain_local;
  uint8_t bom_version_t;
  uint8_t pcb_version_t;
  char temp_sensor_data [6];
  char temp_sensor_pos [6];
  uint32_t temp_sensor_num;
  TEMP_SENSOR_TYPE temp_sensor_type_t;
  FILE *pFile;
  FILE *pFile_6;
  FILE *pFile_7;
  FILE *pFile_20;
  FILE *pFile_23;
  FILE *pFile_24;
  FILE *pFile_22;
  FILE *pFile_21;
  FILE *pFile_19;
  FILE *pFile_18;
  FILE *pFile_17;
  FILE *pFile_12;
  FILE *pFile_13;
  FILE *pFile_16;
  FILE *pFile_15;
  FILE *pFile_14;
  FILE *pFile_11;
  uint32_t hash_rate_mode2_t;
  FILE *pFile_10;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  uint32_t hast_rate;
  eeprom_store_t *eeprom;
  int i;
  int l;
  int k;
  
  k = 0;
  l = 0;
  eeprom = (eeprom_store_t *)0x0;
  hast_rate = 0;
  eeprom = (eeprom_store_t *)malloc(0x83);
  if (eeprom == (eeprom_store_t *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"%s:%d:%s: fetal error: failed to allocate memory for eeprom!\n",
                "eeprom.c",0x263,"travel_eeprom_store");
      }
      fclose((FILE *)pFile);
    }
  }
  else {
    memset(eeprom,0,0x83);
    eeprom = read_eeprom_store_from_at24c02(eeprom,chain);
    temp_sensor_type_t = 0;
    temp_sensor_num = 0;
    temp_sensor_pos[0] = '\0';
    temp_sensor_pos[1] = '\0';
    temp_sensor_pos[2] = '\0';
    temp_sensor_pos[3] = '\0';
    temp_sensor_pos[4] = '\0';
    temp_sensor_pos[5] = '\0';
    temp_sensor_data[0] = '\0';
    temp_sensor_data[1] = '\0';
    temp_sensor_data[2] = '\0';
    temp_sensor_data[3] = '\0';
    temp_sensor_data[4] = '\0';
    temp_sensor_data[5] = '\0';
    pcb_version_t = '\0';
    bom_version_t = '\0';
    i = 0;
    if (debug) {
      _eeprom_get_pcb_version(chain,&pcb_version_t);
      _eeprom_get_bom_version(chain,&bom_version_t);
      _eeprom_get_temp_sensor_type(chain,&temp_sensor_type_t);
      _eeprom_get_temp_sensor_pos(chain,(uint8_t *)temp_sensor_pos,&temp_sensor_num);
      _eeprom_get_temp_sensor_data(chain,(uint8_t *)temp_sensor_data,&temp_sensor_num);
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        fprintf((FILE *)pFile_1,"%s:%d:%s: chain[%d] data in eeprom is:\n","eeprom.c",0x27a,
                "travel_eeprom_store",(uint)chain);
      }
      fclose((FILE *)pFile_1);
    }
    if (3 < log_level) {
      pFile_2 = (FILE *)fopen(log_file,"a+");
      if (pFile_2 != (FILE *)0x0) {
        fprintf((FILE *)pFile_2,"magic number: 0x%02x\n",(uint)eeprom->magic_num);
      }
      fclose((FILE *)pFile_2);
    }
    if (debug) {
      if (3 < log_level) {
        pFile_3 = (FILE *)fopen(log_file,"a+");
        if (pFile_3 != (FILE *)0x0) {
          fprintf((FILE *)pFile_3,"pcb version: 0x%02x\n",(uint)pcb_version_t);
        }
        fclose((FILE *)pFile_3);
      }
      if (3 < log_level) {
        pFile_4 = (FILE *)fopen(log_file,"a+");
        if (pFile_4 != (FILE *)0x0) {
          fprintf((FILE *)pFile_4,"bom version: 0x%02x\n",(uint)bom_version_t);
        }
        fclose((FILE *)pFile_4);
      }
    }
    if (3 < log_level) {
      pFile_5 = (FILE *)fopen(log_file,"a+");
      if (pFile_5 != (FILE *)0x0) {
        fwrite("freq data per ASIC:\n",1,0x14,(FILE *)pFile_5);
      }
      fclose((FILE *)pFile_5);
    }
    for (l = 0; l < 6; l = l + 1) {
      for (k = 0; k < 10; k = k + 1) {
        if (3 < log_level) {
          pFile_6 = (FILE *)fopen(log_file,"a+");
          if (pFile_6 != (FILE *)0x0) {
            fprintf((FILE *)pFile_6,"IC[%03d]:%d ",(l * 0x3c) / 6 + k,
                    (uint)eeprom->chain_freq_data[k + (l * 0x3c) / 6] * 5);
          }
          fclose((FILE *)pFile_6);
        }
      }
      if (3 < log_level) {
        pFile_7 = (FILE *)fopen(log_file,"a+");
        if (pFile_7 != (FILE *)0x0) {
          fputc(10,(FILE *)pFile_7);
        }
        fclose((FILE *)pFile_7);
      }
    }
    if (3 < log_level) {
      pFile_8 = (FILE *)fopen(log_file,"a+");
      if (pFile_8 != (FILE *)0x0) {
        dVar2 = (double)((float)(ulonglong)((eeprom->chain_volt + 300) * 2) / DAT_0006e360);
        fprintf((FILE *)pFile_8,"voltage: %.02f V\n",SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20))
        ;
      }
      fclose((FILE *)pFile_8);
    }
    hast_rate = (uint)eeprom->hash_rate[3] * 0x1000000 +
                (uint)eeprom->hash_rate[0] + (uint)eeprom->hash_rate[1] * 0x100 +
                (uint)eeprom->hash_rate[2] * 0x10000;
    if (3 < log_level) {
      pFile_9 = (FILE *)fopen(log_file,"a+");
      if (pFile_9 != (FILE *)0x0) {
        fprintf((FILE *)pFile_9,"hash rate: %05d GH/s\n",hast_rate);
      }
      fclose((FILE *)pFile_9);
    }
    if (3 < log_level) {
      pFile_10 = (FILE *)fopen(log_file,"a+");
      if (pFile_10 != (FILE *)0x0) {
        fputc(10,(FILE *)pFile_10);
      }
      fclose((FILE *)pFile_10);
    }
    uVar1 = eeprom_target_eeprom_version();
    if (uVar1 == eeprom->magic_num) {
      hash_rate_mode2_t = 0;
      if (3 < log_level) {
        pFile_11 = (FILE *)fopen(log_file,"a+");
        if (pFile_11 != (FILE *)0x0) {
          fwrite("freq data per ASIC in mode2:\n",1,0x1d,(FILE *)pFile_11);
        }
        fclose((FILE *)pFile_11);
      }
      for (l = 0; l < 6; l = l + 1) {
        for (k = 0; k < 10; k = k + 1) {
          if (3 < log_level) {
            pFile_12 = (FILE *)fopen(log_file,"a+");
            if (pFile_12 != (FILE *)0x0) {
              fprintf((FILE *)pFile_12,"IC[%03d]:%d ",(l * 0x3c) / 6 + k,
                      (uint)eeprom->chain_freq_data_mode2[k + (l * 0x3c) / 6] * 5);
            }
            fclose((FILE *)pFile_12);
          }
        }
        if (3 < log_level) {
          pFile_13 = (FILE *)fopen(log_file,"a+");
          if (pFile_13 != (FILE *)0x0) {
            fputc(10,(FILE *)pFile_13);
          }
          fclose((FILE *)pFile_13);
        }
      }
      if (3 < log_level) {
        pFile_14 = (FILE *)fopen(log_file,"a+");
        if (pFile_14 != (FILE *)0x0) {
          dVar2 = (double)((float)(ulonglong)((eeprom->chain_volt_mode2 + 300) * 2) / DAT_0006e360);
          fprintf((FILE *)pFile_14,"voltage in mode2: %.02f V\n",SUB84(dVar2,0),
                  (int)((ulonglong)dVar2 >> 0x20));
        }
        fclose((FILE *)pFile_14);
      }
      hash_rate_mode2_t =
           (uint)eeprom->hash_rate_mode2[3] * 0x1000000 +
           (uint)eeprom->hash_rate_mode2[0] + (uint)eeprom->hash_rate_mode2[1] * 0x100 +
           (uint)eeprom->hash_rate_mode2[2] * 0x10000;
      if (3 < log_level) {
        pFile_15 = (FILE *)fopen(log_file,"a+");
        if (pFile_15 != (FILE *)0x0) {
          fprintf((FILE *)pFile_15,"hash rate in mode2: %05d GH/s\n",hash_rate_mode2_t);
        }
        fclose((FILE *)pFile_15);
      }
      if (3 < log_level) {
        pFile_16 = (FILE *)fopen(log_file,"a+");
        if (pFile_16 != (FILE *)0x0) {
          fputc(10,(FILE *)pFile_16);
        }
        fclose((FILE *)pFile_16);
      }
    }
    if (debug) {
      if (3 < log_level) {
        pFile_17 = (FILE *)fopen(log_file,"a+");
        if (pFile_17 != (FILE *)0x0) {
          fprintf((FILE *)pFile_17,"TEMP SENSOR TYPE: %d \n",temp_sensor_type_t);
        }
        fclose((FILE *)pFile_17);
      }
      if (3 < log_level) {
        pFile_18 = (FILE *)fopen(log_file,"a+");
        if (pFile_18 != (FILE *)0x0) {
          fprintf((FILE *)pFile_18,"TEMP SENSOR NUM: %d \n",temp_sensor_num);
        }
        fclose((FILE *)pFile_18);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile_19 = (FILE *)fopen(log_file,"a+");
        if (pFile_19 != (FILE *)0x0) {
          fprintf((FILE *)pFile_19,"%s:%d:%s: sensor pos =","eeprom.c",0x2ad,"travel_eeprom_store");
        }
        fclose((FILE *)pFile_19);
      }
      for (i = 0; (uint)i < temp_sensor_num; i = i + 1) {
        if (3 < log_level) {
          pFile_20 = (FILE *)fopen(log_file,"a+");
          if (pFile_20 != (FILE *)0x0) {
            fprintf((FILE *)pFile_20," %d ",(int)temp_sensor_pos[i]);
          }
          fclose((FILE *)pFile_20);
        }
      }
      if (3 < log_level) {
        pFile_21 = (FILE *)fopen(log_file,"a+");
        if (pFile_21 != (FILE *)0x0) {
          fputc(10,(FILE *)pFile_21);
        }
        fclose((FILE *)pFile_21);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile_22 = (FILE *)fopen(log_file,"a+");
        if (pFile_22 != (FILE *)0x0) {
          fprintf((FILE *)pFile_22,"%s:%d:%s: sensor offset =","eeprom.c",0x2b3,
                  "travel_eeprom_store");
        }
        fclose((FILE *)pFile_22);
      }
      for (i = 0; (uint)i < temp_sensor_num; i = i + 1) {
        if (3 < log_level) {
          pFile_23 = (FILE *)fopen(log_file,"a+");
          if (pFile_23 != (FILE *)0x0) {
            fprintf((FILE *)pFile_23," %d ",(int)temp_sensor_data[i]);
          }
          fclose((FILE *)pFile_23);
        }
      }
      if (3 < log_level) {
        pFile_24 = (FILE *)fopen(log_file,"a+");
        if (pFile_24 != (FILE *)0x0) {
          fputc(10,(FILE *)pFile_24);
        }
        fclose((FILE *)pFile_24);
      }
    }
    if (eeprom != (eeprom_store_t *)0x0) {
      free(eeprom);
    }
  }
  return;
}


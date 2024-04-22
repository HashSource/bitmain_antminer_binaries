
uint16_t increase_freq_by_eeprom_slowly_new(int init_freq,int freq_step)

{
  ushort uVar1;
  _Bool _Var2;
  FILE *pFVar3;
  float fVar4;
  int freq_step_local;
  int init_freq_local;
  int chip_freq_array [60];
  FILE *pFile_1;
  uint16_t final_freq;
  uint16_t asic_freq;
  uint16_t tmp_freq;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_7;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  uint16_t freq_temp;
  int total_freq_tmp;
  uint16_t total_freq_chain;
  uint16_t max_freq_chain;
  uint16_t min_freq_chain;
  uint16_t max_freq;
  uint16_t step;
  uint16_t steps;
  uint8_t column;
  uint8_t asic;
  uint8_t chip;
  uint8_t vol_region;
  uint8_t chain;
  
  max_freq = 0;
  total_freq_tmp = 0;
  memset(chip_freq_array,0,0xf0);
  chain = '\0';
  do {
    if (0xf < chain) {
      total_freq = total_freq_tmp;
      return max_freq;
    }
    if (dev->chain_exist[chain] != 0) {
      min_freq_chain = 0xffff;
      max_freq_chain = 0;
      total_freq_chain = 0;
      for (asic = '\0'; asic < 0x3c; asic = asic + '\x01') {
        uVar1 = (ushort)scan_result[chain].freq_eeprom[asic];
        if (max_freq_chain < uVar1) {
          max_freq_chain = uVar1;
        }
        if (uVar1 < min_freq_chain) {
          min_freq_chain = uVar1;
        }
        total_freq_chain = uVar1 + total_freq_chain;
      }
      if (max_freq < max_freq_chain) {
        max_freq = max_freq_chain;
      }
      _Var2 = is_user_mode();
      if (_Var2) {
        fVar4 = get_max_freq();
        _Var2 = check_freq_valid(scan_result[chain].freq_eeprom,0x3c,
                                 (uint)(0.0 < fVar4) * (int)fVar4);
        if (!_Var2) {
          dump_freq_data(chain,scan_result[chain].freq_eeprom);
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fVar4 = get_max_freq();
              fprintf(pFVar3,"%s:%d:%s: fetal error: chain[%d] freq data over valid max freq %d\n",
                      "driver-btm-soc.c",0x14a0,"increase_freq_by_eeprom_slowly_new",(uint)chain,
                      (uint)(0.0 < fVar4) * (int)fVar4);
            }
            fclose(pFVar3);
          }
          disable_pic_dac(chain);
          dev->chain_exist[chain] = 0;
          dev->chain_num = dev->chain_num + 0xff;
          return 0xffff;
        }
      }
      scan_freq_average[chain] = total_freq_chain / 0x3c;
      total_freq_tmp = (uint)total_freq_chain + total_freq_tmp;
      steps = __aeabi_idiv((uint)min_freq_chain - init_freq,freq_step);
      if ((int)(freq_step * (uint)steps + init_freq) < (int)(uint)min_freq_chain) {
        steps = steps + 1;
      }
      for (step = 0; step < steps; step = step + 1) {
        freq_temp = (short)init_freq + (step + 1) * (short)freq_step;
        if (min_freq_chain < freq_temp) {
          freq_temp = min_freq_chain;
        }
        change_high_pll_test(chain,(float)(ulonglong)freq_temp,0);
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: chain[%d] increase to %d\n","driver-btm-soc.c",0x14b7,
                    "increase_freq_by_eeprom_slowly_new",(uint)chain,(uint)freq_temp);
          }
          fclose(pFVar3);
        }
        for (asic = '\0'; asic < 0x3c; asic = asic + '\x01') {
          chip_freq_array[asic] = (uint)freq_temp;
        }
        sleep(1);
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: max = %d ,min = %d\n","driver-btm-soc.c",0x14c1,
                  "increase_freq_by_eeprom_slowly_new",(uint)max_freq_chain,(uint)min_freq_chain);
        }
        fclose(pFVar3);
      }
      steps = __aeabi_idiv((uint)max_freq_chain - (uint)min_freq_chain,freq_step);
      if ((int)((uint)min_freq_chain + freq_step * (uint)steps) < (int)(uint)max_freq_chain) {
        steps = steps + 1;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] increaseing the diff freq ...\n","driver-btm-soc.c",
                  0x14c7,"increase_freq_by_eeprom_slowly_new",(uint)chain);
        }
        fclose(pFVar3);
      }
      for (step = 0; step < steps; step = step + 1) {
        tmp_freq = min_freq_chain + (step + 1) * (short)freq_step;
        for (column = '\0'; column < 10; column = column + '\x01') {
          for (vol_region = '\0'; vol_region < 6; vol_region = vol_region + '\x01') {
            asic = column + vol_region * '\n';
            final_freq = tmp_freq;
            if ((scan_result[chain].freq_eeprom[asic] & 0xffff) <= (uint)tmp_freq) {
              final_freq = (ushort)scan_result[chain].freq_eeprom[asic];
            }
            chip_freq_array[asic] = (uint)final_freq;
            change_high_pll_by_aisc((uint)chain,(uint)asic,(float)(ulonglong)final_freq,0);
          }
        }
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain %d final freq setting:\n","driver-btm-soc.c",0x14e3,
                  "increase_freq_by_eeprom_slowly_new",(uint)chain);
        }
        fclose(pFVar3);
      }
      for (chip = '\0'; chip < 0x3c; chip = chip + '\x01') {
        if (3 < log_level) {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%03d ",chip_freq_array[chip]);
          }
          fclose(pFVar3);
        }
        if (((chip + 1) % 10 == 0) && (3 < log_level)) {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fputc(10,pFVar3);
          }
          fclose(pFVar3);
        }
      }
      _Var2 = is_env_temperature_high();
      if (_Var2) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            fprintf(pFVar3,"%s:%d:%s: set chain %u to working voltage\n","driver-btm-soc.c",0x14ef,
                    "increase_freq_by_eeprom_slowly_new",(uint)chain);
          }
          fclose(pFVar3);
        }
        slowly_set_working_power_t11(chain);
      }
    }
    chain = chain + '\x01';
  } while( true );
}


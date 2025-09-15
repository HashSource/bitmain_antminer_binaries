
void scan_freq_save_result_with_new_format(working_mode_e working_mode)

{
  uint8_t chain_00;
  _Bool _Var1;
  FILE *pFVar2;
  working_mode_e working_mode_local;
  uint32_t freq_asic [60];
  int asic;
  FILE *pFile;
  FILE *pFile_1;
  int volt_region;
  int column;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      memset(freq_asic,0,0xf0);
      for (column = 0; column < 10; column = column + 1) {
        for (volt_region = 0; volt_region < 6; volt_region = volt_region + 1) {
          freq_asic[column + volt_region * 10] =
               (uint)(0.0 < freq_adjust_index[chain][volt_region]) *
               (int)freq_adjust_index[chain][volt_region];
        }
      }
      chain_00 = (uint8_t)chain;
      if (working_mode == MODE1) {
        _Var1 = eeprom_set_freq_mode1(chain_00,freq_asic);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: save freq for mode1\n","freq_scan.c",0x89b,
                    "scan_freq_save_result_with_new_format");
          }
          fclose(pFVar2);
        }
      }
      else {
        _Var1 = eeprom_set_freq_mode2(chain_00,freq_asic);
        if (!_Var1) {
          stop_scan(3,chain_00);
        }
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: save freq for mode2\n","freq_scan.c",0x8a1,
                    "scan_freq_save_result_with_new_format");
          }
          fclose(pFVar2);
        }
      }
    }
  }
  return;
}


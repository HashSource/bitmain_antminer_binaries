
/* WARNING: Unknown calling convention */

void get_freq_result_from_eeprom(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  uint32_t *buf_00;
  uint32_t *buf;
  FILE *pFile_1;
  FILE *pFile;
  uint8_t i;
  uint8_t chain;
  
  for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
    if (dev->chain_exist[chain] != 0) {
      buf_00 = scan_result[chain].freq_eeprom;
      memset(buf_00,0,0xf0);
      _Var1 = is_economic_mode();
      if (_Var1) {
        _Var1 = eeprom_get_freq_mode1(chain,buf_00);
        if (!_Var1) {
          for (i = '\0'; i < 0x3c; i = i + '\x01') {
            buf_00[i] = g_sweep_config_eco.sweep_min_freq;
          }
        }
      }
      else {
        _Var1 = eeprom_get_freq_mode2(chain,buf_00);
        if (!_Var1) {
          for (i = '\0'; i < 0x3c; i = i + '\x01') {
            buf_00[i] = g_sweep_config_hpf.sweep_min_freq;
          }
        }
      }
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: orginal chip freq: \n","driver-btm-soc.c",0x16ee,
              "get_freq_result_from_eeprom");
    }
    fclose(pFVar2);
  }
  print_chip_freq();
  _Var1 = is_T11();
  if ((!_Var1) && (_Var1 = is_economic_mode(), _Var1)) {
    fix_chip_freq();
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: fixed chip freq for economic mode of bgm miner: ",
                "driver-btm-soc.c",0x16f5,"get_freq_result_from_eeprom");
      }
      fclose(pFVar2);
    }
    print_chip_freq();
  }
  return;
}


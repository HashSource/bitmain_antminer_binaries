
/* WARNING: Unknown calling convention */

void _get_freq_from_eeprom(void)

{
  _Bool _Var1;
  int iVar2;
  bool bVar3;
  int max_freq;
  FILE *pFile;
  uint32_t *buf;
  _Bool is_eeprom_read_success;
  int work_mode;
  _Bool is_freq_valid;
  uint8_t asic;
  uint8_t chain;
  
  is_eeprom_read_success = false;
  _Var1 = freq_tuning_get_max_freq(&max_freq);
  if (!_Var1) {
    power_off_hash_board((uint)All_Chain);
    stop_mining("Get max freq failed!\n");
  }
  chain = '\0';
  do {
    if (0xf < chain) {
      return;
    }
    if (dev->chain_exist[chain] != 0) {
      buf = scan_result[chain].freq_eeprom;
      memset(buf,0,0x1b0);
      work_mode = (int)(opt_bitmain_economic_mode == false);
      iVar2 = eeprom_get_freq((uint)chain,work_mode,buf,0x30);
      bVar3 = iVar2 == 0;
      if (bVar3) {
        iVar2 = 1;
      }
      is_eeprom_read_success = SUB41(iVar2,0);
      if (!bVar3) {
        is_eeprom_read_success = false;
      }
      if (is_eeprom_read_success != false) {
        is_freq_valid = true;
        for (asic = '\0'; asic < 0x30; asic = asic + '\x01') {
          if ((uint)max_freq < buf[asic]) {
            is_freq_valid = false;
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile = (FILE *)fopen(log_file,"a+");
              if (pFile != (FILE *)0x0) {
                fprintf((FILE *)pFile,"%s:%d:%s: Freq(%d) > Max_freq(%d), invalid!\n",
                        "driver-btm-soc.c",0x1c9a,"_get_freq_from_eeprom",buf[asic],max_freq);
              }
              fclose((FILE *)pFile);
            }
            break;
          }
        }
      }
      if ((is_eeprom_read_success != true) || (is_freq_valid != true)) {
        power_off_hash_board((uint)All_Chain);
        stop_mining("Get frequency from eeprom failed!\n");
      }
    }
    chain = chain + '\x01';
  } while( true );
}


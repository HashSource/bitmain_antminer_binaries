
/* WARNING: Unknown calling convention */

_Bool eeprom_load(void)

{
  _Bool _Var1;
  _Bool _Var2;
  FILE *__stream;
  FILE *pFile;
  _Bool load_flag;
  int i;
  _Bool ret;
  int try_time;
  
  if (state_is_eeprom_all_chain_load_succeeded) {
    ret = true;
  }
  else {
    ret = true;
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 0) {
        state_is_eeprom_chain_load_succeeded[i] = false;
      }
      else {
        try_time = 0;
        do {
          _Var1 = eeprom_read((uint8_t)i,0,eeprom_info[i],0x100);
          _Var2 = array_check_crc((uint8_t)i);
          try_time = try_time + 1;
          if (3 < try_time) break;
        } while (!_Var1 || !_Var2);
        if (_Var1 && _Var2) {
          state_is_eeprom_chain_load_succeeded[i] = true;
        }
        else {
          freq_scan_error_code_set(3,i);
          eeprom_dump_for_debug();
          state_is_eeprom_chain_load_succeeded[i] = false;
          dev->chain_exist[i] = 0;
          dev->chain_num = dev->chain_num + 0xff;
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            __stream = fopen(log_file,"a+");
            if (__stream != (FILE *)0x0) {
              fprintf(__stream,
                      "%s:%d:%s: warning: in chain [%d], eeprom crc doesn\'t match with eeprom data. \n"
                      ,"eeprom.c",0x4e5,"eeprom_load",i);
            }
            fclose(__stream);
          }
          ret = false;
        }
      }
    }
    memset(eeprom_dirty_flag,0,0x1000);
    state_is_eeprom_all_chain_load_succeeded = true;
  }
  return ret;
}


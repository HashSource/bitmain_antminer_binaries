
_Bool eeprom_store_init(char *path,eeprom_store_t **eeprom)

{
  _Bool _Var1;
  eeprom_store_t **eeprom_local;
  char *path_local;
  uint16_t freq [16] [12] [9];
  char msg [32];
  int i;
  _Bool ret;
  
  if (path == (char *)0x0) {
    ret = scan_eeprom_config_file("/config/eeprom.conf",freq);
  }
  else {
    ret = scan_eeprom_config_file(path,freq);
  }
  if (ret == true) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (chain_list[i] != 0) {
        memset(eeprom[i],0,0x72);
        convert_freq_array(eeprom[i]->chain_freq_data,freq[i]);
        eeprom[i]->magic_num = '}';
        eeprom[i]->chain_volt = 0xa5;
        eeprom[i]->hash_rate[0] = 'D';
        eeprom[i]->hash_rate[1] = 'H';
        eeprom[i]->hash_rate[2] = '\0';
        eeprom[i]->hash_rate[3] = '\0';
      }
    }
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


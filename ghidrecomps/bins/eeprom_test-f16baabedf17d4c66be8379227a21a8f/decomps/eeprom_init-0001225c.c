
_Bool eeprom_init(char *path)

{
  _Bool _Var1;
  eeprom_store_t *peVar2;
  char *path_local;
  eeprom_store_t *eeprom [16];
  _Bool ret;
  int i_3;
  int i_2;
  int i_1;
  int i;
  
  i = 0;
  while( true ) {
    if (0xf < i) {
      _Var1 = eeprom_store_init(path,eeprom);
      if (_Var1) {
        for (i_1 = 0; i_1 < 0x10; i_1 = i_1 + 1) {
          if (chain_list[i_1] != 0) {
            write_eeprom_store_into_at24c02(eeprom[i_1],(uint8_t)i_1);
          }
        }
        i_2 = 0;
        while ((i_2 < 0x10 && (_Var1 = eeprom_update_crc((uint8_t)i_2), _Var1))) {
          i_2 = i_2 + 1;
        }
      }
      else {
        puts("failed to initialize eeprom");
      }
      for (i_3 = 0; i_3 < 0x10; i_3 = i_3 + 1) {
        if (eeprom[i_3] != (eeprom_store_t *)0x0) {
          free(eeprom[i_3]);
          eeprom[i_3] = (eeprom_store_t *)0x0;
        }
      }
      return true;
    }
    peVar2 = (eeprom_store_t *)malloc(0x72);
    eeprom[i] = peVar2;
    if (eeprom[i] == (eeprom_store_t *)0x0) break;
    i = i + 1;
  }
  perror("failed to allocate memory for eeprom");
  eeprom[i] = (eeprom_store_t *)0x0;
  return false;
}


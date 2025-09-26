
int read_eeprom(int chain,eeprom_data_format_t **ctx)

{
  int32_t iVar1;
  eeprom_data_format_t *peVar2;
  int iVar3;
  eeprom_data_format_t **ctx_local;
  int chain_local;
  char tmp42 [256];
  uint8_t eeprom_data [256];
  uint32_t len;
  
  memset(eeprom_data,0,0x100);
  eeprom_data[0] = 0xff;
  memset(eeprom_data,0xff,0x100);
  iVar1 = eeprom_read(chain,'\0',eeprom_data,0x100);
  if (iVar1 == 0) {
    peVar2 = edf_load(eeprom_data,0x100);
    *ctx = peVar2;
    if (*ctx == (eeprom_data_format_t *)0x0) {
      builtin_strncpy(tmp42,"load eeprom fail",0x10);
      tmp42[0x10] = 'e';
      tmp42[0x11] = 'd';
      tmp42[0x12] = '\0';
      puts(tmp42);
      iVar3 = -1;
    }
    else {
      (*(*ctx)->dump_data)(*ctx);
      iVar3 = 0;
    }
  }
  else {
    snprintf(tmp42,0x100,"read eeprom_data failed,chain:%d",chain);
    puts(tmp42);
    iVar3 = -1;
  }
  return iVar3;
}


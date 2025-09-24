
int read_eeprom(int chain,eeprom_data_format_t **ctx)

{
  int32_t iVar1;
  eeprom_data_format_t *peVar2;
  int iVar3;
  eeprom_data_format_t **ctx_local;
  int chain_local;
  char time_stamp [48];
  char tmp1 [256];
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
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : load eeprom failed\n","read_eeprom");
      builtin_strncpy(tmp1,"load eeprom fail",0x10);
      tmp1[0x10] = 'e';
      tmp1[0x11] = 'd';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
      iVar3 = -1;
    }
    else {
      (*(*ctx)->dump_data)(*ctx);
      iVar3 = 0;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : read eeprom_data failed,chain:%d\n","read_eeprom",chain);
    snprintf(tmp1,0x100,"read eeprom_data failed,chain:%d",chain);
    log_to_file(tmp1,time_stamp);
    iVar3 = -1;
  }
  return iVar3;
}


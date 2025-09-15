
_Bool _eeprom_is_cgminer_crc_pass(eeprom_layout_t *eeprom_buf)

{
  uint16_t uVar1;
  FILE *__stream;
  _Bool _Var2;
  eeprom_layout_t *eeprom_buf_local;
  FILE *pFile;
  uint16_t crc;
  uint16_t len;
  uint16_t start;
  uint8_t *p_buf;
  
  uVar1 = CRC16((uint8_t *)&eeprom_buf->cgminer_header,0xa4);
  if (uVar1 == eeprom_buf->crc_cgminer) {
    _Var2 = true;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Cgminer EEPROM CRC check fail.\n","eeprom.c",0xee,
                "_eeprom_is_cgminer_crc_pass");
      }
      fclose(__stream);
    }
    _Var2 = false;
  }
  return _Var2;
}


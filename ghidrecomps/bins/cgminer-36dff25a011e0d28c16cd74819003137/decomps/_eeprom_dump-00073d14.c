
void _eeprom_dump(eeprom_layout_t *eeprom_buf)

{
  FILE *__stream;
  eeprom_layout_t *eeprom_buf_local;
  FILE *pFile;
  
  _eeprom_dump_raw((uint8_t *)eeprom_buf,0x100);
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fputc(10,__stream);
    }
    fclose(__stream);
  }
  _eeprom_dump_fileds(eeprom_buf);
  return;
}


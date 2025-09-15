
_Bool is_eeprom_write_buf_valid(uint8_t *buf)

{
  FILE *__stream;
  _Bool _Var1;
  uint8_t *buf_local;
  FILE *pFile;
  
  if (buf == (uint8_t *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: warning: write buf is null \n","eeprom.c",0x6e,
                "is_eeprom_write_buf_valid");
      }
      fclose(__stream);
    }
    _Var1 = false;
  }
  else {
    _Var1 = true;
  }
  return _Var1;
}


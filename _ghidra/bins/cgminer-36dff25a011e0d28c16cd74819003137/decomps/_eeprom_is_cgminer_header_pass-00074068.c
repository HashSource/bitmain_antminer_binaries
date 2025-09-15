
_Bool _eeprom_is_cgminer_header_pass(eeprom_layout_t *eeprom_buf)

{
  FILE *__stream;
  _Bool _Var1;
  eeprom_layout_t *eeprom_buf_local;
  FILE *pFile;
  
  if (eeprom_buf->cgminer_header == 0x1397) {
    _Var1 = true;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Cgminer EEPROM header check fail. cgminer-header = 0x%x\n",
                "eeprom.c",0x104,"_eeprom_is_cgminer_header_pass",(uint)eeprom_buf->cgminer_header);
      }
      fclose(__stream);
    }
    _Var1 = false;
  }
  return _Var1;
}


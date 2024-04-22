
_Bool is_eeprom_address_valid(uint32_t address,uint32_t len)

{
  FILE *__stream;
  _Bool _Var1;
  uint32_t len_local;
  uint32_t address_local;
  FILE *pFile;
  
  if (len + address < 0x101) {
    _Var1 = true;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: warning: eeprom address (start %d, length %d)  overflow %d \n",
                "eeprom.c",100,"is_eeprom_address_valid",address,len,0x100);
      }
      fclose(__stream);
    }
    _Var1 = false;
  }
  return _Var1;
}


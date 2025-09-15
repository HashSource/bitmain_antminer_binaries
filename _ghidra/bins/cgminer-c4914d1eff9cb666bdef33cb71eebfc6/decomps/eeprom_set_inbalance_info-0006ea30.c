
_Bool eeprom_set_inbalance_info(uint8_t chain,uint8_t *buf,uint32_t len)

{
  _Bool _Var1;
  FILE *__stream;
  uint32_t len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  FILE *pFile;
  
  if (len < 5) {
    _Var1 = is_eeprom_chain_load_succeeded(chain);
    if (_Var1) {
      array_write_one_byte('r',(uint8_t)len,chain);
      array_write_bytes('s',buf,chain,len);
      _Var1 = array_update_crc(chain);
    }
    else {
      _Var1 = false;
    }
  }
  else {
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: error: inbalance data are more than %d\n","eeprom.c",0x35a,
                "eeprom_set_inbalance_info",4);
      }
      fclose(__stream);
    }
    _Var1 = false;
  }
  return _Var1;
}


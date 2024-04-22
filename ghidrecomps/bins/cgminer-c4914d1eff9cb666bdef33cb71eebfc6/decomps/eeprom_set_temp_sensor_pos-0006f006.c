
_Bool eeprom_set_temp_sensor_pos(uint8_t chain,uint8_t *buf,uint32_t len)

{
  _Bool _Var1;
  FILE *__stream;
  uint32_t len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  FILE *pFile;
  int i;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = is_eeprom_write_buf_valid(buf);
    if (_Var1) {
      if (len < 7) {
        array_write_one_byte('z',(uint8_t)len,chain);
        for (i = 0; (uint)i < len; i = i + 1) {
          array_write_one_byte((char)i * '\x02' + '{',buf[i],chain);
        }
        _Var1 = array_update_crc(chain);
      }
      else {
        if (1 < log_level) {
          print_crt_time_to_file(log_file,1);
          __stream = fopen(log_file,"a+");
          if (__stream != (FILE *)0x0) {
            fprintf(__stream,"%s:%d:%s: error: position data are more than %d\n","eeprom.c",0x489,
                    "eeprom_set_temp_sensor_pos",6);
          }
          fclose(__stream);
        }
        _Var1 = false;
      }
    }
    else {
      _Var1 = false;
    }
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


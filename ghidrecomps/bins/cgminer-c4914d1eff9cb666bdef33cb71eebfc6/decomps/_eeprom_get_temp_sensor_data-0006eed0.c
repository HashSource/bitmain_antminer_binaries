
_Bool _eeprom_get_temp_sensor_data(uint8_t chain,uint8_t *buf,uint32_t *len)

{
  byte bVar1;
  uint8_t uVar2;
  FILE *__stream;
  _Bool _Var3;
  uint32_t *len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  FILE *pFile;
  int i;
  
  bVar1 = array_read_one_byte('z',chain);
  *len = (uint)bVar1;
  if (*len < 7) {
    for (i = 0; (uint)i < *len; i = i + 1) {
      uVar2 = array_read_one_byte((uint8_t)((i + 0x3eU & 0xff) << 1),chain);
      buf[i] = uVar2;
    }
    _Var3 = true;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,
                "%s:%d:%s: error: chain[%d] temperature data num %d read, is more than MAX_OFFSET %d\n"
                ,"eeprom.c",0x463,"_eeprom_get_temp_sensor_data",(uint)chain,*len,6);
      }
      fclose(__stream);
    }
    _Var3 = false;
  }
  return _Var3;
}



_Bool _eeprom_set_freq(uint8_t chain,uint32_t *buf,uint8_t mode)

{
  _Bool _Var1;
  FILE *__stream;
  uint8_t address;
  uint32_t *buf_local;
  uint8_t mode_local;
  uint8_t chain_local;
  uint8_t send_buf [60];
  FILE *pFile;
  uint8_t freq_addr;
  int i;
  
  memset(send_buf,0,0x3c);
  for (i = 0; i < 0x3c; i = i + 1) {
    if ((buf[i] % 5 != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: ** warning: freq is not multiple of %d **\n","eeprom.c",0x163,
                "_eeprom_set_freq",5);
      }
      fclose(__stream);
    }
    send_buf[i] = (uint8_t)(buf[i] / 5);
  }
  if (mode == '\x01') {
    address = 0x88;
  }
  else {
    address = '\x02';
  }
  array_write_bytes(address,send_buf,chain,0x3c);
  _Var1 = array_update_crc(chain);
  return _Var1;
}



_Bool eeprom_check_crc(uint8_t chain)

{
  _Bool _Var1;
  uint8_t chain_local;
  uint16_t _crc_;
  uint16_t crc;
  uint8_t *buf;
  
  buf = (uint8_t *)malloc(0xfe);
  if (buf == (uint8_t *)0x0) {
    perror("error: allocate memory failed\n");
    _Var1 = false;
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    eeprom_read_bytes('\0',buf,chain,0xfe);
    crc = CRC16(buf,0xfe);
    eeprom_read_bytes(0xfe,(uint8_t *)&_crc_,chain,'\x02');
    usleep(10000);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    if (buf != (uint8_t *)0x0) {
      free(buf);
    }
    if (crc == _crc_) {
      _Var1 = true;
    }
    else {
      _Var1 = false;
    }
  }
  return _Var1;
}


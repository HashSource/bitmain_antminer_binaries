
_Bool eeprom_read(uint8_t chain,uint32_t addr,uint8_t *buf,uint32_t len)

{
  _Bool _Var1;
  uint32_t len_local;
  uint8_t *buf_local;
  uint32_t addr_local;
  uint8_t chain_local;
  
  _Var1 = is_chain_existed(chain);
  if (_Var1) {
    _Var1 = is_eeprom_address_valid(addr,len);
    if (_Var1) {
      _Var1 = is_eeprom_read_buf_valid(buf);
      if (_Var1) {
        pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
        eeprom_read_bytes((uint8_t)addr,buf,chain,len);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
        _Var1 = true;
      }
      else {
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


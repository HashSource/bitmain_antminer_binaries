
_Bool eeprom_write_full_length(uint8_t chain,uint8_t *buf)

{
  _Bool _Var1;
  int iVar2;
  uint8_t *buf_local;
  uint8_t chain_local;
  uint8_t receive_buf [256];
  
  _Var1 = is_chain_existed(chain);
  if (_Var1) {
    _Var1 = is_eeprom_write_buf_valid(buf);
    if (_Var1) {
      memset(receive_buf,0,0x100);
      pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
      eeprom_write_bytes('\0',buf,chain,0x100);
      usleep(10000);
      eeprom_read_bytes('\0',receive_buf,chain,0x100);
      pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
      iVar2 = memcmp(buf,receive_buf,0x100);
      if (iVar2 == 0) {
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



_Bool eeprom_get_temp_sensor_pos(uint8_t chain,uint8_t *buf,uint32_t *len)

{
  _Bool _Var1;
  uint32_t *len_local;
  uint8_t *buf_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = is_eeprom_read_buf_valid(buf);
    if (_Var1) {
      _Var1 = _eeprom_get_temp_sensor_pos(chain,buf,len);
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


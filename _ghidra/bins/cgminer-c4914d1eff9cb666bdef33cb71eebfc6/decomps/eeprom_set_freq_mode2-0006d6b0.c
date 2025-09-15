
_Bool eeprom_set_freq_mode2(uint8_t chain,uint32_t *buf)

{
  _Bool _Var1;
  uint32_t *buf_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = is_eeprom_write_buf_valid((uint8_t *)buf);
    if (_Var1) {
      _Var1 = _eeprom_set_freq(chain,buf,'\x01');
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


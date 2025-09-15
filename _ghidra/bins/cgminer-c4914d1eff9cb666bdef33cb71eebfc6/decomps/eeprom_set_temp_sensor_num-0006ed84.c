
_Bool eeprom_set_temp_sensor_num(uint8_t chain,uint8_t num)

{
  _Bool _Var1;
  uint8_t num_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    array_write_one_byte('{',num,chain);
    _Var1 = array_update_crc(chain);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


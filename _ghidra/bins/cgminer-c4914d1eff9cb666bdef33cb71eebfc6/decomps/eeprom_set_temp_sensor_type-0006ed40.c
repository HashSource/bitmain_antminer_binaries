
_Bool eeprom_set_temp_sensor_type(uint8_t chain,TEMP_SENSOR_TYPE type)

{
  _Bool _Var1;
  TEMP_SENSOR_TYPE type_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    array_write_one_byte('y',(uint8_t)type,chain);
    _Var1 = array_update_crc(chain);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


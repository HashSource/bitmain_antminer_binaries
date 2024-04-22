
_Bool eeprom_get_temp_sensor_type(uint8_t chain,TEMP_SENSOR_TYPE *type)

{
  _Bool _Var1;
  TEMP_SENSOR_TYPE *type_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = _eeprom_get_temp_sensor_type(chain,type);
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


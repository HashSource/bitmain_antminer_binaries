
_Bool _eeprom_get_temp_sensor_type(uint8_t chain,TEMP_SENSOR_TYPE *type)

{
  byte bVar1;
  TEMP_SENSOR_TYPE *type_local;
  uint8_t chain_local;
  
  bVar1 = array_read_one_byte('y',chain);
  *type = (uint)bVar1;
  return true;
}



_Bool eeprom_v1_is_version_available(eeprom_v1 *eeprom)

{
  _Bool _Var1;
  eeprom_v1 *eeprom_local;
  
  if (((eeprom->data).version == '\x01') || ((eeprom->data).version == '\x02')) {
    _Var1 = true;
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


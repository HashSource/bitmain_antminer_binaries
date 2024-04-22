
_Bool eeprom_get_voltage(uint8_t chain,double *voltage)

{
  _Bool _Var1;
  double *voltage_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = _eeprom_get_voltage(chain,voltage,'\0');
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


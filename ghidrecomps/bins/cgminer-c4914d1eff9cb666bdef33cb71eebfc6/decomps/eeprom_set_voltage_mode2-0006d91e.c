
/* WARNING: Variable defined which should be unmapped: voltage-local */

_Bool eeprom_set_voltage_mode2(uint8_t chain,double voltage)

{
  _Bool _Var1;
  double in_d0;
  double voltage_local;
  uint8_t chain_local;
  
  _Var1 = is_eeprom_chain_load_succeeded(chain);
  if (_Var1) {
    _Var1 = _eeprom_set_voltage(chain,in_d0,'\x01');
  }
  else {
    _Var1 = false;
  }
  return _Var1;
}


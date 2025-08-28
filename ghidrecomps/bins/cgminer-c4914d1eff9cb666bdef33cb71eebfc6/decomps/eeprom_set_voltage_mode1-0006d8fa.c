
_Bool eeprom_set_voltage_mode1(uint8_t chain,double voltage)

{
  _Bool _Var1;
  double voltage_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_set_voltage(chain,voltage);
  return _Var1;
}


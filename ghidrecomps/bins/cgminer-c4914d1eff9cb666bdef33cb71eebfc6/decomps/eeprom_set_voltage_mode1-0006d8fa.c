
/* WARNING: Variable defined which should be unmapped: voltage-local */

_Bool eeprom_set_voltage_mode1(uint8_t chain,double voltage)

{
  _Bool _Var1;
  double in_d0;
  double voltage_local;
  uint8_t chain_local;
  
  _Var1 = eeprom_set_voltage(chain,in_d0);
  return _Var1;
}


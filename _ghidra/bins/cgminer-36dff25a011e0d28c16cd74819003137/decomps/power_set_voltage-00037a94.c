
void power_set_voltage(uint8_t da_value)

{
  _Bool _Var1;
  uint8_t da_value_local;
  
  _Var1 = power_is_support_cmd_package();
  if (_Var1) {
    power_set_da_value(da_value);
  }
  else {
    power_set_da_value_simple(da_value);
  }
  return;
}


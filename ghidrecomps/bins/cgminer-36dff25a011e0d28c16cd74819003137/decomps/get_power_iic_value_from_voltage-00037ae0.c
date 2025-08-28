
uint8_t get_power_iic_value_from_voltage(double voltage)

{
  _Bool _Var1;
  double voltage_local;
  uint8_t ret;
  double iic_index;
  
  _Var1 = power_is_support_cmd_package();
  if (_Var1) {
    iic_index = 765.411764 - voltage * 35.833333;
  }
  else {
    iic_index = 1215.89444 - voltage * 59.93150685;
  }
  if (255.0 < iic_index) {
    iic_index = 255.0;
  }
  return (0.0 < iic_index) * (char)(longlong)iic_index;
}


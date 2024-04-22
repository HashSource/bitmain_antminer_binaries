
uint8_t get_power_iic_value_from_voltage(double voltage)

{
  _Bool _Var1;
  double in_d0;
  double voltage_local;
  uint8_t ret;
  double iic_index;
  
  _Var1 = power_is_support_cmd_package();
  if (_Var1) {
    iic_index = DAT_00037b90 - in_d0 * DAT_00037b88;
  }
  else {
    iic_index = DAT_00037ba0 - in_d0 * DAT_00037b98;
  }
  if (iic_index != DAT_00037ba8 && iic_index < DAT_00037ba8 == (NAN(iic_index) || NAN(DAT_00037ba8))
     ) {
    iic_index = 255.0;
  }
  return (0.0 < iic_index) * (char)(longlong)iic_index;
}


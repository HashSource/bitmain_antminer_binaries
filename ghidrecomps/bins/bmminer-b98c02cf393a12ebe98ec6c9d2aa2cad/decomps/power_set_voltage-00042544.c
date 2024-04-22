
undefined4 power_set_voltage(void)

{
  if (power_protocal_type != 2) {
    power_set_da_value_simple();
    return 0;
  }
  power_set_da_value();
  return 0;
}


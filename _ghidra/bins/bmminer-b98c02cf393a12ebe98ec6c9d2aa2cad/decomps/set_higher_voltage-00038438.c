
void set_higher_voltage(void)

{
  if (opt_fixed_freq != '\0') {
    return;
  }
  set_iic_power_to_higher_voltage();
  return;
}


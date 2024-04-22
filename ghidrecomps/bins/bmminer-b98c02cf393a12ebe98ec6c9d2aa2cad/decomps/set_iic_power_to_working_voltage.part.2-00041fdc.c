
void set_iic_power_to_working_voltage_part_2(void)

{
  double dVar1;
  
  dVar1 = (double)get_avg_voltage();
  if ((int)((uint)(dVar1 < DAT_00042000) << 0x1f) < 0) {
    stop_mining("power voltage too low\n");
  }
  return;
}


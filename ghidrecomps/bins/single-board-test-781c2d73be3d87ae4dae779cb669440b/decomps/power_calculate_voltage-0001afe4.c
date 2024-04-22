
/* WARNING: Unknown calling convention */

uchar power_calculate_voltage(uint voltage)

{
  uchar uVar1;
  int ret;
  
  if (g_power_type != 1) {
    uVar1 = APW9_calculate_voltage(voltage);
    return uVar1;
  }
  uVar1 = APW8_calculate_voltage(voltage);
  return uVar1;
}



/* WARNING: Unknown calling convention */

void power_set_voltage(uchar N)

{
  if (g_power_type != 1) {
    APW9_set_voltage(N);
    return;
  }
  i2c_write(N | 0x5200200);
  return;
}


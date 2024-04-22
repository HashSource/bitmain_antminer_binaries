
/* WARNING: Unknown calling convention */

void APW8_set_voltage(uchar N)

{
  i2c_write(N | 0x5200200);
  return;
}


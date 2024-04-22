
/* WARNING: Unknown calling convention */

void do_calibration_temperature_sensor(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] == 1) && (dev->chain_asic_num[chain] == '0')) {
      calibration_sensor_offset(chain);
      cgsleep_ms(10);
    }
  }
  return;
}


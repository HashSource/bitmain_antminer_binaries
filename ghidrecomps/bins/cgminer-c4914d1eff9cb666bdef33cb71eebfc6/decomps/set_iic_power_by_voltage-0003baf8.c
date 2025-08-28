
_Bool set_iic_power_by_voltage(double target_vol,power_info_t *power)

{
  uint8_t da_value;
  FILE *__stream;
  power_info_t *power_local;
  double target_vol_local;
  FILE *pFile;
  uint8_t iic_vol_data;
  
  power->is_voltage_stable = true;
  da_value = get_power_iic_value_from_voltage(target_vol);
  power_set_voltage(power,da_value);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: now setting voltage to : %f \n","power.c",0x2b1,
              "set_iic_power_by_voltage");
    }
    fclose(__stream);
  }
  usleep(300000);
  power->current_voltage = target_vol;
  power->current_iic_data = da_value;
  return true;
}


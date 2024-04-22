
_Bool set_iic_power_by_voltage(double target_vol,power_info_t *power)

{
  uint8_t da_value;
  FILE *__stream;
  undefined8 in_d0;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  power_info_t *power_local;
  double target_vol_local;
  FILE *pFile;
  uint8_t iic_vol_data;
  
  power->is_voltage_stable = true;
  da_value = get_power_iic_value_from_voltage((double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0))
  ;
  power_set_voltage(da_value);
  target_vol_local._0_4_ = (undefined4)in_d0;
  target_vol_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: now setting voltage to : %f \n","power.c",0x21c,
              "set_iic_power_by_voltage");
    }
    fclose(__stream);
  }
  usleep(300000);
  *(undefined4 *)&power->current_voltage = target_vol_local._0_4_;
  *(undefined4 *)((int)&power->current_voltage + 4) = target_vol_local._4_4_;
  power->current_iic_data = da_value;
  return true;
}


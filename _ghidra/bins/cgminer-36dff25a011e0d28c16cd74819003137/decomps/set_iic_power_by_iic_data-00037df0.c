
_Bool set_iic_power_by_iic_data(uint8_t target_data,power_info_t *power)

{
  FILE *__stream;
  double dVar1;
  power_info_t *power_local;
  uint8_t target_data_local;
  FILE *pFile;
  double voltage;
  
  power->is_voltage_stable = true;
  dVar1 = get_power_voltage_from_iic_value(target_data);
  power_set_voltage(target_data);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: now setting voltage to : %f \n","power.c",0x231,
              "set_iic_power_by_iic_data");
    }
    fclose(__stream);
  }
  usleep(300000);
  voltage._0_4_ = SUB84(dVar1,0);
  voltage._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  *(undefined4 *)&power->current_voltage = voltage._0_4_;
  *(undefined4 *)((int)&power->current_voltage + 4) = voltage._4_4_;
  power->current_iic_data = target_data;
  return true;
}


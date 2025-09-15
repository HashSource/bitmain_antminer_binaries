
void set_working_voltage(double working_voltage)

{
  FILE *__stream;
  double working_voltage_local;
  FILE *pFile;
  
  if (3 < log_level) {
    power_info[0].working_voltage = working_voltage;
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: working_voltage = %f\n","power.c",0xdb,"set_working_voltage");
    }
    fclose(__stream);
    working_voltage = power_info[0].working_voltage;
  }
  power_info[0].working_voltage._4_4_ = (undefined4)((ulonglong)working_voltage >> 0x20);
  power_info[0].working_voltage._0_4_ = SUB84(working_voltage,0);
  return;
}


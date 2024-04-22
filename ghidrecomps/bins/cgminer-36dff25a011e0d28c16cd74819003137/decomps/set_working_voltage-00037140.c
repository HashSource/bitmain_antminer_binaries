
void set_working_voltage(double working_voltage)

{
  FILE *__stream;
  undefined8 in_d0;
  double working_voltage_local;
  FILE *pFile;
  
  working_voltage_local._0_4_ = (undefined4)in_d0;
  working_voltage_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  power_info.working_voltage._0_4_ = working_voltage_local._0_4_;
  power_info.working_voltage._4_4_ = working_voltage_local._4_4_;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: working_voltage = %f\n","power.c",0xd5,"set_working_voltage");
    }
    fclose(__stream);
  }
  return;
}


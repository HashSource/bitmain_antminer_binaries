
double get_power_voltage_from_iic_value(uint8_t data)

{
  _Bool _Var1;
  FILE *__stream;
  uint8_t data_local;
  FILE *pFile;
  double voltage;
  
  _Var1 = power_is_support_cmd_package();
  if (_Var1) {
    voltage = (DAT_00037cc8 - (double)(longlong)(int)(uint)data) / DAT_00037cd0;
  }
  else {
    voltage = (DAT_00037cd8 - (double)(longlong)(int)(uint)data) / DAT_00037ce0;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: iic_index for voltage[%d] = %f\n","power.c",0x20a,
              "get_power_voltage_from_iic_value",(uint)data,voltage._0_4_,voltage._4_4_);
    }
    fclose(__stream);
  }
  return voltage;
}


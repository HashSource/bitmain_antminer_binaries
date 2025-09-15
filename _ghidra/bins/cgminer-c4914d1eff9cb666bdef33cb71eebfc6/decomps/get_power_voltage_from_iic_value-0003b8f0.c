
double get_power_voltage_from_iic_value(uint8_t data)

{
  _Bool _Var1;
  FILE *__stream;
  uint8_t data_local;
  FILE *pFile;
  double voltage;
  
  _Var1 = is_T11();
  if (_Var1) {
    if ((char)data < '\0') {
      voltage = 0.0;
    }
    else if ((_g_minor_type == PKG_CE) || (_g_minor_type == PKG_B_BGM)) {
      voltage = ((double)data * 44.244 + 1943.4048) / ((double)data * 5.74 + 174.9552);
    }
    else {
      voltage = ((double)data * 43.956 + 1899.7248) / ((double)data * 5.26 + 161.5872);
    }
  }
  else {
    _Var1 = power_is_support_cmd_package();
    if (_Var1) {
      voltage = (1215.89444 - (double)data) / 59.931507;
    }
    else {
      voltage = (1718.459125 - (double)data) / 85.509875;
    }
  }
  _Var1 = is_T11();
  if ((!_Var1) && (3 < log_level)) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: iic_index for voltage[%d] = %f\n","power.c",0x2a4,
              "get_power_voltage_from_iic_value",(uint)data,voltage._0_4_,voltage._4_4_);
    }
    fclose(__stream);
  }
  return voltage;
}


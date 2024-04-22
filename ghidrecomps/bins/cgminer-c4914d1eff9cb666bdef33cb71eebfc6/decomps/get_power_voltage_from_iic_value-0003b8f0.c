
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
      voltage = ((double)(longlong)(int)(uint)data * DAT_0003ba98 + DAT_0003baa0) /
                ((double)(longlong)(int)(uint)data * DAT_0003baa8 + DAT_0003bab0);
    }
    else {
      voltage = ((double)(longlong)(int)(uint)data * DAT_0003bab8 + DAT_0003bac0) /
                ((double)(longlong)(int)(uint)data * DAT_0003bac8 + DAT_0003bad0);
    }
  }
  else {
    _Var1 = power_is_support_cmd_package();
    if (_Var1) {
      voltage = (DAT_0003bad8 - (double)(longlong)(int)(uint)data) / DAT_0003bae0;
    }
    else {
      voltage = (DAT_0003bae8 - (double)(longlong)(int)(uint)data) / DAT_0003baf0;
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


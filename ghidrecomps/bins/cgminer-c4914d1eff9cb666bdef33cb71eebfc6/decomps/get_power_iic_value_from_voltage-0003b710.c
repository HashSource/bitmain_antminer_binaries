
uint8_t get_power_iic_value_from_voltage(double voltage)

{
  _Bool _Var1;
  FILE *__stream;
  double in_d0;
  double dVar2;
  uint8_t local_1c;
  double voltage_local;
  FILE *pFile;
  uint8_t iic_index;
  
  _Var1 = is_T11();
  if (_Var1) {
    if ((_g_minor_type == PKG_CE) || (_g_minor_type == PKG_B_BGM)) {
      dVar2 = (DAT_0003b898 - in_d0 * DAT_0003b890) / (in_d0 * DAT_0003b8a0 - DAT_0003b8a8);
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
    else {
      dVar2 = (DAT_0003b8b8 - in_d0 * DAT_0003b8b0) / (in_d0 * DAT_0003b8c0 - DAT_0003b8c8);
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
    if ((char)iic_index < '\0') {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: %d iic data is more than voltage max iic data 127\n","power.c"
                  ,0x261,"get_power_iic_value_from_voltage",(uint)iic_index);
        }
        fclose(__stream);
      }
      iic_index = '\x7f';
    }
  }
  else {
    _Var1 = power_is_support_cmd_package();
    if (_Var1) {
      dVar2 = DAT_0003b8d8 - in_d0 * DAT_0003b8d0;
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
    else {
      dVar2 = DAT_0003b8e8 - in_d0 * DAT_0003b8e0;
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
  }
  return iic_index;
}



uint8_t get_power_iic_value_from_voltage(double voltage)

{
  _Bool _Var1;
  FILE *__stream;
  double dVar2;
  uint8_t local_1c;
  double voltage_local;
  FILE *pFile;
  uint8_t iic_index;
  
  _Var1 = is_T11();
  if (_Var1) {
    if ((_g_minor_type == PKG_CE) || (_g_minor_type == PKG_B_BGM)) {
      dVar2 = (1943.4048 - voltage * 174.9552) / (voltage * 5.74 - 44.244);
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
    else {
      dVar2 = (1899.7248 - voltage * 161.5872) / (voltage * 5.26 - 43.956);
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
      dVar2 = 1215.89444 - voltage * 59.931507;
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
    else {
      dVar2 = 1718.459125 - voltage * 85.509875;
      local_1c = (0.0 < dVar2) * (char)(longlong)dVar2;
      iic_index = local_1c;
    }
  }
  return iic_index;
}



_Bool slowly_set_iic_power_to_custom_voltage(double custom_voltage)

{
  _Bool _Var1;
  FILE *__stream;
  double custom_voltage_local;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: slowly setting to voltage: %0.2f ...\n","power.c",0x391,
              "slowly_set_iic_power_to_custom_voltage");
    }
    fclose(__stream);
  }
  _Var1 = slowly_adapt_voltage(power_info,custom_voltage,0);
  if (!_Var1) {
    freq_scan_error_code_set(0xc,0);
    stop_mining("power set failed!\n");
  }
  return _Var1;
}



/* WARNING: Unknown calling convention */

_Bool set_iic_power_to_highest_voltage(void)

{
  _Bool _Var1;
  FILE *__stream;
  char *in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      in_stack_ffffffc8 = "set_iic_power_to_highest_voltage";
      fprintf(__stream,"%s:%d:%s: setting to hightest voltage: %0.2f ...\n","power.c",0x2e5);
    }
    fclose(__stream);
  }
  _Var1 = set_iic_power_by_voltage((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8),power_info)
  ;
  if (!_Var1) {
    freq_scan_error_code_set(0xc,0);
  }
  return _Var1;
}


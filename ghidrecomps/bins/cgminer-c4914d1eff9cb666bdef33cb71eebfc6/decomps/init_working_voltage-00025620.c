
/* WARNING: Unknown calling convention */

void init_working_voltage(void)

{
  _Bool _Var1;
  FILE *__stream;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  FILE *pFile;
  
  _Var1 = is_fixed_mode();
  if (_Var1) {
    _set_working_voltage((double)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: set fixed voltage to %f\n","driver-btm-soc.c",0x1609,
                "init_working_voltage");
      }
      fclose(__stream);
    }
  }
  else {
    get_working_voltage_from_eeprom();
  }
  return;
}


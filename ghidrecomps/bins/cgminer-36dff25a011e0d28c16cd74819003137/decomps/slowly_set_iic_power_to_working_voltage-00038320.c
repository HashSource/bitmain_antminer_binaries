
/* WARNING: Unknown calling convention */

_Bool slowly_set_iic_power_to_working_voltage(void)

{
  _Bool _Var1;
  FILE *__stream;
  char *in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  sprintf(displayed_working_voltage,"%.2f",power_info.working_voltage._0_4_,
          power_info.working_voltage._4_4_);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      in_stack_ffffffd0 = "slowly_set_iic_power_to_working_voltage";
      fprintf(__stream,"%s:%d:%s: slowly setting to voltage: %0.2f ...\n","power.c",0x2e8);
    }
    fclose(__stream);
  }
  _Var1 = slowly_adapt_voltage((double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0),0);
  if (!_Var1) {
    stop_mining("power set failed!\n");
  }
  return _Var1;
}


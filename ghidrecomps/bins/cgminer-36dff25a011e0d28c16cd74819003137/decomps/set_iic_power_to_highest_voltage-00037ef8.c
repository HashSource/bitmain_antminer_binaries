
/* WARNING: Unknown calling convention */

_Bool set_iic_power_to_highest_voltage(void)

{
  _Bool _Var1;
  FILE *__stream;
  char *in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      in_stack_ffffffd0 = "set_iic_power_to_highest_voltage";
      fprintf(__stream,"%s:%d:%s: setting to voltage: %0.2f ...\n","power.c",0x24f);
    }
    fclose(__stream);
  }
  _Var1 = set_iic_power_by_voltage
                    ((double)CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0),&power_info);
  if (!_Var1) {
    stop_mining("power set failed!\n");
  }
  return _Var1;
}


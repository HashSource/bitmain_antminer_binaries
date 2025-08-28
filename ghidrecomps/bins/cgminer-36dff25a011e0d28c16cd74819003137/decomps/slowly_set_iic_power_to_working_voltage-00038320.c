
/* WARNING: Unknown calling convention */

_Bool slowly_set_iic_power_to_working_voltage(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  _Bool _Var3;
  FILE *__stream;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  uVar2 = power_info.working_voltage._4_4_;
  uVar1 = power_info.working_voltage._0_4_;
  sprintf(displayed_working_voltage,"%.2f",power_info.working_voltage._0_4_,
          power_info.working_voltage._4_4_);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: slowly setting to voltage: %0.2f ...\n","power.c",0x2e8,
              "slowly_set_iic_power_to_working_voltage");
    }
    fclose(__stream);
  }
  _Var3 = slowly_adapt_voltage((double)CONCAT44(uVar2,uVar1),0);
  if (!_Var3) {
    stop_mining("power set failed!\n");
  }
  return _Var3;
}


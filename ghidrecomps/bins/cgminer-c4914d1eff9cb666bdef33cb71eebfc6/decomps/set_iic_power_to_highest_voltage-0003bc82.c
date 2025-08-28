
/* WARNING: Unknown calling convention */

_Bool set_iic_power_to_highest_voltage(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  _Bool _Var3;
  FILE *__stream;
  FILE *pFile;
  double target_vol;
  power_info_t *power;
  
  uVar2 = power_info[0].highest_voltage._4_4_;
  uVar1 = power_info[0].highest_voltage._0_4_;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: setting to hightest voltage: %0.2f ...\n","power.c",0x2e5,
              "set_iic_power_to_highest_voltage");
    }
    fclose(__stream);
  }
  _Var3 = set_iic_power_by_voltage((double)CONCAT44(uVar2,uVar1),power_info);
  if (!_Var3) {
    freq_scan_error_code_set(0xc,0);
  }
  return _Var3;
}


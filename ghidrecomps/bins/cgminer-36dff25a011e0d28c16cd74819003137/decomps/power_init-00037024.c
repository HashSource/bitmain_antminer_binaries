
/* WARNING: Unknown calling convention */

void power_init(void)

{
  FILE *__stream;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: power init ... \n","power.c",0xc4,"power_init");
    }
    fclose(__stream);
  }
  power_info.is_voltage_stable = false;
  power_info.current_voltage._0_4_ = 0;
  power_info.current_voltage._4_4_ = 0;
  power_info.working_voltage._0_4_ = 0xc0000000;
  power_info.working_voltage._4_4_ = 0x40324ccc;
  power_info.higher_voltage._0_4_ = 0;
  power_info.higher_voltage._4_4_ = 0;
  power_info.highest_voltage._0_4_ = 0;
  power_info.highest_voltage._4_4_ = 0x40340000;
  power_info.current_iic_data = '\0';
  power_check_protocal_type();
  return;
}


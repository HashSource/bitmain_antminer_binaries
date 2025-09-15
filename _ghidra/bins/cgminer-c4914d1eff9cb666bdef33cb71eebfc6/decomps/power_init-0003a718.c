
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void power_init(void)

{
  _Bool _Var1;
  FILE *__stream;
  FILE *pFile;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: power init ... \n","power.c",0xb7,"power_init");
    }
    fclose(__stream);
  }
  _Var1 = is_T11();
  if (_Var1) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        power_info[chain].is_voltage_stable = false;
        *(undefined4 *)&power_info[chain].current_voltage = 0;
        *(undefined4 *)((int)&power_info[chain].current_voltage + 4) = 0;
        *(undefined4 *)&power_info[chain].working_voltage = 0xa0000000;
        *(undefined4 *)((int)&power_info[chain].working_voltage + 4) = 0x40239999;
        *(undefined4 *)&power_info[chain].higher_voltage = 0;
        *(undefined4 *)((int)&power_info[chain].higher_voltage + 4) = 0;
        *(undefined4 *)&power_info[chain].highest_voltage = 0x60000000;
        *(undefined4 *)((int)&power_info[chain].highest_voltage + 4) = 0x40246666;
        power_info[chain].current_iic_data = '\0';
        power_info[chain].chain_num = (uint8_t)chain;
        _g_minor_type = g_minor_type[chain];
      }
    }
  }
  else {
    power_info[0].is_voltage_stable = false;
    power_info[0].current_voltage._0_4_ = 0;
    power_info[0].current_voltage._4_4_ = 0;
    power_info[0].working_voltage._0_4_ = 0xa0000000;
    power_info[0].working_voltage._4_4_ = 0x40239999;
    power_info[0].higher_voltage._0_4_ = 0;
    power_info[0].higher_voltage._4_4_ = 0;
    power_info[0].highest_voltage._0_4_ = 0x60000000;
    power_info[0].highest_voltage._4_4_ = 0x40246666;
    power_info[0].chain_num = 0xff;
  }
  _Var1 = is_T11();
  if (!_Var1) {
    power_check_protocal_type();
    power_on();
  }
  return;
}


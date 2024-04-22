
/* WARNING: Unknown calling convention */

void power_init(void)

{
  undefined4 uVar1;
  _Bool _Var2;
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
  _Var2 = is_T11();
  if (_Var2) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        power_info[chain].is_voltage_stable = false;
        *(undefined4 *)&power_info[chain].current_voltage = 0;
        *(undefined4 *)((int)&power_info[chain].current_voltage + 4) = 0;
        uVar1 = DAT_0003a944;
        *(undefined4 *)&power_info[chain].working_voltage = DAT_0003a940;
        *(undefined4 *)((int)&power_info[chain].working_voltage + 4) = uVar1;
        *(undefined4 *)&power_info[chain].higher_voltage = 0;
        *(undefined4 *)((int)&power_info[chain].higher_voltage + 4) = 0;
        uVar1 = DAT_0003a94c;
        *(undefined4 *)&power_info[chain].highest_voltage = DAT_0003a948;
        *(undefined4 *)((int)&power_info[chain].highest_voltage + 4) = uVar1;
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
    power_info[0].working_voltage._0_4_ = DAT_0003a940;
    power_info[0].working_voltage._4_4_ = DAT_0003a944;
    power_info[0].higher_voltage._0_4_ = 0;
    power_info[0].higher_voltage._4_4_ = 0;
    power_info[0].highest_voltage._0_4_ = DAT_0003a948;
    power_info[0].highest_voltage._4_4_ = DAT_0003a94c;
    power_info[0].chain_num = 0xff;
  }
  _Var2 = is_T11();
  if (!_Var2) {
    power_check_protocal_type();
    power_on();
  }
  return;
}


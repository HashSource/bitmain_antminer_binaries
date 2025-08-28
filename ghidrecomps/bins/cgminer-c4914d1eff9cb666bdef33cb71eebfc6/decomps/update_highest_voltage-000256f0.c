
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void update_highest_voltage(void)

{
  _Bool _Var1;
  double hpf_working_volt;
  FILE *pFile;
  FILE *pFile_1;
  double max_volt;
  int chain;
  
  hpf_working_volt._0_4_ = 0;
  hpf_working_volt._4_4_ = 0;
  max_volt = 0.0;
  _Var1 = is_T11();
  if ((_Var1) && (_Var1 = is_fixed_mode(), !_Var1)) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        eeprom_get_voltage_mode2((uint8_t)chain,&hpf_working_volt);
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile = (FILE *)fopen(log_file,"a+");
          if (pFile != (FILE *)0x0) {
            fprintf((FILE *)pFile,"%s:%d:%s: chain %d hpf working voltage %.2f\n","driver-btm-soc.c"
                    ,0x161c,"update_highest_voltage",chain,hpf_working_volt._0_4_,
                    hpf_working_volt._4_4_);
          }
          fclose((FILE *)pFile);
        }
        if ((int)((uint)(max_volt < (double)CONCAT44(hpf_working_volt._4_4_,hpf_working_volt._0_4_))
                 << 0x1f) < 0) {
          max_volt = (double)CONCAT44(hpf_working_volt._4_4_,hpf_working_volt._0_4_);
        }
      }
    }
    max_volt = max_volt * 1.08;
    if (10.199999809265137 < max_volt) {
      max_volt = 10.199999809265137;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        fprintf((FILE *)pFile_1,"%s:%d:%s: open core at max voltage %.2f\n","driver-btm-soc.c",
                0x1625,"update_highest_voltage");
      }
      fclose((FILE *)pFile_1);
    }
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        set_highest_voltage_by_chain((uint8_t)chain,max_volt);
      }
    }
  }
  return;
}


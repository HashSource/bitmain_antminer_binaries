
void set_working_voltage_by_chain(uint8_t chain,double working_voltage)

{
  FILE *pFVar1;
  undefined8 in_d0;
  double working_voltage_local;
  uint8_t chain_local;
  FILE *pFile;
  FILE *pFile_1;
  
  if (dev->chain_exist[chain] == 1) {
    working_voltage_local._0_4_ = (undefined4)in_d0;
    working_voltage_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
    *(undefined4 *)&power_info[chain].working_voltage = working_voltage_local._0_4_;
    *(undefined4 *)((int)&power_info[chain].working_voltage + 4) = working_voltage_local._4_4_;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: chain[%d] working_voltage = %f\n","power.c",0xe4,
                "set_working_voltage_by_chain",(uint)chain,
                *(undefined4 *)&power_info[chain].working_voltage,
                *(undefined4 *)((int)&power_info[chain].working_voltage + 4));
      }
      fclose(pFVar1);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0xe8,
              "set_working_voltage_by_chain",(uint)chain);
    }
    fclose(pFVar1);
  }
  return;
}


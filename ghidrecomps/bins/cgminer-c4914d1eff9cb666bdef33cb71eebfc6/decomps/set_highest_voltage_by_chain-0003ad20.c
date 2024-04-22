
void set_highest_voltage_by_chain(uint8_t chain,double highest_voltage)

{
  FILE *__stream;
  undefined8 in_d0;
  double highest_voltage_local;
  uint8_t chain_local;
  FILE *pFile;
  
  if (dev->chain_exist[chain] == 1) {
    highest_voltage_local._0_4_ = (undefined4)in_d0;
    highest_voltage_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
    *(undefined4 *)&power_info[chain].highest_voltage = highest_voltage_local._0_4_;
    *(undefined4 *)((int)&power_info[chain].highest_voltage + 4) = highest_voltage_local._4_4_;
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x10d,
              "set_highest_voltage_by_chain",(uint)chain);
    }
    fclose(__stream);
  }
  return;
}


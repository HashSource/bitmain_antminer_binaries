
void set_highest_voltage_by_chain(uint8_t chain,double highest_voltage)

{
  FILE *__stream;
  double highest_voltage_local;
  uint8_t chain_local;
  FILE *pFile;
  
  if (dev->chain_exist[chain] == 1) {
    power_info[chain].highest_voltage = highest_voltage;
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


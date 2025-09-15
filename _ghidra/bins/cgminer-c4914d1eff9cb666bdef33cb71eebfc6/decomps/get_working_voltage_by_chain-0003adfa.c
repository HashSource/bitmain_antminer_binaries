
double get_working_voltage_by_chain(uint8_t chain)

{
  FILE *__stream;
  undefined4 uVar1;
  undefined4 uVar2;
  uint8_t chain_local;
  FILE *pFile;
  
  if (dev->chain_exist[chain] == 1) {
    uVar1 = *(undefined4 *)&power_info[chain].working_voltage;
    uVar2 = *(undefined4 *)((int)&power_info[chain].working_voltage + 4);
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x11e,
                "get_working_voltage_by_chain",(uint)chain);
      }
      fclose(__stream);
    }
    uVar1 = 0;
    uVar2 = 0;
  }
  return (double)CONCAT44(uVar2,uVar1);
}


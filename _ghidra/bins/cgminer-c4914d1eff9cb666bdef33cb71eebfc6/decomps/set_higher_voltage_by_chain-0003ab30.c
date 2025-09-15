
void set_higher_voltage_by_chain(uint8_t chain,double higher_voltage)

{
  FILE *pFVar1;
  double higher_voltage_local;
  uint8_t chain_local;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  
  if (dev->chain_exist[chain] == 1) {
    higher_voltage_local = higher_voltage;
    if (10.800000190734863 < higher_voltage) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          higher_voltage_local._0_4_ = SUB84(higher_voltage,0);
          higher_voltage_local._4_4_ = (undefined4)((ulonglong)higher_voltage >> 0x20);
          fprintf(pFVar1,
                  "%s:%d:%s: warning!!!chain[%d] higher_voltage = %f,max_higher_voltage = %f\n",
                  "power.c",0xf8,"set_higher_voltage_by_chain",(uint)chain,
                  higher_voltage_local._0_4_,higher_voltage_local._4_4_,0xa0000000,0x40259999);
        }
        fclose(pFVar1);
      }
      higher_voltage_local = 10.800000190734863;
    }
    *(undefined4 *)&power_info[chain].higher_voltage = higher_voltage_local._0_4_;
    *(undefined4 *)((int)&power_info[chain].higher_voltage + 4) = higher_voltage_local._4_4_;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: chain[%d] higher_voltage = %f\n","power.c",0xfd,
                "set_higher_voltage_by_chain",(uint)chain,
                *(undefined4 *)&power_info[chain].higher_voltage,
                *(undefined4 *)((int)&power_info[chain].higher_voltage + 4));
      }
      fclose(pFVar1);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x101,
              "set_higher_voltage_by_chain",(uint)chain);
    }
    fclose(pFVar1);
  }
  return;
}


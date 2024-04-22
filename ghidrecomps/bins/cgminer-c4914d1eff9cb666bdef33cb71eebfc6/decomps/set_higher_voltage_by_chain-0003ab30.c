
void set_higher_voltage_by_chain(uint8_t chain,double higher_voltage)

{
  double dVar1;
  FILE *pFVar2;
  double in_d0;
  double higher_voltage_local;
  uint8_t chain_local;
  FILE *pFile_1;
  FILE *pFile;
  FILE *pFile_2;
  
  if (dev->chain_exist[chain] == 1) {
    dVar1 = (double)CONCAT44(DAT_0003ad18._4_4_,(undefined4)DAT_0003ad18);
    higher_voltage_local = in_d0;
    if (in_d0 != dVar1 && in_d0 < dVar1 == (NAN(in_d0) || NAN(dVar1))) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          higher_voltage_local._0_4_ = SUB84(in_d0,0);
          higher_voltage_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
          fprintf(pFVar2,
                  "%s:%d:%s: warning!!!chain[%d] higher_voltage = %f,max_higher_voltage = %f\n",
                  "power.c",0xf8,"set_higher_voltage_by_chain",(uint)chain,
                  higher_voltage_local._0_4_,higher_voltage_local._4_4_,(undefined4)DAT_0003ad18,
                  DAT_0003ad18._4_4_);
        }
        fclose(pFVar2);
      }
      higher_voltage_local = (double)CONCAT44(DAT_0003ad18._4_4_,(undefined4)DAT_0003ad18);
    }
    *(undefined4 *)&power_info[chain].higher_voltage = higher_voltage_local._0_4_;
    *(undefined4 *)((int)&power_info[chain].higher_voltage + 4) = higher_voltage_local._4_4_;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: chain[%d] higher_voltage = %f\n","power.c",0xfd,
                "set_higher_voltage_by_chain",(uint)chain,
                *(undefined4 *)&power_info[chain].higher_voltage,
                *(undefined4 *)((int)&power_info[chain].higher_voltage + 4));
      }
      fclose(pFVar2);
    }
  }
  else if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x101,
              "set_higher_voltage_by_chain",(uint)chain);
    }
    fclose(pFVar2);
  }
  return;
}


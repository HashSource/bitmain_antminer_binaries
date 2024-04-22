
_Bool set_iic_power_to_highest_voltage_by_chain(int8_t chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *in_stack_ffffffc0;
  int in_stack_ffffffc4;
  int8_t chain_local;
  FILE *pFile;
  FILE *pFile_1;
  double target_vol;
  power_info_t *power;
  
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x2f6,
                "set_iic_power_to_highest_voltage_by_chain",(int)chain);
      }
      fclose(pFVar2);
    }
    _Var1 = false;
  }
  else {
    uVar3 = *(undefined4 *)&power_info[chain].highest_voltage;
    uVar4 = *(undefined4 *)((int)&power_info[chain].highest_voltage + 4);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        in_stack_ffffffc4 = (int)chain;
        in_stack_ffffffc0 = "set_iic_power_to_highest_voltage_by_chain";
        fprintf(pFVar2,"%s:%d:%s: chain[%d] setting to hightest voltage: %0.2f ...\n","power.c",
                0x2fb,"set_iic_power_to_highest_voltage_by_chain",in_stack_ffffffc4,uVar3,uVar4);
      }
      fclose(pFVar2);
    }
    _Var1 = set_iic_power_by_voltage
                      ((double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0),power_info + chain);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      freq_scan_error_code_set(0xc,0);
      _Var1 = false;
    }
  }
  return _Var1;
}



_Bool slowly_set_iic_power_to_working_voltage_by_chain(uint8_t chain)

{
  _Bool _Var1;
  FILE *pFVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *in_stack_ffffffc0;
  uint in_stack_ffffffc4;
  uint8_t chain_local;
  FILE *pFile;
  FILE *pFile_1;
  double target_vol;
  power_info_t *power;
  
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x3ca,
                "slowly_set_iic_power_to_working_voltage_by_chain",(uint)chain);
      }
      fclose(pFVar2);
    }
    _Var1 = false;
  }
  else {
    uVar3 = *(undefined4 *)&power_info[chain].working_voltage;
    uVar4 = *(undefined4 *)((int)&power_info[chain].working_voltage + 4);
    sprintf(displayed_working_voltage,"%.2f",uVar3,uVar4);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        in_stack_ffffffc4 = (uint)chain;
        in_stack_ffffffc0 = "slowly_set_iic_power_to_working_voltage_by_chain";
        fprintf(pFVar2,"%s:%d:%s: chain[%d] slowly setting to voltage: %0.2f ...\n","power.c",0x3d2,
                "slowly_set_iic_power_to_working_voltage_by_chain",in_stack_ffffffc4,uVar3,uVar4);
      }
      fclose(pFVar2);
    }
    _Var1 = slowly_adapt_voltage
                      (power_info + chain,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0),0);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      freq_scan_error_code_set(0xc,0);
      stop_mining("power set failed!\n");
      _Var1 = false;
    }
  }
  return _Var1;
}


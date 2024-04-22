
_Bool slowly_set_iic_power_to_custom_voltage_by_chain(uint8_t chain,double custom_voltage)

{
  _Bool _Var1;
  FILE *pFVar2;
  undefined8 in_d0;
  char *in_stack_ffffffb8;
  uint in_stack_ffffffbc;
  double custom_voltage_local;
  uint8_t chain_local;
  FILE *pFile;
  FILE *pFile_1;
  power_info_t *power;
  double target_vol;
  
  custom_voltage_local._0_4_ = (undefined4)in_d0;
  custom_voltage_local._4_4_ = (undefined4)((ulonglong)in_d0 >> 0x20);
  if (dev->chain_exist[chain] == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: error! chain[%d] does not exist!\n","power.c",0x3a3,
                "slowly_set_iic_power_to_custom_voltage_by_chain",(uint)chain);
      }
      fclose(pFVar2);
    }
    _Var1 = false;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        in_stack_ffffffbc = (uint)chain;
        in_stack_ffffffb8 = "slowly_set_iic_power_to_custom_voltage_by_chain";
        fprintf(pFVar2,"%s:%d:%s: chain[%d] slowly setting to voltage: %0.2f ...\n","power.c",0x3a7,
                "slowly_set_iic_power_to_custom_voltage_by_chain",in_stack_ffffffbc,
                custom_voltage_local._0_4_,custom_voltage_local._4_4_);
      }
      fclose(pFVar2);
    }
    _Var1 = slowly_adapt_voltage
                      (power_info + chain,(double)CONCAT44(in_stack_ffffffbc,in_stack_ffffffb8),0);
    if (_Var1) {
      _Var1 = true;
    }
    else {
      freq_scan_error_code_set(0xc,0);
      disable_pic_dac(chain);
      dev->chain_exist[chain] = 0;
      dev->chain_num = dev->chain_num + 0xff;
      _Var1 = false;
    }
  }
  return _Var1;
}



/* WARNING: Unknown calling convention */

void set_working_voltage_by_eeprom(void)

{
  char *in_stack_ffffffc8;
  int in_stack_ffffffcc;
  int voltage;
  FILE *pFile;
  FILE *pFile_1;
  int avg;
  int work_mode;
  int chain_num;
  int sum;
  int chain;
  
  sum = 0;
  avg = -1;
  chain_num = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      work_mode = (int)(opt_bitmain_economic_mode == false);
      eeprom_get_voltage(chain,work_mode,&voltage);
      sum = sum + voltage;
      chain_num = chain_num + 1;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          in_stack_ffffffc8 = "set_working_voltage_by_eeprom";
          in_stack_ffffffcc = chain;
          fprintf((FILE *)pFile,"%s:%d:%s: eeprom voltage[%d] = %d\n","driver-btm-soc.c",0x1c1e,
                  "set_working_voltage_by_eeprom",chain,voltage);
        }
        fclose((FILE *)pFile);
      }
    }
  }
  if (chain_num != 0) {
    avg = __aeabi_idiv(sum,chain_num);
    if (sum == chain_num * avg) {
      set_working_voltage((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
    }
    else if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_1 = (FILE *)fopen(log_file,"a+");
      if (pFile_1 != (FILE *)0x0) {
        get_working_voltage();
        fprintf((FILE *)pFile_1,
                "%s:%d:%s: Voltage are different. Will use default setting(voltage = %f).\n",
                "driver-btm-soc.c",0x1c2b,"set_working_voltage_by_eeprom");
      }
      fclose((FILE *)pFile_1);
    }
  }
  return;
}


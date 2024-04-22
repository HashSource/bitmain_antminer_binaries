
/* WARNING: Unknown calling convention */

void get_working_voltage_from_eeprom(void)

{
  _Bool _Var1;
  char *in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  double working_voltage;
  FILE *pFile;
  int chain;
  
  working_voltage = 0.0;
  chain = 0;
  do {
    if (0xf < chain) {
      return;
    }
    if (dev->chain_exist[chain] != 0) {
      _Var1 = is_economic_mode();
      if (_Var1) {
        eeprom_get_voltage_mode1((uint8_t)chain,&working_voltage);
      }
      else {
        eeprom_get_voltage_mode2((uint8_t)chain,&working_voltage);
      }
      _Var1 = is_column_sweep();
      if (_Var1) {
        working_voltage = working_voltage + DAT_00024420;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          in_stack_ffffffc8 = "get_working_voltage_from_eeprom";
          fprintf((FILE *)pFile,"%s:%d:%s: get working vol [%5.2f] from chain[%d] eeprom\n",
                  "driver-btm-soc.c",0x1330);
        }
        fclose((FILE *)pFile);
      }
      if ((working_voltage != 8.0 && working_voltage < 8.0 == NAN(working_voltage)) &&
         ((int)((uint)(working_voltage < 10.5) << 0x1f) < 0)) {
        _Var1 = is_T11();
        if (!_Var1) {
          set_working_voltage((double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
          return;
        }
        set_working_voltage_by_chain
                  ((uint8_t)chain,(double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
      }
    }
    chain = chain + 1;
  } while( true );
}



void decrease_voltage_at_high_temp(_Bool *high_chip_temp_flag)

{
  FILE *pFVar1;
  char *in_stack_ffffffd8;
  int in_stack_ffffffdc;
  _Bool *high_chip_temp_flag_local;
  FILE *pFile_1;
  FILE *pFile;
  int pwm;
  uint8_t chain;
  
  chain = '\0';
  while( true ) {
    if (0xf < chain) {
      if (((dev->fan_pwm != 'd') || (last_testpatten_highest_chip_temp < 0x5d)) ||
         (decrease_voltage_at_high_temp::working_volt_decreased_flag)) {
        if ((last_testpatten_highest_chip_temp < 0x57) &&
           (decrease_voltage_at_high_temp::working_volt_decreased_flag)) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              in_stack_ffffffd8 = "decrease_voltage_at_high_temp";
              in_stack_ffffffdc = last_testpatten_highest_chip_temp;
              fprintf(pFVar1,"%s:%d:%s: increase volt for max chip temp is %d\n","driver-btm-soc.c",
                      0xdeb);
            }
            fclose(pFVar1);
          }
          for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
            if (dev->chain_exist[chain] != 0) {
              get_working_voltage_by_chain(chain);
              set_working_voltage_by_chain
                        (chain,(double)CONCAT44(in_stack_ffffffdc,in_stack_ffffffd8));
            }
          }
          slowly_set_iic_power_voltage_t11(1);
          decrease_voltage_at_high_temp::working_volt_decreased_flag = false;
        }
      }
      else {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            in_stack_ffffffd8 = "decrease_voltage_at_high_temp";
            in_stack_ffffffdc = last_testpatten_highest_chip_temp;
            fprintf(pFVar1,"%s:%d:%s: decrease volt for max chip temp is %d\n","driver-btm-soc.c",
                    0xddf);
          }
          fclose(pFVar1);
        }
        for (chain = '\0'; chain < 0x10; chain = chain + '\x01') {
          if (dev->chain_exist[chain] != 0) {
            get_working_voltage_by_chain(chain);
            set_working_voltage_by_chain
                      (chain,(double)CONCAT44(in_stack_ffffffdc,in_stack_ffffffd8));
          }
        }
        slowly_set_iic_power_voltage_t11(1);
        decrease_voltage_at_high_temp::working_volt_decreased_flag = true;
      }
      *high_chip_temp_flag = decrease_voltage_at_high_temp::working_volt_decreased_flag;
      return;
    }
    if ((dev->chain_exist[chain] != 0) && (g_minor_type[chain] != PKG_B_BGM)) break;
    chain = chain + '\x01';
  }
  return;
}


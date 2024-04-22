
void volt_decrease_for_mode0(double lower_limit_volt,double delta_volt,_Bool *increased_flag)

{
  double in_d0;
  double in_d1;
  char *in_stack_ffffff98;
  int in_stack_ffffff9c;
  _Bool *increased_flag_local;
  double delta_volt_local;
  double lower_limit_volt_local;
  double working_voltage;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile;
  double custom_voltage;
  int chain;
  
  custom_voltage = 0.0;
  working_voltage._0_4_ = 0;
  working_voltage._4_4_ = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      custom_voltage = get_current_voltage_by_chain((uint8_t)chain);
      eeprom_get_voltage_mode2((uint8_t)chain,&working_voltage);
      if ((increased_flag[chain] == true) ||
         (-1 < (int)((uint)(custom_voltage <
                           (double)CONCAT44(working_voltage._4_4_,working_voltage._0_4_)) << 0x1f)))
      {
        if ((int)((uint)(custom_voltage < in_d0) << 0x1f) < 0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFile_1 = (FILE *)fopen(log_file,"a+");
            if (pFile_1 != (FILE *)0x0) {
              in_stack_ffffff98 = "volt_decrease_for_mode0";
              in_stack_ffffff9c = chain;
              fprintf((FILE *)pFile_1,
                      "%s:%d:%s: chain[%d] is not sanctified with decreasing requirements\n",
                      "driver-btm-soc.c",0xd37);
            }
            fclose((FILE *)pFile_1);
          }
        }
        else {
          if (in_d0 < custom_voltage - in_d1 == (NAN(in_d0) || NAN(custom_voltage - in_d1))) {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_2 = (FILE *)fopen(log_file,"a+");
              if (pFile_2 != (FILE *)0x0) {
                in_stack_ffffff98 = "volt_decrease_for_mode0";
                in_stack_ffffff9c = chain;
                fprintf((FILE *)pFile_2,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0xd3c,"volt_decrease_for_mode0",chain,
                        custom_voltage._0_4_,custom_voltage._4_4_,SUB84(in_d0,0));
              }
              fclose((FILE *)pFile_2);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain
                      ((uint8_t)chain,(double)CONCAT44(in_stack_ffffff9c,in_stack_ffffff98));
            increased_flag[chain] = false;
          }
          else {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_3 = (FILE *)fopen(log_file,"a+");
              if (pFile_3 != (FILE *)0x0) {
                in_stack_ffffff98 = "volt_decrease_for_mode0";
                in_stack_ffffff9c = chain;
                fprintf((FILE *)pFile_3,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0xd42,"volt_decrease_for_mode0",chain,
                        custom_voltage._0_4_,custom_voltage._4_4_,custom_voltage - in_d1);
              }
              fclose((FILE *)pFile_3);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain
                      ((uint8_t)chain,(double)CONCAT44(in_stack_ffffff9c,in_stack_ffffff98));
          }
          if (custom_voltage - in_d1 ==
              (double)CONCAT44(working_voltage._4_4_,working_voltage._0_4_)) {
            increased_flag[chain] = false;
          }
        }
      }
      else if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          in_stack_ffffff98 = "volt_decrease_for_mode0";
          in_stack_ffffff9c = chain;
          fprintf((FILE *)pFile,
                  "%s:%d:%s: chain[%d] is not sanctified with decreasing requirements\n",
                  "driver-btm-soc.c",0xd31);
        }
        fclose((FILE *)pFile);
      }
    }
  }
  return;
}



void volt_decrease_for_mode0(double lower_limit_volt,double delta_volt,_Bool *increased_flag)

{
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
        if ((int)((uint)(custom_voltage < lower_limit_volt) << 0x1f) < 0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFile_1 = (FILE *)fopen(log_file,"a+");
            if (pFile_1 != (FILE *)0x0) {
              fprintf((FILE *)pFile_1,
                      "%s:%d:%s: chain[%d] is not sanctified with decreasing requirements\n",
                      "driver-btm-soc.c",0xd37,"volt_decrease_for_mode0",chain);
            }
            fclose((FILE *)pFile_1);
          }
        }
        else {
          if (lower_limit_volt < custom_voltage - delta_volt) {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_3 = (FILE *)fopen(log_file,"a+");
              if (pFile_3 != (FILE *)0x0) {
                fprintf((FILE *)pFile_3,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0xd42,"volt_decrease_for_mode0",chain,
                        custom_voltage._0_4_,custom_voltage._4_4_,custom_voltage - delta_volt);
              }
              fclose((FILE *)pFile_3);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain
                      ((uint8_t)chain,custom_voltage - delta_volt);
          }
          else {
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_2 = (FILE *)fopen(log_file,"a+");
              if (pFile_2 != (FILE *)0x0) {
                fprintf((FILE *)pFile_2,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0xd3c,"volt_decrease_for_mode0",chain,
                        custom_voltage._0_4_,custom_voltage._4_4_,SUB84(lower_limit_volt,0));
              }
              fclose((FILE *)pFile_2);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain((uint8_t)chain,lower_limit_volt);
            increased_flag[chain] = false;
          }
          if (custom_voltage - delta_volt ==
              (double)CONCAT44(working_voltage._4_4_,working_voltage._0_4_)) {
            increased_flag[chain] = false;
          }
        }
      }
      else if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,
                  "%s:%d:%s: chain[%d] is not sanctified with decreasing requirements\n",
                  "driver-btm-soc.c",0xd31,"volt_decrease_for_mode0",chain);
        }
        fclose((FILE *)pFile);
      }
    }
  }
  return;
}


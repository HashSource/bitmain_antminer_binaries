
void volt_increase_for_mode0
               (double upper_limit_volt,double delta_volt,_Bool *increased_flag,
               _Bool *outer_reopen_flag)

{
  uint8_t chain_00;
  FILE *pFVar1;
  int fan_pwm;
  double dVar2;
  _Bool *outer_reopen_flag_local;
  _Bool *increased_flag_local;
  double delta_volt_local;
  double upper_limit_volt_local;
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  double custom_voltage;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      chain_00 = (uint8_t)chain;
      dVar2 = get_current_voltage_by_chain(chain_00);
      if (dVar2 < upper_limit_volt) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,
                    "%s:%d:%s: chain[%d] start reopen core for low temperature voltage increment\n",
                    "driver-btm-soc.c",0xd5f,"volt_increase_for_mode0",chain);
          }
          fclose(pFVar1);
        }
        fan_pwm = get_reopen_pwm();
        re_open_core_by_chain(fan_pwm,chain,true);
        sleep(0x1e);
        reCalculateAVG();
        recalc_hashrate();
        custom_voltage._0_4_ = SUB84(dVar2,0);
        custom_voltage._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
        if (dVar2 + delta_volt < upper_limit_volt) {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                      "driver-btm-soc.c",0xd6c,"volt_increase_for_mode0",chain,custom_voltage._0_4_,
                      custom_voltage._4_4_,dVar2 + delta_volt);
            }
            fclose(pFVar1);
          }
          set_higher_voltage_by_chain(chain_00,dVar2 + delta_volt);
        }
        else {
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                      "driver-btm-soc.c",0xd67,"volt_increase_for_mode0",chain,custom_voltage._0_4_,
                      custom_voltage._4_4_,SUB84(upper_limit_volt,0));
            }
            fclose(pFVar1);
          }
          set_higher_voltage_by_chain(chain_00,upper_limit_volt);
        }
        slowly_set_iic_power_to_higher_voltage_by_chain(chain_00);
        increased_flag[chain] = true;
      }
      else {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,
                    "%s:%d:%s: chain[%d] voltage is high enough, no need to increase voltage\n",
                    "driver-btm-soc.c",0xd5a,"volt_increase_for_mode0",chain);
          }
          fclose(pFVar1);
        }
        *outer_reopen_flag = true;
      }
    }
  }
  return;
}


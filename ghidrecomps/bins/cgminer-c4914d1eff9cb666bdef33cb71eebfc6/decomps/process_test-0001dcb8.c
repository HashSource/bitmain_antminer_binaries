
/* WARNING: Unknown calling convention */

void process_test(void)

{
  _Bool _Var1;
  int fan_pwm;
  char *in_stack_ffffffa0;
  int in_stack_ffffffa4;
  uint32_t data;
  uint32_t testID;
  FILE *pFile;
  FILE *pFile_1;
  double custom_voltage;
  FILE *pFile_2;
  FILE *pFile_3;
  double custom_voltage_1;
  int core;
  int asic;
  int i;
  int chain;
  
  testID = 0;
  data = 0;
  read_test_ID(&testID,&data);
  clear_test_ID();
  if (testID != 0) {
    saveTestID(0);
    if (testID == 0x11) {
      dump_nonce_info_all_asic();
    }
    else if (testID == 0x12) {
      fan_pwm = get_reopen_pwm();
      re_open_core(fan_pwm);
      _slowly_set_iic_power_to_working_voltage();
    }
    else if (testID == 0x13) {
      custom_voltage = 0.0;
      _Var1 = is_T11();
      if (_Var1) {
        for (chain = 0; chain < 0x10; chain = chain + 1) {
          if (dev->chain_exist[chain] != 0) {
            custom_voltage = get_current_voltage_by_chain((uint8_t)chain);
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile = (FILE *)fopen(log_file,"a+");
              if (pFile != (FILE *)0x0) {
                in_stack_ffffffa0 = "process_test";
                in_stack_ffffffa4 = chain;
                fprintf((FILE *)pFile,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0x8af,"process_test",chain,custom_voltage._0_4_,
                        custom_voltage._4_4_,custom_voltage + DAT_0001e0a0);
              }
              fclose((FILE *)pFile);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain
                      ((uint8_t)chain,(double)CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
          }
        }
      }
      else {
        custom_voltage = get_current_voltage();
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_1 = (FILE *)fopen(log_file,"a+");
          if (pFile_1 != (FILE *)0x0) {
            in_stack_ffffffa0 = "process_test";
            fprintf((FILE *)pFile_1,"%s:%d:%s: voltage: %0.2f, now set to: %0.2f\n",
                    "driver-btm-soc.c",0x8b6);
          }
          fclose((FILE *)pFile_1);
        }
        slowly_set_iic_power_to_custom_voltage
                  ((double)CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
      }
    }
    else if (testID == 0x14) {
      custom_voltage_1 = 0.0;
      _Var1 = is_T11();
      if (_Var1) {
        for (chain = 0; chain < 0x10; chain = chain + 1) {
          if (dev->chain_exist[chain] != 0) {
            custom_voltage_1 = get_current_voltage_by_chain((uint8_t)chain);
            if (3 < log_level) {
              print_crt_time_to_file(log_file,3);
              pFile_2 = (FILE *)fopen(log_file,"a+");
              if (pFile_2 != (FILE *)0x0) {
                in_stack_ffffffa0 = "process_test";
                in_stack_ffffffa4 = chain;
                fprintf((FILE *)pFile_2,"%s:%d:%s: chain[%d] voltage: %0.2f, now set to: %0.2f\n",
                        "driver-btm-soc.c",0x8c4,"process_test",chain,custom_voltage_1._0_4_,
                        custom_voltage_1._4_4_,custom_voltage_1 - DAT_0001e0a0);
              }
              fclose((FILE *)pFile_2);
            }
            slowly_set_iic_power_to_custom_voltage_by_chain
                      ((uint8_t)chain,(double)CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
          }
        }
      }
      else {
        custom_voltage_1 = get_current_voltage();
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_3 = (FILE *)fopen(log_file,"a+");
          if (pFile_3 != (FILE *)0x0) {
            in_stack_ffffffa0 = "process_test";
            fprintf((FILE *)pFile_3,"%s:%d:%s: voltage: %0.2f, now set to: %0.2f\n",
                    "driver-btm-soc.c",0x8cb);
          }
          fclose((FILE *)pFile_3);
        }
        slowly_set_iic_power_to_custom_voltage
                  ((double)CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
      }
    }
    else if ((testID & 0xff000000) == 0xb2000000) {
      chain = testID >> 0x14 & 0xf;
      asic = testID >> 0xc & 0xff;
      core = testID & 0xff;
      if (core == 0xff) {
        core = 0xff;
        for (i = 0; i < 0xd0; i = i + 1) {
          do_dump_core_hash_clock_counter(chain,(uint8_t)asic,i);
        }
      }
      else {
        do_dump_core_hash_clock_counter(chain,(uint8_t)(testID >> 0xc),core);
      }
    }
  }
  return;
}



/* WARNING: Unknown calling convention */

void process_TEST(void)

{
  uint uVar1;
  FILE *pFVar2;
  char *in_stack_ffffffa8;
  undefined4 in_stack_ffffffac;
  char log_level_str [32];
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_4;
  FILE *fd;
  FILE *pFile_3;
  int testID;
  
  uVar1 = read_test_ID();
  if (uVar1 != 0) {
    save_test_ID(0);
    if (uVar1 == 0xb) {
      dump_nonce_info_all_core();
    }
    else if (uVar1 == 0xc) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffffa8 = "process_TEST";
          fprintf(pFVar2,"%s:%d:%s: current voltage = %f\n","driver-btm-soc.c",0xe5d);
        }
        fclose(pFVar2);
      }
      set_working_voltage((double)CONCAT44(in_stack_ffffffac,in_stack_ffffffa8));
      slowly_set_iic_power_to_working_voltage();
      process_TEST::lexical_block_0::voltage = process_TEST::lexical_block_0::voltage - DAT_00029088
      ;
    }
    else if (uVar1 == 0xd) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          in_stack_ffffffa8 = "process_TEST";
          fprintf(pFVar2,"%s:%d:%s: current voltage = %f\n","driver-btm-soc.c",0xe67);
        }
        fclose(pFVar2);
      }
      set_working_voltage((double)CONCAT44(in_stack_ffffffac,in_stack_ffffffa8));
      slowly_set_iic_power_to_working_voltage();
      process_TEST::lexical_block_1::voltage_1 =
           process_TEST::lexical_block_1::voltage_1 + DAT_00029088;
    }
    else if (uVar1 == 0xe) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: current pwm = %d\n","driver-btm-soc.c",0xe71,"process_TEST",
                  process_TEST::lexical_block_2::pwm);
        }
        fclose(pFVar2);
      }
      set_pwm((uchar)process_TEST::lexical_block_2::pwm);
      process_TEST::lexical_block_2::pwm = process_TEST::lexical_block_2::pwm + -3;
    }
    else if ((uVar1 != 0xf) && (uVar1 != 0x10)) {
      if (uVar1 == 0x11) {
        if (1 < log_level) {
          print_crt_time_to_file(log_file,1);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: try to set log level...\n","driver-btm-soc.c",0xe80,
                    "process_TEST");
          }
          fclose(pFVar2);
        }
        pFVar2 = fopen("/etc/config/log_level","rb");
        if (pFVar2 != (FILE *)0x0) {
          memset(log_level_str,0,0x20);
          fread(log_level_str,1,0x20,pFVar2);
          fclose(pFVar2);
          uVar1 = atoi(log_level_str);
          set_log_level(uVar1);
          if (1 < log_level) {
            print_crt_time_to_file(log_file,1);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: log level set to %d\n","driver-btm-soc.c",0xe8c,
                      "process_TEST",log_level);
            }
            fclose(pFVar2);
          }
        }
      }
      else if ((uVar1 != 0x12) && (uVar1 != 0x13)) {
        if (uVar1 == 0x14) {
          dump_all_asic_reg();
        }
        else if ((uVar1 & 0xff000000) == 0xa6000000) {
          dump_asic_reg(uVar1);
        }
        else if ((uVar1 & 0xff000000) == 0xa5000000) {
          dump_core_reg(uVar1);
        }
      }
    }
  }
  return;
}


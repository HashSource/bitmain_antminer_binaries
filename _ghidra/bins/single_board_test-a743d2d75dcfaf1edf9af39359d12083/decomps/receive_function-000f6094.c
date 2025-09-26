
void * receive_function(void *arg)

{
  uint32_t uVar1;
  int iVar2;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  return_nonce_128bit_t reg_buf;
  uint32_t nonce_number;
  uint32_t nonce_number_total;
  uint32_t i;
  
  nonce_number = 0;
  i = 0;
  nonce_number_total = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: BTC start %s\n","receive_function","receive_function");
  snprintf(tmp1,0x800,"BTC start %s","receive_function");
  log_to_file(tmp1,time_stamp);
  flush_nonce3_buffer();
  while (gStart_receive != false) {
    uVar1 = get_nonce_number_in_fifo();
    nonce_number = uVar1 >> 1;
    nonce_number_total = nonce_number + nonce_number_total;
    if (nonce_number != 0) {
      for (i = 0; i < nonce_number; i = i + 1) {
        get_return_nonce_128bit(reg_buf.buf);
        if ((reg_buf.buf[0]._3_1_ & 0x80) == 0) {
          BTC_check_register(&reg_buf);
        }
        else {
          iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1");
          if (((iVar2 == 0) ||
              (iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1+"), iVar2 == 0)) ||
             (iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1new"), iVar2 == 0)) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: pt1 do not need nonce, aisc no need return nonce\n","receive_function");
            builtin_strncpy(tmp1,"pt1 do not need nonce, aisc no need return nonce",0x30);
            tmp1[0x30] = '\0';
            log_to_file(tmp1,time_stamp);
          }
          if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
            if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
              if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s: Test_Method error\n","receive_function");
                builtin_strncpy(tmp1,"Test_Method erro",0x10);
                tmp1[0x10] = 'r';
                tmp1[0x11] = '\0';
                log_to_file(tmp1,time_stamp);
              }
              else {
                BTC_mid_auto_gen_check_nonce(&reg_buf);
              }
            }
            else if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
              BTC_super_software_pattern_check_nonce(&reg_buf);
            }
            else {
              BTC_cpugen_pattern_check_nonce(&reg_buf);
            }
          }
          else if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
            BTC_software_pattern_check_nonce(&reg_buf);
          }
          else {
            BTC_cpugen_pattern_check_nonce(&reg_buf);
          }
        }
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: BTC %s stop\n","receive_function","receive_function");
  snprintf(tmp1,0x800,"BTC %s stop","receive_function");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}


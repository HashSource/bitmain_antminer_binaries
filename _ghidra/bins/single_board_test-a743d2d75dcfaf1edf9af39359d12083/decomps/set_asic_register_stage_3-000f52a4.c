
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_asic_register_stage_3(void)

{
  uint8_t which_chain;
  uint32_t uVar1;
  char time_stamp [48];
  char tmp1 [2048];
  pll_userdivider_t user_divider;
  uint32_t Timeout_1;
  uint32_t Timeout;
  int temp_freq;
  int real_freq;
  int n;
  int i;
  
  set_chain_baud((uint8_t)gChain,(Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set chain baud as %d\n","set_asic_register_stage_3",
         (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  snprintf(tmp1,0x800,"Set chain baud as %d",
           (Local_Config_Information->Test_Info).Test_Speed.Baudrate);
  log_to_file(tmp1,time_stamp);
  usleep(5000);
  memset(&user_divider,0,4);
  set_chain_pllparameter_userdivider((uint8_t)gChain,'\0',user_divider);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x\n"
         ,"set_asic_register_stage_3",(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
         (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  snprintf(tmp1,0x800,
           "Set Pll0: userdivider0 = 0x%02x, userdivider1 = 0x%02x, userdivider2 = 0x%02x, userdivider3 = 0x%02x"
           ,(uint)user_divider & 0xff,(uint)user_divider >> 8 & 0xff,
           (uint)user_divider >> 0x10 & 0xff,(uint)user_divider >> 0x18);
  log_to_file(tmp1,time_stamp);
  usleep(10000);
  uVar1 = get_freq_comp((Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                        [gPattern_test_counter].Frequence);
  do_core_reset();
  usleep(1000000);
  if ((Local_Config_Information->Hash_Board).Smooth_Voltage == false) {
    time_stamp[0] = '\'';
    time_stamp[1] = '\0';
    time_stamp[2] = '\0';
    time_stamp[3] = '\0';
    time_stamp[4] = '*';
    time_stamp[5] = '\0';
    time_stamp[6] = '\0';
    time_stamp[7] = '\0';
    time_stamp[8] = '-';
    time_stamp[9] = '\0';
    time_stamp[10] = '\0';
    time_stamp[0xb] = '\0';
    time_stamp[0xc] = '0';
    time_stamp[0xd] = '\0';
    time_stamp[0xe] = '\0';
    time_stamp[0xf] = '\0';
    time_stamp[0x10] = '1';
    time_stamp[0x11] = '\0';
    time_stamp[0x12] = '\0';
    time_stamp[0x13] = '\0';
    time_stamp[0x14] = '2';
    time_stamp[0x15] = '\0';
    time_stamp[0x16] = '\0';
    time_stamp[0x17] = '\0';
    time_stamp[0x18] = '3';
    time_stamp[0x19] = '\0';
    time_stamp[0x1a] = '\0';
    time_stamp[0x1b] = '\0';
    time_stamp[0x1c] = '4';
    time_stamp[0x1d] = '\0';
    time_stamp[0x1e] = '\0';
    time_stamp[0x1f] = '\0';
    time_stamp[0x20] = '5';
    time_stamp[0x21] = '\0';
    time_stamp[0x22] = '\0';
    time_stamp[0x23] = '\0';
    time_stamp[0x24] = '6';
    time_stamp[0x25] = '\0';
    time_stamp[0x26] = '\0';
    time_stamp[0x27] = '\0';
    time_stamp[0x28] = '7';
    time_stamp[0x29] = '\0';
    time_stamp[0x2a] = '\0';
    time_stamp[0x2b] = '\0';
    time_stamp[0x2c] = '8';
    time_stamp[0x2d] = '\0';
    time_stamp[0x2e] = '\0';
    time_stamp[0x2f] = '\0';
    tmp1[0] = '2';
    tmp1[1] = '\0';
    tmp1[2] = '\0';
    tmp1[3] = '\0';
    tmp1[4] = -0x6a;
    tmp1[5] = '\0';
    tmp1[6] = '\0';
    tmp1[7] = '\0';
    tmp1[8] = -0x38;
    tmp1[9] = '\0';
    tmp1[10] = '\0';
    tmp1[0xb] = '\0';
    tmp1[0xc] = -6;
    tmp1[0xd] = '\0';
    tmp1[0xe] = '\0';
    tmp1[0xf] = '\0';
    tmp1[0x10] = '\x0e';
    tmp1[0x11] = '\x01';
    tmp1[0x12] = '\0';
    tmp1[0x13] = '\0';
    tmp1[0x14] = '\"';
    tmp1[0x15] = '\x01';
    tmp1[0x16] = '\0';
    tmp1[0x17] = '\0';
    tmp1[0x18] = '6';
    tmp1[0x19] = '\x01';
    tmp1[0x1a] = '\0';
    tmp1[0x1b] = '\0';
    tmp1[0x1c] = 'J';
    tmp1[0x1d] = '\x01';
    tmp1[0x1e] = '\0';
    tmp1[0x1f] = '\0';
    tmp1[0x20] = '^';
    tmp1[0x21] = '\x01';
    tmp1[0x22] = '\0';
    tmp1[0x23] = '\0';
    tmp1[0x24] = 'r';
    tmp1[0x25] = '\x01';
    tmp1[0x26] = '\0';
    tmp1[0x27] = '\0';
    tmp1[0x28] = -0x7a;
    tmp1[0x29] = '\x01';
    tmp1[0x2a] = '\0';
    tmp1[0x2b] = '\0';
    tmp1[0x2c] = -0x66;
    tmp1[0x2d] = '\x01';
    tmp1[0x2e] = '\0';
    tmp1[0x2f] = '\0';
    tmp1[0x30] = -0x52;
    tmp1[0x31] = '\x01';
    tmp1[0x32] = '\0';
    tmp1[0x33] = '\0';
    tmp1[0x34] = -0x3e;
    tmp1[0x35] = '\x01';
    tmp1[0x36] = '\0';
    tmp1[0x37] = '\0';
    n = 0;
    for (i = 0; (uint)i < 0xe; i = i + 1) {
      if ((int)uVar1 < *(int *)(tmp1 + i * 4)) {
        n = i + -1;
        break;
      }
    }
    for (i = 0; i < n; i = i + 1) {
      inc_freq_delay(*(int *)(tmp1 + i * 4),*(int *)(tmp1 + (i + 1) * 4),
                     *(int *)(time_stamp + i * 4));
    }
    if (*(uint32_t *)(tmp1 + n * 4) != uVar1) {
      inc_freq_with_fixed_step_parallel
                ((uint8_t)gChain,'\x01',0,
                 (uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel,
                 *(uint32_t *)(tmp1 + n * 4),uVar1,6.25);
      sleep(5);
    }
    gStart_read_temp_from_asic = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: use config smooth_voltage\n","set_asic_register_stage_3");
    builtin_strncpy(tmp1,"use config smooth_voltage",0x1a);
    log_to_file(tmp1,time_stamp);
    inc_freq_with_adjust_voltage
              ((uint8_t)gChain,(uint8_t)(Local_Config_Information->Test_Info).Asic_Register.Clk_Sel,
               0x32,(uint)(0.0 < (double)(longlong)(int)uVar1) *
                    (int)(longlong)(double)(longlong)(int)uVar1,6.25);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Set chain frequency as %d\n","set_asic_register_stage_3",uVar1);
  snprintf(tmp1,0x800,"Set chain frequency as %d",uVar1);
  log_to_file(tmp1,time_stamp);
  which_chain = (uint8_t)gChain;
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      set_chain_ticketmask(which_chain,0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set TM as 0x%08x\n","set_asic_register_stage_3",0);
      snprintf(tmp1,0x800,"Set TM as 0x%08x",0);
      log_to_file(tmp1,time_stamp);
    }
    else {
      set_chain_ticketmask(which_chain,0xffff);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set TM as 0x%08x\n","set_asic_register_stage_3",0xffff);
      snprintf(tmp1,0x800,"Set TM as 0x%08x",0xffff);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    set_chain_ticketmask(which_chain,0xffff);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set TM as 0x%08x\n","set_asic_register_stage_3",0xffff);
    snprintf(tmp1,0x800,"Set TM as 0x%08x",0xffff);
    log_to_file(tmp1,time_stamp);
    set_one_chip_ticketmask((uint8_t)gChain,0,0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: enable asic 0 to return nonce to ctrlboard to judge unique nonce\n",
           "set_asic_register_stage_3");
    memcpy(tmp1,"enable asic 0 to return nonce to ctrlboard to judge unique nonce",0x41);
    log_to_file(tmp1,time_stamp);
  }
  uart_flush_rx(gChain);
  if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
      uVar1 = __aeabi_uidiv(0x1ffff,uVar1);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set timeout by using value from freq: %d\n","set_asic_register_stage_3",uVar1);
      snprintf(tmp1,0x800,"Set timeout by using value from freq: %d",uVar1);
      log_to_file(tmp1,time_stamp);
      dhash_set_timeout(uVar1);
    }
    else {
      uVar1 = (Local_Config_Information->Test_Info).Test_Speed.Timeout;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set timeout by using config value: %d\n","set_asic_register_stage_3",
             (Local_Config_Information->Test_Info).Test_Speed.Timeout);
      snprintf(tmp1,0x800,"Set timeout by using config value: %d",
               (Local_Config_Information->Test_Info).Test_Speed.Timeout);
      log_to_file(tmp1,time_stamp);
      dhash_set_timeout(uVar1);
    }
  }
  else {
    dhash_set_timeout((Local_Config_Information->Test_Info).Test_Speed.Timeout);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Set timeout by using config value: %d\n","set_asic_register_stage_3",
           (Local_Config_Information->Test_Info).Test_Speed.Timeout);
    snprintf(tmp1,0x800,"Set timeout by using config value: %d",
             (Local_Config_Information->Test_Info).Test_Speed.Timeout);
    log_to_file(tmp1,time_stamp);
  }
  set_chain_core_nonce_overflow_control((uint8_t)gChain,false);
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != false) {
    set_chain_chip_nonce_offset((uint8_t)gChain,true,0);
  }
  return;
}


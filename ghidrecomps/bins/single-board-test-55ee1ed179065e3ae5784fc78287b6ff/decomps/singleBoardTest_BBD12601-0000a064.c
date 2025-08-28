
void singleBoardTest_BBD12601(void)

{
  char local_2c [16];
  int local_1c;
  uint local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  builtin_strncpy(local_2c,"                ",0x10);
  printf("\nBegin %s test\n","singleBoardTest_BBD12601");
  system("date");
  putchar(10);
  reset_global_arg();
  chain_reset(gChain);
  pthread_create((pthread_t *)(cgpu + 0x80008),(pthread_attr_t *)0x0,(__start_routine *)0xe135,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  chain_reset_low(gChain);
  usleep(300000);
  reset_PIC16F1704_pic(gChain,0);
  jump_from_loader_to_app_PIC16F1704(gChain,0);
  set_voltage(gChain,0,0);
  enable_PIC16F1704_dc_dc(gChain,0,1);
  pthread_create((pthread_t *)(cgpu + 0x8000c),(pthread_attr_t *)0x0,(__start_routine *)0x14089,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  usleep(100);
  chain_reset_high(gChain);
  usleep(300000);
  fan_control(0x32);
  set_baud(gChain,0x1a);
  *(undefined1 *)((int)&start_receive + (uint)gChain) = 1;
  pthread_create((pthread_t *)(cgpu + 0x80004),(pthread_attr_t *)0x0,(__start_routine *)0xebc5,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  usleep(5000);
  puts("\n--- BBD25601 check asic number");
  check_BM1722_asic_reg(gChain,0,0,1);
  printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
         (uint)(byte)cgpu[gChain + 0x1004b8]);
  if ((uint)(byte)cgpu[gChain + 0x1004b8] == Conf._108_4_) {
    chain_reset(gChain);
    uart_flush(gChain);
    uart_set_baud(gChain,0x1a);
    puts("\n--- double check asic number");
    check_BM1722_asic_reg(gChain,0,0,1);
    printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
           (uint)(byte)cgpu[gChain + 0x1004b8]);
    if ((uint)(byte)cgpu[gChain + 0x1004b8] == Conf._108_4_) {
      calculate_timeout_and_baud();
      set_baud(gChain,Conf._260_4_ & 0xff);
      set_BM1722_freq((float)(uint)Conf._68_4_,gChain,0,1);
      BM1722_set_address_all(gChain);
      if (Conf[0xfc] == '\x01') {
        if (pattern_test_time == 0) {
          get_temperature_offset_value_from_asic_chain(gChain);
          set_default_temperature_offset_value_chain(gChain);
        }
        else {
          set_default_temperature_offset_value_chain(gChain);
        }
      }
      pthread_create((pthread_t *)(cgpu + 0x80010),(pthread_attr_t *)0x0,(__start_routine *)0xf349,
                     (void *)((int)&chain_info + (uint)gChain * 2));
      set_BM1722_asic_register(gChain,0,0x14,1,0x26);
      BM1722_open_core(gChain);
      puts("\nBegin send test pattern");
      *(undefined1 *)((int)&gStartTest + (uint)gChain) = 1;
      while (*(char *)((int)&gStartTest + (uint)gChain) != '\x01') {
        if ((uint)Conf._216_4_ <= *(uint *)(time_counter + (uint)gChain * 4)) {
          pthread_cancel(cgpu._524304_4_);
          pthread_cancel(cgpu._524292_4_);
          pthread_cancel(cgpu._524296_4_);
          pthread_cancel(cgpu._524300_4_);
          puts("Can\'t open core, change to next voltage and freq");
          write_lcd(0,"Can\'t open core ",0x10);
          write_lcd_no_memset(1,"change    to    next",0x10);
          write_lcd_no_memset(2,"voltage and freq",0x10);
          pattern_test_time = pattern_test_time + 1;
          enable_PIC16F1704_dc_dc(gChain,0,0);
          return;
        }
        usleep(10000);
      }
      pthread_create((pthread_t *)(cgpu + 0x80000),(pthread_attr_t *)0x0,(__start_routine *)0xef59,
                     (void *)((int)&chain_info + (uint)gChain * 2));
      local_1c = pthread_join(cgpu._524288_4_,(void **)0x0);
      local_1c = pthread_join(cgpu._524292_4_,(void **)0x0);
      pthread_cancel(cgpu._524296_4_);
      pthread_cancel(cgpu._524304_4_);
      local_18 = single_board_get_result(gChain);
      single_board_print_lcd(local_18);
      if ((local_18 == 7) && (Conf[0xe0] != '\0')) {
        set_voltage(gChain,0,1);
      }
      if (((local_18 & 1) != 0) || (gHowManyVoltageLevel <= pattern_test_time)) {
        enable_PIC16F1704_dc_dc(gChain,0,0);
      }
      pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
      pthread_cancel(cgpu._524300_4_);
      pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
      fan_control(0);
    }
    else {
      pthread_cancel(cgpu._524292_4_);
      pthread_cancel(cgpu._524296_4_);
      pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
      pthread_cancel(cgpu._524300_4_);
      pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
      sprintf(local_2c + 7,"%d",(uint)(byte)cgpu[gChain + 0x1004b8]);
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,local_2c,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_BBD12601",
             (uint)(byte)cgpu[gChain + 0x1004b8]);
      sleep(Conf._264_4_);
      enable_PIC16F1704_dc_dc(gChain,0,0);
    }
  }
  else {
    pthread_cancel(cgpu._524292_4_);
    pthread_cancel(cgpu._524296_4_);
    pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
    pthread_cancel(cgpu._524300_4_);
    pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
    sprintf(local_2c + 7,"%d",(uint)(byte)cgpu[gChain + 0x1004b8]);
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,local_2c,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_BBD12601",
           (uint)(byte)cgpu[gChain + 0x1004b8]);
    sleep(Conf._264_4_);
    enable_PIC16F1704_dc_dc(gChain,0,0);
  }
  return;
}



void singleBoardTest_BBD25601(void)

{
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_2c = s______BBD25601_check_asic_number_000288cc._0_4_;
  uStack_28 = s______BBD25601_check_asic_number_000288cc._4_4_;
  uStack_24 = s______BBD25601_check_asic_number_000288cc._8_4_;
  uStack_20 = s______BBD25601_check_asic_number_000288cc._12_4_;
  printf("\nBegin %s test\n","singleBoardTest_BBD25601");
  system("date");
  putchar(10);
  reset_global_arg();
  chain_reset(gChain);
  pthread_create(DAT_0000bc2c,(pthread_attr_t *)0x0,show_status_func + 1,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  chain_reset_low(gChain);
  usleep(300000);
  power_init();
  reset_PIC16F1704_pic(gChain,gI2c);
  jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
  pthread_create(DAT_0000bc30,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  usleep(100);
  set_voltage(gChain,0xff,0);
  enable_PIC16F1704_dc_dc(gChain,gI2c,1);
  chain_reset_high(gChain);
  usleep(300000);
  fan_control(0x50);
  set_baud(gChain,0x1a);
  *(undefined *)((int)&start_receive + (uint)gChain) = 1;
  pthread_create(DAT_0000bc34,(pthread_attr_t *)0x0,receive_func + 1,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  usleep(5000);
  puts("\n--- BBD25601 check asic number");
  check_BM1725_asic_reg(gChain,0,0,1);
  printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
         (uint)(byte)cgpu[gChain + 0x1004b8]);
  if ((uint)(byte)cgpu[gChain + 0x1004b8] == Conf._108_4_) {
    chain_reset(gChain);
    uart_flush(gChain);
    uart_set_baud(gChain,0x1a);
    puts("\n--- double check asic number");
    check_BM1725_asic_reg(gChain,0,0,1);
    printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
           (uint)(byte)cgpu[gChain + 0x1004b8]);
    if ((uint)(byte)cgpu[gChain + 0x1004b8] == Conf._108_4_) {
      calculate_timeout_and_baud();
      set_baud(gChain,Conf._260_4_ & 0xff);
      set_BM1725_freq((float)(ulonglong)(uint)Conf._68_4_,gChain,0,1);
      BM1725_set_address_all(gChain);
      check_BM1725_asic_reg(gChain,0,0,1);
      if (Conf[252] == '\x01') {
        if (pattern_test_time == 0) {
          get_temperature_offset_value_from_asic_chain(gChain);
          set_default_temperature_offset_value_chain(gChain);
        }
        else {
          set_default_temperature_offset_value_chain(gChain);
        }
      }
      pthread_create(DAT_0000c20c,(pthread_attr_t *)0x0,read_temp_func + 1,
                     (void *)((int)&chain_info + (uint)gChain * 2));
      set_BM1725_asic_register(gChain,0,0x14,1,0x26);
      BM1725_open_core(gChain);
      puts("\nBegin send test pattern");
      while (*(char *)((int)&gStartTest + (uint)gChain) != '\x01') {
        if ((uint)Conf._216_4_ <= *(uint *)(time_counter + (uint)gChain * 4)) {
          pthread_cancel(cgpu._524304_4_);
          pthread_cancel(cgpu._524292_4_);
          pthread_cancel(cgpu._524296_4_);
          pthread_cancel(cgpu._524300_4_);
          puts("Can\'t open core, change to next voltage and freq");
          write_lcd(0,"Can\'t open core ",0x10);
          write_lcd_no_memset(1,"change  to  next",0x10);
          write_lcd_no_memset(2,"voltage and freq",0x10);
          pattern_test_time = pattern_test_time + 1;
          enable_PIC16F1704_dc_dc(gChain,gI2c,0);
          power_off();
          return;
        }
        usleep(10000);
      }
      pthread_create(DAT_0000c210,(pthread_attr_t *)0x0,send_func + 1,
                     (void *)((int)&chain_info + (uint)gChain * 2));
      local_1c = pthread_join(cgpu._524288_4_,(void **)0x0);
      local_1c = pthread_join(cgpu._524292_4_,(void **)0x0);
      pthread_cancel(cgpu._524296_4_);
      pthread_cancel(cgpu._524304_4_);
      local_18 = single_board_get_result(gChain);
      if ((local_18 == 7) &&
         (g_test_epprom = save_voltage_info_to_eeprom(Conf._68_4_,Conf._156_4_),
         g_test_epprom != '\x01')) {
        g_test_epprom = save_voltage_info_to_eeprom(Conf._68_4_,Conf._156_4_);
      }
      single_board_print_lcd(local_18);
      if (((local_18 & 1) != 0) || (gHowManyVoltageLevel <= pattern_test_time)) {
        enable_PIC16F1704_dc_dc(gChain,gI2c,0);
        power_off();
        fan_control(0);
        printf("power off %d\n",(uint)pattern_test_time);
      }
      pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
      pthread_cancel(cgpu._524300_4_);
      pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
    }
    else {
      pthread_cancel(cgpu._524292_4_);
      pthread_cancel(cgpu._524296_4_);
      pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
      pthread_cancel(cgpu._524300_4_);
      pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
      sprintf((char *)((int)&uStack_28 + 3),"%d",(uint)(byte)cgpu[gChain + 0x1004b8]);
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,&local_2c,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_BBD25601",
             (uint)(byte)cgpu[gChain + 0x1004b8]);
      sleep(Conf._264_4_);
      enable_PIC16F1704_dc_dc(gChain,gI2c,0);
      power_off();
    }
  }
  else {
    pthread_cancel(cgpu._524292_4_);
    pthread_cancel(cgpu._524296_4_);
    pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
    pthread_cancel(cgpu._524300_4_);
    pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
    sprintf((char *)((int)&uStack_28 + 3),"%d",(uint)(byte)cgpu[gChain + 0x1004b8]);
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,&local_2c,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_BBD25601",
           (uint)(byte)cgpu[gChain + 0x1004b8]);
    sleep(Conf._264_4_);
    enable_PIC16F1704_dc_dc(gChain,gI2c,0);
    power_off();
  }
  return;
}


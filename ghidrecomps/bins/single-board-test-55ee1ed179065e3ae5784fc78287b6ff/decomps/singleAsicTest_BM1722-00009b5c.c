
void singleAsicTest_BM1722(void)

{
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0x1e240;
  local_2c = s______BBD25601_check_asic_number_00028500._0_4_;
  uStack_28 = s______BBD25601_check_asic_number_00028500._4_4_;
  uStack_24 = s______BBD25601_check_asic_number_00028500._8_4_;
  uStack_20 = s______BBD25601_check_asic_number_00028500._12_4_;
  printf("\nBegin %s test\n","singleAsicTest_BM1722");
  system("date");
  putchar(10);
  reset_global_arg();
  chain_reset(gChain);
  fan_control(0x32);
  pthread_create(DAT_00009eb4,(pthread_attr_t *)0x0,show_status_func + 1,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  *(undefined *)((int)&start_receive + (uint)gChain) = 1;
  pthread_create(DAT_00009eb8,(pthread_attr_t *)0x0,receive_func + 1,
                 (void *)((int)&chain_info + (uint)gChain * 2));
  set_baud(gChain,0x1a);
  puts("\n--- check asic number");
  check_BM1722_asic_reg(gChain,0,0,1);
  printf("\n--- check chain: asicNum = %d\n",(uint)(byte)cgpu[gChain + 0x1004b8]);
  if ((uint)(byte)cgpu[gChain + 0x1004b8] == Conf._108_4_) {
    calculate_timeout_and_baud();
    set_baud(gChain,Conf._260_4_ & 0xff);
    set_BM1722_freq((float)(ulonglong)(uint)Conf._68_4_,gChain,0,1);
    BM1722_set_address_all(gChain);
    check_BM1722_asic_reg(gChain,0,0,1);
    if (Conf[252] == '\x01') {
      if (pattern_test_time == '\0') {
        get_temperature_offset_value_from_asic_chain(gChain);
        set_default_temperature_offset_value_chain(gChain);
      }
      else {
        set_default_temperature_offset_value_chain(gChain);
      }
    }
    pthread_create(DAT_00009ebc,(pthread_attr_t *)0x0,read_temp_func + 1,
                   (void *)((int)&chain_info + (uint)gChain * 2));
    set_BM1725_asic_register(gChain,0,0x14,1,0x26);
    BM1722_open_core(gChain);
    puts("\nBegin send test pattern");
    system("date");
    putchar(10);
    while (*(char *)((int)&gStartTest + (uint)gChain) != '\x01') {
      if ((uint)Conf._216_4_ <= *(uint *)(time_counter + (uint)gChain * 4)) {
        pthread_cancel(cgpu._524304_4_);
        pthread_cancel(cgpu._524292_4_);
        pthread_cancel(cgpu._524296_4_);
        puts("Can\'t open core, change to next voltage and freq");
        write_lcd(0,"Can\'t open core ",0x10);
        write_lcd_no_memset(1,"change  to  next",0x10);
        write_lcd_no_memset(2,"voltage and freq",0x10);
        pattern_test_time = pattern_test_time + '\x01';
        return;
      }
      usleep(10000);
    }
    pthread_create(DAT_0000a060,(pthread_attr_t *)0x0,send_func + 1,
                   (void *)((int)&chain_info + (uint)gChain * 2));
    local_1c = pthread_join(cgpu._524288_4_,(void **)0x0);
    local_1c = pthread_join(cgpu._524292_4_,(void **)0x0);
    pthread_cancel(cgpu._524296_4_);
    pthread_cancel(cgpu._524304_4_);
    local_18 = single_asic_get_result(gChain);
    single_asic_print_lcd(gChain,local_18);
    fan_control(0);
  }
  else {
    pthread_cancel(cgpu._524292_4_);
    pthread_cancel(cgpu._524296_4_);
    sprintf((char *)((int)&uStack_28 + 3),"%d",(uint)(byte)cgpu[gChain + 0x1004b8]);
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,&local_2c,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n%s: Only have %d ASIC\n","singleAsicTest_BM1722",(uint)(byte)cgpu[gChain + 0x1004b8]
          );
  }
  return;
}


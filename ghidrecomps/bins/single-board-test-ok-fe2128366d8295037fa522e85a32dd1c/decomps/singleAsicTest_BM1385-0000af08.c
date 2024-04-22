
void singleAsicTest_BM1385(void)

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
  local_2c = s__singleAsicTest_BM1385_00019d9c._0_4_;
  uStack_28 = s__singleAsicTest_BM1385_00019d9c._4_4_;
  uStack_24 = s__singleAsicTest_BM1385_00019d9c._8_4_;
  uStack_20 = s__singleAsicTest_BM1385_00019d9c._12_4_;
  printf("\nBegin %s test\n","singleAsicTest_BM1385");
  system("date");
  putchar(10);
  memset(lcd_buffer + 0x20,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_buffer + 0x20,0x40);
  }
  init_fpga();
  reset_single_BM1385_global_arg();
  check_chain();
  if (gChain == 0xff) {
    write_lcd(1,"  no hash board ",0x10);
    pthread_cancel(cgpu._65540_4_);
    pthread_cancel(cgpu._65544_4_);
    puts("\nNo hash board, please plug in it");
  }
  else {
    pthread_create(DAT_0000b30c,(pthread_attr_t *)0x0,single_BM1385_show_status_func + 1,
                   chain_info + (uint)gChain * 2);
    reset_hash_board();
    start_receive = 1;
    pthread_create(DAT_0000b310,(pthread_attr_t *)0x0,single_BM1385_receive_func + 1,
                   chain_info + (uint)gChain * 2);
    puts("\n--- check asic number");
    check_BM1385_asic_reg(gChain,0,0,1);
    printf("\n--- check chain: asicNum = %d\n",(uint)(byte)cgpu[gChain + 0x20338]);
    if ((uint)(byte)cgpu[gChain + 0x20338] == Conf._108_4_) {
      single_BM1385_calculate_timeout_and_baud();
      set_BM1385_freq(gChain,0,Conf._68_4_,1);
      single_BM1385_set_address(gChain);
      check_BM1385_asic_reg(gChain,0,0,1);
      single_BM1385_set_baud(gChain,Conf._256_4_ & 0xff);
      single_BM1385_open_core(gChain);
      puts("\nBegin send test pattern");
      system("date");
      putchar(10);
      gStartTest = 1;
      pthread_create(DAT_0000b314,(pthread_attr_t *)0x0,single_BM1385_send_func + 1,
                     chain_info + (uint)gChain * 2);
      local_1c = pthread_join(cgpu._65536_4_,(void **)0x0);
      local_1c = pthread_join(cgpu._65540_4_,(void **)0x0);
      pthread_cancel(cgpu._65544_4_);
      local_18 = single_BM1385_get_result(gChain);
      single_BM1385_print_lcd(gChain,local_18);
      set_fan_speed(0);
      usleep(500000);
    }
    else {
      pthread_cancel(cgpu._65540_4_);
      pthread_cancel(cgpu._65544_4_);
      sprintf((char *)((int)&uStack_28 + 3),"%d",(uint)(byte)cgpu[gChain + 0x20338]);
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,&local_2c,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n","singleAsicTest_BM1385",
             (uint)(byte)cgpu[gChain + 0x20338]);
      puts("----------------------------\n\n");
    }
  }
  return;
}


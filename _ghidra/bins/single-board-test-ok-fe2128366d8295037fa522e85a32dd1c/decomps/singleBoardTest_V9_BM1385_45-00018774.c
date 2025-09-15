
void singleBoardTest_V9_BM1385_45(void)

{
  char local_2c [16];
  int local_1c;
  uint local_18;
  undefined4 local_14;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0x1e240;
  builtin_strncpy(local_2c,"                ",0x10);
  printf("\nBegin %s test\n","singleBoardTest_V9_BM1385_45");
  system("date");
  putchar(10);
  memset(lcd_buffer + 0x20,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_buffer + 0x20,0x40);
  }
  init_fpga();
  set_fpga_baud(0x1a);
  reset_V9_global_arg();
  check_chain();
  if (gChain == 0xff) {
    pthread_cancel(cgpu._65540_4_);
    pthread_cancel(cgpu._65544_4_);
    usleep(500000);
    write_lcd(1," no hash board  ",0x10);
    puts("\nNo hash board, please plug in it");
  }
  else {
    pthread_create((pthread_t *)(cgpu + 0x10008),(pthread_attr_t *)0x0,(__start_routine *)0x17cc9,
                   chain_info + (uint)gChain * 2);
    reset_PIC16F1704_pic(gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704(gChain,gI2c);
    V9_set_voltage(gChain,gI2c,0);
    enable_PIC16F1704_dc_dc(gChain,gI2c,1);
    pthread_create((pthread_t *)(cgpu + 0x1000c),(pthread_attr_t *)0x0,(__start_routine *)0x11025,
                   chain_info + (uint)gChain * 2);
    reset_hash_board();
    start_receive = 1;
    pthread_create((pthread_t *)(cgpu + 0x10004),(pthread_attr_t *)0x0,(__start_routine *)0x18475,
                   chain_info + (uint)gChain * 2);
    puts("\n--- V9 check asic number");
    check_BM1385_asic_reg(gChain,0,0,1);
    printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
           (uint)(byte)cgpu[gChain + 0x20338]);
    if ((uint)(byte)cgpu[gChain + 0x20338] == Conf._108_4_) {
      V9_set_baud(gChain,1);
      reset_hash_board(gChain);
      set_fpga_baud(0x1a);
      cgpu[gChain + 0x20338] = 0;
      puts("\n--- double check asic number");
      check_BM1385_asic_reg(gChain,0,0,1);
      printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,
             (uint)(byte)cgpu[gChain + 0x20338]);
      if ((uint)(byte)cgpu[gChain + 0x20338] == Conf._108_4_) {
        V9_calculate_timeout_and_baud();
        set_BM1385_freq(gChain,0,Conf._68_4_,1);
        V9_set_address(gChain);
        V9_set_baud(gChain,Conf._256_4_ & 0xff);
        V9_open_core(gChain);
        puts("\nBegin send test pattern");
        while (gStartTest != '\x01') {
          if ((uint)Conf._228_4_ <= time_counter) {
            pthread_cancel(cgpu._65540_4_);
            pthread_cancel(cgpu._65544_4_);
            pthread_cancel(cgpu._65548_4_);
            puts("Can\'t open core, change to next voltage and freq");
            write_lcd(0,"Can\'t open core ",0x10);
            write_lcd_no_memset(1,"change  to  next",0x10);
            write_lcd_no_memset(2,"voltage and freq",0x10);
            pattern_test_time = pattern_test_time + 1;
            return;
          }
          usleep(10000);
        }
        pthread_create((pthread_t *)(cgpu + 0x10000),(pthread_attr_t *)0x0,
                       (__start_routine *)0x181b5,chain_info + (uint)gChain * 2);
        local_1c = pthread_join(cgpu._65536_4_,(void **)0x0);
        pthread_cancel(cgpu._65544_4_);
        local_1c = pthread_join(cgpu._65540_4_,(void **)0x0);
        local_18 = V9_get_result(gChain);
        V9_print_lcd(local_18);
        if ((local_18 == 7) && (Conf[0xec] != '\0')) {
          V9_set_voltage(gChain,gI2c,1);
        }
        if (((local_18 & 1) != 0) || (gHowManyVoltageLevel <= pattern_test_time)) {
          enable_PIC16F1704_dc_dc(gChain,gI2c,0);
        }
        pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(cgpu._65548_4_);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        set_fan_speed(0);
        usleep(500000);
      }
      else {
        enable_PIC16F1704_dc_dc(gChain,gI2c,0);
        pthread_cancel(cgpu._65540_4_);
        pthread_cancel(cgpu._65544_4_);
        pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(cgpu._65548_4_);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        sprintf(local_2c + 7,"%d",(uint)(byte)cgpu[gChain + 0x20338]);
        write_lcd(0,"   Only have    ",0x10);
        write_lcd_no_memset(1,local_2c,0x10);
        write_lcd_no_memset(2,"      ASIC      ",0x10);
        printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_V9_BM1385_45",
               (uint)(byte)cgpu[gChain + 0x20338]);
        puts("----------------------------\n\n");
      }
    }
    else {
      enable_PIC16F1704_dc_dc(gChain,gI2c,0);
      pthread_cancel(cgpu._65540_4_);
      pthread_cancel(cgpu._65544_4_);
      pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
      pthread_cancel(cgpu._65548_4_);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      sprintf(local_2c + 7,"%d",(uint)(byte)cgpu[gChain + 0x20338]);
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,local_2c,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n","singleBoardTest_V9_BM1385_45",
             (uint)(byte)cgpu[gChain + 0x20338]);
      puts("----------------------------\n\n");
    }
  }
  return;
}


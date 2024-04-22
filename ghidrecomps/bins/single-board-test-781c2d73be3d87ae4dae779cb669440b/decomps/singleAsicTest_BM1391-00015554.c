
/* WARNING: Unknown calling convention */

void singleAsicTest_BM1391(void)

{
  pthread_t *ppVar1;
  uint uVar2;
  int iVar3;
  char lcd_display_buf [16];
  
  lcd_display_buf._8_4_ = DAT_00015870[2];
  lcd_display_buf._12_4_ = DAT_00015870[3];
  lcd_display_buf._0_4_ = *DAT_00015870;
  lcd_display_buf._4_4_ = DAT_00015870[1];
  printf("\nBegin %s test\n",DAT_00015870 + 4);
  system("date");
  putchar(10);
  memset(lcd_output,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_output,0x40);
  }
  init_fpga();
  write_axi_fpga(0x3e,0);
  usleep(100000);
  uVar2 = read_axi_fpga(0);
  write_axi_fpga(0,uVar2 | 0x40000000);
  reset_single_BM1391_global_arg();
  check_chain();
  ppVar1 = DAT_00015874;
  if (gChain == 0xff) {
    puts("\nNo hash board, please plug in it");
    write_lcd(1," no hash board  ",0x10);
    return;
  }
  iVar3 = pthread_create(DAT_00015874,(pthread_attr_t *)0x0,single_BM1391_show_status_func + 1,
                         chain_info + gChain);
  if (iVar3 == 0) {
    reset_hash_board();
    start_receive = true;
    iVar3 = pthread_create(ppVar1 + -1,(pthread_attr_t *)0x0,single_BM1391_receive_func + 1,
                           chain_info + gChain);
    if (iVar3 != 0) {
      pthread_cancel(ppVar1[-1]);
      pthread_cancel(*ppVar1);
      write_lcd(0,"  Creat receive ",0x10);
      write_lcd_no_memset(1,"   thread fail  ",0x10);
      write_lcd_no_memset(3,"   test again   ",0x10);
      printf("\n!!!%s: create single_BM1391_receive_func fail\n\n\n",DAT_00015878);
      return;
    }
    uVar2 = read_axi_fpga(0x40);
    write_axi_fpga(0x40,uVar2 & 0xffff7e1f | 0x8100);
    puts("\n--- check asic number");
    check_BM1391_asic_reg(gChain,'\0','\0',true);
    printf("\n--- check chain: asicNum = %d\n",
           (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    if (*(char *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) != '\x01') {
      pthread_cancel(ppVar1[-1]);
      pthread_cancel(*ppVar1);
      sprintf(lcd_display_buf + 7,"%d",
              (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
      write_lcd(0,"   Only have    ",0x10);
      write_lcd_no_memset(1,lcd_display_buf,0x10);
      write_lcd_no_memset(2,"      ASIC      ",0x10);
      printf("\n\n---%s: Only have %d ASIC\n",DAT_00015878,
             (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
      puts("----------------------------\n\n");
      return;
    }
    single_BM1391_calculate_timeout_and_baud();
    set_BM1391_freq(gChain,'\0',Conf.Freq,true);
    BM1391_software_set_address(gChain);
    BM1391_set_baud(gChain,(uchar)Conf.baud);
    check_BM1391_asic_reg(gChain,'\0','\x18',true);
    write_axi_fpga(0x22,Conf.timeout | 0x80000000);
    if (Conf.sensor_model - 1 < 2) {
      if (pattern_test_time == '\0') {
        BM1391_soft_reset_sensor(gChain);
        BM1391_enable_extended_mode_of_temperature_sensor(gChain);
        BM1391_get_temperature_offset_value_from_asic(gChain);
        BM1391_set_default_temperature_offset_value(gChain);
      }
      else {
        BM1391_enable_extended_mode_of_temperature_sensor(gChain);
        BM1391_set_default_temperature_offset_value(gChain);
      }
    }
    else {
      if (6 < Conf.sensor_model - 3) {
        pthread_cancel(ppVar1[-1]);
        pthread_cancel(*ppVar1);
        write_lcd(0,"Sensor Model Err",0x10);
        printf("\n%s: please config sensor_model in Config.ini\n",DAT_00015878);
        return;
      }
      BM1391_enable_extended_mode_of_temperature_sensor(gChain);
    }
    gIsReadTemp = true;
    if (Conf.AsicType == 0x3657) {
      single_BM1391P_open_core(gChain);
    }
    else {
      if (Conf.AsicType != 0x3658) {
        pthread_cancel(DAT_000159d0[1]);
        pthread_cancel(*ppVar1);
        write_lcd(1," Asic Type Err  ",0x10);
        printf("\n!!! %s: Conf.AsicType = %d, error\n",DAT_000159d4,Conf.AsicType);
        return;
      }
      single_BM1391S_open_core(gChain);
    }
    ppVar1 = DAT_000159d0;
    puts("\nBegin send test pattern");
    putchar(10);
    iVar3 = pthread_create(ppVar1,(pthread_attr_t *)0x0,single_BM1391_send_func + 1,
                           chain_info + gChain);
    if (iVar3 == 0) {
      pthread_join(*ppVar1,(void **)0x0);
      pthread_join(ppVar1[1],(void **)0x0);
      pthread_cancel(ppVar1[2]);
      uVar2 = single_BM1391_get_result(gChain);
      single_BM1391_print_lcd(gChain,uVar2);
      set_fan_speed(0);
      usleep(500000);
    }
    else {
      pthread_cancel(*ppVar1);
      pthread_cancel(ppVar1[1]);
      pthread_cancel(ppVar1[2]);
      write_lcd(0,"   Creat send   ",0x10);
      write_lcd_no_memset(1,"   thread fail  ",0x10);
      write_lcd_no_memset(3,"   test again   ",0x10);
      printf("\n!!!%s: create single_BM1391_send_func fail\n\n\n",DAT_000159d4);
    }
  }
  else {
    pthread_cancel(*ppVar1);
    write_lcd(0,"   Creat show   ",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create single_BM1391_show_status_func fail\n\n\n",DAT_00015878);
  }
  return;
}


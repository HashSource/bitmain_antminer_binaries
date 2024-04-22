
/* WARNING: Unknown calling convention */

void singleBoardTest_V9_BM1385_45(void)

{
  pthread_t *ppVar1;
  int iVar2;
  pthread_t *ppVar3;
  uint uVar4;
  char lcd_display_buf [16];
  
  lcd_display_buf._8_4_ = DAT_0001a700[2];
  lcd_display_buf._12_4_ = DAT_0001a700[3];
  lcd_display_buf._0_4_ = *DAT_0001a700;
  lcd_display_buf._4_4_ = DAT_0001a700[1];
  printf("\nBegin %s test\n",DAT_0001a700 + 4);
  system("date");
  putchar(10);
  memset(lcd_output,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_output,0x40);
  }
  init_fpga();
  set_fpga_baud('\x1a');
  uVar4 = read_axi_fpga(0);
  write_axi_fpga(0,uVar4 | 0x20000000);
  reset_V9_global_arg();
  check_chain();
  iVar2 = DAT_0001a70c;
  ppVar1 = DAT_0001a704;
  if (gChain == 0xff) {
    pthread_cancel(*(pthread_t *)(DAT_0001a70c + 4));
    pthread_cancel(*(pthread_t *)(iVar2 + 8));
    usleep(500000);
    write_lcd(1," no hash board  ",0x10);
    puts("\nNo hash board, please plug in it");
    return;
  }
  pthread_create(DAT_0001a704,(pthread_attr_t *)0x0,V9_show_status_func + 1,chain_info + gChain);
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  reset_PIC16F1704_pic((uint)gChain,gI2c);
  jump_from_loader_to_app_PIC16F1704((uint)gChain,gI2c);
  V9_set_voltage(gChain,gI2c,false);
  enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\x01');
  pthread_create(ppVar1 + 1,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,chain_info + gChain);
  usleep(300000);
  write_axi_fpga(0xd,0);
  usleep(300000);
  start_receive = true;
  pthread_create(ppVar1 + -1,(pthread_attr_t *)0x0,V9_receive_func + 1,chain_info + gChain);
  puts("\n--- V9 check asic number");
  check_BM1385_asic_reg(gChain,'\0','\0',true);
  printf("\n--- check chain: J%d has asicNum = %d\n",(uint)gChain,
         (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
  if (*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) != Conf.AsicNum)
  {
    pthread_cancel(ppVar1[-1]);
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(ppVar1[1]);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",
            (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n",DAT_0001a708,
           (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    puts("----------------------------\n\n");
    sleep(Conf.close_power_delay);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\0');
    return;
  }
  V9_set_baud(gChain,'\x01');
  reset_hash_board();
  set_fpga_baud('\x1a');
  *(undefined *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) = 0;
  puts("\n--- double check asic number");
  check_BM1385_asic_reg(gChain,'\0','\0',true);
  printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,
         (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
  if (*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) != Conf.AsicNum)
  {
    pthread_cancel(ppVar1[-1]);
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(ppVar1[1]);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",
            (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n",DAT_0001a9a8,
           (uint)*(byte *)((int)ppVar1 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    puts("----------------------------\n\n");
    sleep(Conf.close_power_delay);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\0');
    return;
  }
  V9_calculate_timeout_and_baud();
  set_BM1385_freq(gChain,'\0',Conf.Freq,true);
  V9_set_address(gChain);
  V9_set_baud(gChain,(uchar)Conf.baud);
  V9_open_core(gChain);
  puts("\nBegin send test pattern");
  if (gStartTest == false) {
    if (time_counter < Conf.HeatingUpTime) {
      do {
        usleep(10000);
        if (gStartTest != false) goto LAB_0001a89a;
      } while (time_counter < Conf.HeatingUpTime);
    }
    ppVar3 = DAT_0001a9ac;
    pthread_cancel(DAT_0001a9ac[1]);
    pthread_cancel(*ppVar1);
    pthread_cancel(ppVar3[3]);
    puts("Can\'t open core, change to next voltage and freq");
    write_lcd(0,"Can\'t open core ",0x10);
    write_lcd_no_memset(1,"change  to  next",0x10);
    write_lcd_no_memset(2,"voltage and freq",0x10);
    pattern_test_time = pattern_test_time + '\x01';
    return;
  }
LAB_0001a89a:
  ppVar1 = DAT_0001a9ac;
  pthread_create(DAT_0001a9ac,(pthread_attr_t *)0x0,V9_send_func + 1,chain_info + gChain);
  pthread_join(*ppVar1,(void **)0x0);
  pthread_cancel(ppVar1[2]);
  pthread_join(ppVar1[1],(void **)0x0);
  uVar4 = V9_get_result(gChain);
  V9_print_lcd(uVar4);
  if (uVar4 == 7) {
    if (Conf.add_voltage_after_test_ok != 0) {
      V9_set_voltage(gChain,gI2c,true);
    }
  }
  else if (((uVar4 & 1) == 0) && (pattern_test_time < gHowManyVoltageLevel)) goto LAB_0001a902;
  enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\0');
LAB_0001a902:
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  pthread_cancel(ppVar1[3]);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  set_fan_speed(0);
  usleep(500000);
  return;
}


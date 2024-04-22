
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void singleBoardTest_BHB07601_BM1397(void)

{
  byte bVar1;
  pthread_t *ppVar2;
  pthread_t *ppVar3;
  uchar uVar4;
  _Bool _Var5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char lcd_display_buf [16];
  
  lcd_display_buf[4] = ' ';
  lcd_display_buf[5] = ' ';
  lcd_display_buf[6] = ' ';
  lcd_display_buf[7] = ' ';
  lcd_display_buf[0] = ' ';
  lcd_display_buf[1] = ' ';
  lcd_display_buf[2] = ' ';
  lcd_display_buf[3] = ' ';
  lcd_display_buf[8] = ' ';
  lcd_display_buf[9] = ' ';
  lcd_display_buf[10] = ' ';
  lcd_display_buf[11] = ' ';
  lcd_display_buf[12] = ' ';
  lcd_display_buf[13] = ' ';
  lcd_display_buf[14] = ' ';
  lcd_display_buf[15] = ' ';
  printf("\nBegin %s test\n",DAT_00021310);
  system("date");
  putchar(10);
  memset(lcd_output,0x20,0x40);
  if (0 < lcd_fd) {
    lseek(lcd_fd,0,0);
    write(lcd_fd,lcd_output,0x40);
  }
  init_fpga();
  set_fpga_baud('\x1a');
  write_axi_fpga(0x3e,0);
  uVar6 = read_axi_fpga(0);
  printf("FPGA version 0x%04x\n",uVar6 & 0xffff);
  uVar6 = read_axi_fpga(0);
  write_axi_fpga(0,uVar6 | 0x40000000);
  reset_BHB07601_global_arg();
  check_chain();
  ppVar2 = DAT_00021314;
  if (gChain == 0xff) {
    write_lcd(1," no hash board  ",0x10);
    puts("\nNo hash board, please plug in it");
    return;
  }
  iVar7 = pthread_create(DAT_00021314,(pthread_attr_t *)0x0,BHB07601_show_status_func + 1,
                         chain_info + gChain);
  if (iVar7 != 0) {
    pthread_cancel(*ppVar2);
    write_lcd(0,"   Creat show   ",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create single_BM1397_show_status_func fail\n\n\n",DAT_00021310);
    return;
  }
  gEEPROM_error = false;
  pthread_mutex_init((pthread_mutex_t *)&i2c_mutex,(pthread_mutexattr_t *)0x0);
  if (ppVar2[0x200c9] == 0) {
    uVar4 = Test_EEPROM();
    if (uVar4 == '\0') {
      printf("\n--- %s: Test_EEPROM: Check EEPROM ok!!!\n",DAT_00021684);
    }
    else {
      printf("\n!!! %s: Test_EEPROM: Check EEPROM error!!!\n\n",DAT_00021310);
      gEEPROM_error = true;
    }
  }
  else {
    uVar4 = Test_EEPROM_part_area();
    if (uVar4 == '\0') {
      printf("\n--- %s: Test_EEPROM_part_area: Check EEPROM ok!!!\n",DAT_00021684);
    }
    else {
      printf("\n!!! %s: Test_EEPROM_part_area: Check EEPROM error!!!\n\n",DAT_00021310);
      gEEPROM_error = true;
    }
  }
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  reset_dsPIC33EP16GS202_pic((uint)gChain,gI2c);
  jump_from_loader_to_app_dsPIC33EP16GS202((uint)gChain,gI2c);
  iVar7 = pthread_create(DAT_00021318,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                         chain_info + gChain);
  if (iVar7 != 0) {
    pthread_cancel(*ppVar2);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(DAT_0002131c + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    write_lcd(0,"Creat heart beat",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create pic_heart_beat_func fail\n\n\n",DAT_00021310);
    return;
  }
  usleep(300000);
  iVar7 = set_pre_open_core_voltage(gChain,gI2c);
  if (iVar7 != 0) {
    return;
  }
  start_receive = true;
  usleep(10000);
  iVar8 = pthread_create(DAT_0002167c,(pthread_attr_t *)0x0,BHB07601_receive_func + 1,
                         chain_info + gChain);
  iVar7 = DAT_00021680;
  if (iVar8 != 0) {
    pthread_cancel(*ppVar2);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar7 + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar7 + 4));
    write_lcd(0,"  Creat receive ",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create BHB07601_receive_func fail\n\n\n",DAT_00021684);
    return;
  }
  uVar6 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar6 & 0xffff7e1f | 0x8100);
  BM1397_set_clock_order(gChain,'\0',true);
  puts("\n--- BHB07601 check asic number");
  check_BM1397_asic_reg(gChain,'\0','\0',true);
  printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,
         (uint)*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
  iVar7 = DAT_00021680;
  if (*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) ==
      BHB07601_ASIC_NUMBER) {
    set_fpga_baud('\x1a');
    *(undefined *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) = 0;
    puts("\n--- double check asic number");
    check_BM1397_asic_reg(gChain,'\0','\0',true);
    printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,
           (uint)*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    iVar8 = DAT_00021688;
    iVar7 = DAT_00021680;
    if (*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0) ==
        BHB07601_ASIC_NUMBER) {
      if (*(char *)(DAT_00021688 + 800) == '\0') {
        BHB07601_calculate_timeout_and_baud();
        set_BM1397_freq_slowly(gChain,'\0',Conf.Freq,true);
        BHB07601_set_address(gChain);
        BHB07601_set_baud(gChain,*(uchar *)(iVar8 + 0x321));
        BM1397_set_TM(gChain,'\0',0x3f,true);
        write_axi_fpga(0x22,Conf.timeout | 0x80000000);
        usleep(10000);
        BM1397_set_core_clock_delay_all(gChain,'\0',(uchar)Conf.CoreClockDelay,'\x01');
        BM1397_soft_reset_sensor(gChain);
        BM1397_enable_extended_mode_of_temperature_sensor(gChain);
        iVar7 = 0;
        do {
          uVar6 = (uint)gChain;
          iVar8 = iVar7 + 1;
          if ((((gSensor_OK[uVar6][0] != false) && (gSensor_OK[uVar6][1] != false)) &&
              (gSensor_OK[uVar6][2] != false)) && (gSensor_OK[uVar6][3] != false)) {
            printf("\n---%s: check sensor ok\n",DAT_00021990,iVar7);
            break;
          }
          printf("\n---%s: check sensor %d time\n",DAT_00021990,iVar7);
          BM1397_read_asic_temperature_local(gChain);
          iVar7 = iVar8;
        } while (iVar8 != 3);
        gIsReadTemp = true;
        BHB07601_open_core(gChain);
        adjust_voltage(gChain,gI2c);
        puts("\nBegin send test pattern");
        if (gStartTest == false) {
          if (time_counter < Conf.HeatingUpTime) {
            do {
              usleep(10000);
              if (gStartTest != false) goto LAB_000217bc;
            } while (time_counter < Conf.HeatingUpTime);
          }
          ppVar3 = DAT_00021994;
          pthread_cancel(DAT_00021994[1]);
          pthread_cancel(*ppVar2);
          pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(ppVar3[3]);
          pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
          puts("Can\'t open core, change to next voltage and freq");
          write_lcd(0,"Can\'t open core ",0x10);
          write_lcd_no_memset(1,"change  to  next",0x10);
          write_lcd_no_memset(2,"voltage and freq",0x10);
          pattern_test_time = pattern_test_time + '\x01';
          enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
          power_off();
          return;
        }
LAB_000217bc:
        ppVar2 = DAT_00021994;
        iVar7 = pthread_create(DAT_00021994,(pthread_attr_t *)0x0,BHB07601_send_func + 1,
                               chain_info + gChain);
        if (iVar7 != 0) {
          pthread_cancel(ppVar2[2]);
          pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(ppVar2[3]);
          pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(ppVar2[1]);
          write_lcd(0,"   Creat send   ",0x10);
          write_lcd_no_memset(1,"   thread fail  ",0x10);
          write_lcd_no_memset(3,"   test again   ",0x10);
          printf("\n!!!%s: create BHB07601_send_func fail\n\n\n",DAT_00021990);
          enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
          power_off();
          return;
        }
        pthread_join(*ppVar2,(void **)0x0);
        pthread_join(ppVar2[1],(void **)0x0);
        pthread_cancel(ppVar2[2]);
        uVar6 = BHB07601_get_result(gChain);
        if ((int)(uVar6 << 0x1f) < 0) {
          if (gEEPROM_error == false) {
            _Var5 = BHB07601_AT24C02_write_total_data(gI2c,gChain);
            if (_Var5) {
              puts("\nEEPROM OK\n");
            }
            else {
              puts("\nEEPROM NG\n");
            }
          }
          else {
            printf("\n!!!%s: Don\'t save data into EEPROM, because EEPROM test fail!!\n\n",
                   DAT_00021990);
          }
        }
        BHB07601_print_lcd(uVar6);
        sleep(Conf.close_power_delay);
        power_off();
        sleep(0x1e);
        pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(ppVar2[3]);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        set_fan_speed(0);
        usleep(500000);
        return;
      }
      pthread_cancel(*(pthread_t *)(DAT_00021688 + -0x7fffc));
      pthread_cancel(*ppVar2);
      pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
      pthread_cancel(*(pthread_t *)(iVar8 + -0x7fff4));
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      write_lcd(1," find all ASIC  ",0x10);
      write_lcd_no_memset(2,"       OK       ",0x10);
      printf("\nFind %d ASIC, OK\n",BHB07601_ASIC_NUMBER);
      goto LAB_0002147c;
    }
    pthread_cancel(*(pthread_t *)(DAT_00021680 + 4));
    pthread_cancel(*ppVar2);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar7 + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",
            (uint)*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    bVar1 = *(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0);
  }
  else {
    pthread_cancel(*(pthread_t *)(DAT_00021680 + 4));
    pthread_cancel(*ppVar2);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar7 + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",
            (uint)*(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0));
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    bVar1 = *(byte *)((int)ppVar2 + (int)gAsic_Core_Nonce_Num[0][0x4f] + gChain + 0x4c0);
  }
  printf("\n\n---%s: Only have %d ASIC\n",DAT_00021684,(uint)bVar1);
  puts("----------------------------\n\n");
LAB_0002147c:
  sleep(Conf.close_power_delay);
  enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
  power_off();
  return;
}


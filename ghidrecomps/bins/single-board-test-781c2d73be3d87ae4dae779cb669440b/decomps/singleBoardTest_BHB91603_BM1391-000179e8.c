
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void singleBoardTest_BHB91603_BM1391(void)

{
  pthread_t *ppVar1;
  pthread_t *ppVar2;
  uchar uVar3;
  _Bool _Var4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char lcd_display_buf [16];
  
  lcd_display_buf._8_4_ = DAT_00017d18[2];
  lcd_display_buf._12_4_ = DAT_00017d18[3];
  lcd_display_buf._0_4_ = *DAT_00017d18;
  lcd_display_buf._4_4_ = DAT_00017d18[1];
  printf("\nBegin %s test\n",DAT_00017d18 + 4);
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
  uVar5 = read_axi_fpga(0);
  write_axi_fpga(0,uVar5 | 0x40000000);
  reset_BHB91603_global_arg();
  check_chain();
  ppVar1 = DAT_00017d1c;
  if (gChain == 0xff) {
    write_lcd(1," no hash board  ",0x10);
    puts("\nNo hash board, please plug in it");
    return;
  }
  iVar6 = pthread_create(DAT_00017d1c,(pthread_attr_t *)0x0,BHB91603_show_status_func + 1,
                         chain_info + gChain);
  if (iVar6 != 0) {
    pthread_cancel(*ppVar1);
    write_lcd(0,"   Creat show   ",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create single_BM1391_show_status_func fail\n\n\n",DAT_00017d20);
    return;
  }
  gEEPROM_error = false;
  pthread_mutex_init((pthread_mutex_t *)&i2c_mutex,(pthread_mutexattr_t *)0x0);
  uVar3 = Test_EEPROM_part_area();
  if (uVar3 == '\0') {
    printf("\n--- %s: Check EEPROM ok!!!\n",DAT_00017d20);
  }
  else {
    printf("\n!!! %s: Check EEPROM error!!!\n\n",DAT_00017d20);
    gEEPROM_error = true;
  }
  write_axi_fpga(0xd,0xffff);
  usleep(300000);
  reset_dsPIC33EP16GS202_pic((uint)gChain,gI2c);
  jump_from_loader_to_app_dsPIC33EP16GS202((uint)gChain,gI2c);
  iVar6 = pthread_create(DAT_00017d24,(pthread_attr_t *)0x0,pic_heart_beat_func + 1,
                         chain_info + gChain);
  if (iVar6 != 0) {
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(DAT_00017d28 + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    write_lcd(0,"Creat heart beat",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create pic_heart_beat_func fail\n\n\n",DAT_00017d20);
    return;
  }
  usleep(300000);
  iVar6 = set_pre_open_core_voltage(gChain,gI2c);
  if (iVar6 != 0) {
    return;
  }
  enable_dsPIC33EP16GS202_clamping_voltage((uint)gChain,gI2c,'\0');
  write_axi_fpga(0xd,0);
  usleep(300000);
  start_receive = true;
  usleep(10000);
  iVar7 = pthread_create(DAT_00017d2c,(pthread_attr_t *)0x0,BHB91603_receive_func + 1,
                         chain_info + gChain);
  iVar6 = DAT_000180ac;
  if (iVar7 != 0) {
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar6 + 0xc));
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(*(pthread_t *)(iVar6 + 4));
    write_lcd(0,"  Creat receive ",0x10);
    write_lcd_no_memset(1,"   thread fail  ",0x10);
    write_lcd_no_memset(3,"   test again   ",0x10);
    printf("\n!!!%s: create BHB91603_receive_func fail\n\n\n",DAT_000180b0);
    return;
  }
  uVar5 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar5 & 0xffff7e1f | 0x8100);
  printf("\n---%s: Conf.OpenCoreNum1 = %d, Conf.OpenCoreNum2 = %d\n",DAT_00017d20,Conf.OpenCoreNum1,
         Conf.OpenCoreNum2);
  if (Conf.OpenCoreNum1 != 0) {
    uVar5 = 0;
    do {
      iVar6 = DAT_000180ac;
      if (gHashBoard_BHB91603P == false) {
        if (gHashBoard_BHB91603S == false) {
          pthread_cancel(*ppVar1);
          pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(*(pthread_t *)(iVar6 + 0xc));
          pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(*(pthread_t *)(iVar6 + 4));
          write_lcd(0,"     Config     ",0x10);
          goto LAB_00017efc;
        }
        BHB91603_S_pre_open_core(gChain);
        usleep(500000);
      }
      else {
        BHB91603_P_pre_open_core(gChain);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < Conf.OpenCoreNum1);
  }
  puts("\n--- BHB91603 check asic number");
  check_BM1391_asic_reg(gChain,'\0','\0',true);
  printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,(uint)cgpu.chain_asic_num[gChain]);
  if (cgpu.chain_asic_num[gChain] != BHB91603_ASIC_NUMBER) {
    pthread_cancel(cgpu.receive_id);
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",(uint)cgpu.chain_asic_num[gChain]);
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n",DAT_000180b0,(uint)cgpu.chain_asic_num[gChain]);
    puts("----------------------------\n\n");
    sleep(Conf.close_power_delay);
LAB_00017ea0:
    enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
    power_off();
    return;
  }
  BHB91603_set_baud(gChain,'\0');
  reset_hash_board();
  set_fpga_baud('\x1a');
  cgpu.chain_asic_num[gChain] = '\0';
  puts("\n--- double check asic number");
  check_BM1391_asic_reg(gChain,'\0','\0',true);
  printf("\n--- check chain: J%d has asicNum = %d\n",gChain + 1,(uint)cgpu.chain_asic_num[gChain]);
  if (cgpu.chain_asic_num[gChain] == BHB91603_ASIC_NUMBER) {
    if (*(char *)(DAT_000180b4 + 800) == '\0') {
      BHB91603_calculate_timeout_and_baud();
      set_BM1391_freq(gChain,'\0',Conf.Freq,true);
      BHB91603_set_address(gChain);
      BHB91603_set_baud(gChain,*(uchar *)(DAT_000183d8 + 0x321));
      BM1391_set_TM(gChain,'\0',0x3f,true);
      write_axi_fpga(0x22,Conf.timeout | 0x80000000);
      usleep(10000);
      BM1391_soft_reset_sensor(gChain);
      BM1391_enable_extended_mode_of_temperature_sensor(gChain);
      gIsReadTemp = true;
      if (gHashBoard_BHB91603P == false) {
        if (gHashBoard_BHB91603S == false) {
          pthread_cancel(*ppVar1);
          pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(cgpu.pic_heart_beat_id);
          pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
          pthread_cancel(cgpu.receive_id);
          write_lcd(0,"     Config     ",0x10);
LAB_00017efc:
          write_lcd_no_memset(1," Hashboard Type ",0x10);
          write_lcd_no_memset(2," in Config.ini  ",0x10);
          printf("\n!!!%s: Can\'t find Hashboard type when open core, fail\n\n\n",DAT_000180b0);
          goto LAB_00017f1e;
        }
        BHB91603_S_open_core(gChain);
      }
      else {
        BHB91603_P_open_core(gChain);
      }
      adjust_voltage(gChain,gI2c);
      puts("\nBegin send test pattern");
      if (gStartTest == false) {
        if (time_counter < Conf.HeatingUpTime) {
          do {
            usleep(10000);
            if (gStartTest != false) goto LAB_00018198;
          } while (time_counter < Conf.HeatingUpTime);
        }
        ppVar2 = DAT_000183dc;
        pthread_cancel(DAT_000183dc[1]);
        pthread_cancel(*ppVar1);
        pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(ppVar2[3]);
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
LAB_00018198:
      ppVar1 = DAT_000183dc;
      iVar6 = pthread_create(DAT_000183dc,(pthread_attr_t *)0x0,BHB91603_send_func + 1,
                             chain_info + gChain);
      if (iVar6 != 0) {
        pthread_cancel(ppVar1[2]);
        pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(ppVar1[3]);
        pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
        pthread_cancel(ppVar1[1]);
        write_lcd(0,"   Creat send   ",0x10);
        write_lcd_no_memset(1,"   thread fail  ",0x10);
        write_lcd_no_memset(3,"   test again   ",0x10);
        printf("\n!!!%s: create BHB91603_send_func fail\n\n\n",DAT_000183e0);
        goto LAB_00017ea0;
      }
      pthread_join(*ppVar1,(void **)0x0);
      pthread_join(ppVar1[1],(void **)0x0);
      pthread_cancel(ppVar1[2]);
      uVar5 = BHB91603_get_result(gChain);
      if ((int)(uVar5 << 0x1f) < 0) {
        if (gEEPROM_error == false) {
          _Var4 = BHB91603_AT24C02_write_total_data(gI2c,gChain);
          if (_Var4) {
            puts("\nEEPROM OK\n");
          }
          else {
            puts("\nEEPROM NG\n");
          }
        }
        else {
          printf("\n!!!%s: Don\'t save data into EEPROM, because EEPROM test fail!!\n\n",
                 DAT_000183e0);
        }
        BHB91603_print_lcd(uVar5);
        sleep(Conf.close_power_delay);
      }
      else {
        BHB91603_print_lcd(uVar5);
        sleep(Conf.close_power_delay);
        if (pattern_test_time < gHowManyVoltageLevel) goto LAB_00018360;
      }
      enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
      power_off();
LAB_00018360:
      pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
      pthread_cancel(ppVar1[3]);
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      set_fan_speed(0);
      usleep(500000);
      return;
    }
    pthread_cancel(cgpu.receive_id);
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    write_lcd(1," find all ASIC  ",0x10);
    write_lcd_no_memset(2,"       OK       ",0x10);
    printf("\nFind %d ASIC, OK\n",BHB91603_ASIC_NUMBER);
  }
  else {
    pthread_cancel(cgpu.receive_id);
    pthread_cancel(*ppVar1);
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    sprintf(lcd_display_buf + 7,"%d",(uint)cgpu.chain_asic_num[gChain]);
    write_lcd(0,"   Only have    ",0x10);
    write_lcd_no_memset(1,lcd_display_buf,0x10);
    write_lcd_no_memset(2,"      ASIC      ",0x10);
    printf("\n\n---%s: Only have %d ASIC\n",DAT_000180b0,(uint)cgpu.chain_asic_num[gChain]);
    puts("----------------------------\n\n");
  }
  sleep(Conf.close_power_delay);
LAB_00017f1e:
  enable_dsPIC33EP16GS202_dc_dc((uint)gChain,gI2c,'\0');
  power_off();
  return;
}


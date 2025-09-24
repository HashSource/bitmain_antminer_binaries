
/* WARNING: Unknown calling convention */

_Bool scan_code_from_hashboard(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  uint32_t uVar3;
  int32_t iVar4;
  char time_stamp [48];
  char tmp1 [256];
  _Bool qrcode_ok;
  _Bool sn_ok;
  uint8_t i;
  
  sn_ok = false;
  qrcode_ok = false;
  i = '\0';
  if (gScanCodeGun_data_ready == '\x03') {
    if (scan_code_from_hashboard::display) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Got Scan code");
      lcd_show(2,"Press");
      lcd_show(3,"Start Key");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : No need scan code, Press Start Key to Begin Test\n","scan_code_from_hashboard");
      builtin_strncpy(tmp1,"No need scan code, Press Start Key to Begin Test",0x30);
      tmp1[0x30] = '\0';
      log_to_file(tmp1,time_stamp);
      scan_code_from_hashboard::display = false;
    }
  }
  else {
    reset_fpga(0);
    usleep(150000);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    uVar3 = _get_hardware_version();
    printf("%s : FPGA version is 0x%08x\n","scan_code_from_hashboard",uVar3);
    uVar3 = _get_hardware_version();
    snprintf(tmp1,0x100,"FPGA version is 0x%08x",uVar3);
    log_to_file(tmp1,time_stamp);
    enable_bypass_mode();
    _Var2 = check_scan_code_gun();
    if (!_Var2) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Scan code gun don\'t plug on J4\n","scan_code_from_hashboard");
      builtin_strncpy(tmp1,"Scan code gun don\'t plug on J4",0x1f);
      log_to_file(tmp1,time_stamp);
      lcd_common_show("Scan code gun","don\'t plug on","J4");
      return false;
    }
    set_bt8d_chain(gCode_gun_chain,0x1a);
    flush_scanner_data();
    gScanCodeGun_data_ready = '\0';
    lcd_common_show("Scan","QR Code",(char *)0x0);
    while (gScanCodeGun_data_ready != '\x03') {
      sn_ok = false;
      qrcode_ok = false;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : wait gScanCodeGun_data_ready\n","scan_code_from_hashboard");
      builtin_strncpy(tmp1,"wait gScanCodeGun_data_ready",0x1c);
      tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      iVar4 = read_ipreport_key_val();
      if (iVar4 == 0) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Please Scan code");
        lcd_show(2,"first");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Please Scan code first\n","scan_code_from_hashboard");
        uVar1 = tmp1._20_4_;
        builtin_strncpy(tmp1,"Please Scan code first",0x17);
        tmp1[0x17] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
      }
      scan_hashboard_info(&sn,&qr_code,&sn_ok,&qrcode_ok,1000);
      if (sn_ok != false) {
        gScanCodeGun_data_ready = gScanCodeGun_data_ready | 1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Got SN code... gScanCodeGun_data_ready = %d\n","scan_code_from_hashboard",
               (uint)gScanCodeGun_data_ready);
        snprintf(tmp1,0x100,"Got SN code... gScanCodeGun_data_ready = %d",
                 (uint)gScanCodeGun_data_ready);
        log_to_file(tmp1,time_stamp);
      }
      if (qrcode_ok != false) {
        gScanCodeGun_data_ready = gScanCodeGun_data_ready | 2;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Got QR code... gScanCodeGun_data_ready = %d\n","scan_code_from_hashboard",
               (uint)gScanCodeGun_data_ready);
        snprintf(tmp1,0x100,"Got QR code... gScanCodeGun_data_ready = %d",
                 (uint)gScanCodeGun_data_ready);
        log_to_file(tmp1,time_stamp);
      }
      if (gScanCodeGun_data_ready == '\x01') {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"SN  OK");
        lcd_show(2,"Scan QR code");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Got SN code\n","scan_code_from_hashboard");
        builtin_strncpy(tmp1,"Got SN code",0xc);
        log_to_file(tmp1,time_stamp);
      }
      if (gScanCodeGun_data_ready == '\x02') {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"QR code OK");
        lcd_show(2,"Scan SN code");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Got QR code\n","scan_code_from_hashboard");
        builtin_strncpy(tmp1,"Got QR code",0xc);
        log_to_file(tmp1,time_stamp);
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : SN data::[%s]\n","scan_code_from_hashboard",0xa2a101);
    snprintf(tmp1,0x100,"SN data::[%s]",0xa2a101);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : QR code data::\n","scan_code_from_hashboard");
    builtin_strncpy(tmp1,"QR code data",0xc);
    tmp1[0xc] = ':';
    tmp1[0xd] = ':';
    tmp1[0xe] = '\0';
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : factory_job::[%s].\n","scan_code_from_hashboard",&qr_code);
    snprintf(tmp1,0x100,"factory_job::[%s].",&qr_code);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_die::[%s].\n","scan_code_from_hashboard",0xa2a090);
    snprintf(tmp1,0x100,"chip_die::[%s].",0xa2a090);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_marking::[%s].\n","scan_code_from_hashboard",0xa2a0a0);
    snprintf(tmp1,0x100,"chip_marking::[%s].",0xa2a0a0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_bin::[%s].\n","scan_code_from_hashboard",0xa2a0b0);
    snprintf(tmp1,0x100,"chip_bin::[%s].",0xa2a0b0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_ftversion::[%s].\n","scan_code_from_hashboard",0xa2a0c0);
    snprintf(tmp1,0x100,"chip_ftversion::[%s].",0xa2a0c0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : temp_sensor_type::[%s].\n","scan_code_from_hashboard",0xa2a0d0);
    snprintf(tmp1,0x100,"temp_sensor_type::[%s].",0xa2a0d0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : hashboard_ctrl_code::[%s].\n","scan_code_from_hashboard",0xa2a0e0);
    snprintf(tmp1,0x100,"hashboard_ctrl_code::[%s].",0xa2a0e0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : hashboard_index::[%s].\n","scan_code_from_hashboard",0xa2a0f0);
    snprintf(tmp1,0x100,"hashboard_index::[%s].",0xa2a0f0);
    log_to_file(tmp1,time_stamp);
    _Var2 = check_sn_qr_code_legality(&sn,&qr_code);
    if (!_Var2) {
      gScanCodeGun_data_ready = '\0';
      return false;
    }
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Got Scan code");
    lcd_show(2,"wait for find");
    lcd_show(3,"test standard");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : got scan code\n","scan_code_from_hashboard");
    builtin_strncpy(tmp1,"got scan cod",0xc);
    tmp1[0xc] = 'e';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return true;
}


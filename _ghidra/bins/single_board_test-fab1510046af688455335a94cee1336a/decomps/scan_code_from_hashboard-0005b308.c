
/* WARNING: Unknown calling convention */

_Bool scan_code_from_hashboard(void)

{
  undefined4 uVar1;
  _Bool _Var2;
  uint32_t uVar3;
  int32_t iVar4;
  char time_stamp [48];
  char tmp1 [2048];
  char chip_bin_list [2];
  char chip_ftversion_2 [16];
  char chip_ftversion_1 [16];
  _Bool qrcode_ok;
  _Bool sn_ok;
  int chip_mbb_col;
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
      printf("%s: No need scan code, Press Start Key to Begin Test\n","scan_code_from_hashboard");
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
    printf("%s: FPGA version is 0x%08x\n","scan_code_from_hashboard",uVar3);
    uVar3 = _get_hardware_version();
    snprintf(tmp1,0x800,"FPGA version is 0x%08x",uVar3);
    log_to_file(tmp1,time_stamp);
    enable_bypass_mode();
    check_scan_code_gun();
    set_bt8d_chain(gCode_gun_chain,0x1a);
    flush_scanner_data();
    gScanCodeGun_data_ready = '\0';
    while (gScanCodeGun_data_ready != '\x03') {
      sn_ok = false;
      qrcode_ok = false;
      iVar4 = read_ipreport_key_val();
      if (iVar4 == 0) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Please Scan code");
        lcd_show(2,"first");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Please Scan code first\n","scan_code_from_hashboard");
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
        printf("%s: Got SN code... gScanCodeGun_data_ready = %d\n","scan_code_from_hashboard",
               (uint)gScanCodeGun_data_ready);
        snprintf(tmp1,0x800,"Got SN code... gScanCodeGun_data_ready = %d",
                 (uint)gScanCodeGun_data_ready);
        log_to_file(tmp1,time_stamp);
      }
      if (qrcode_ok != false) {
        gScanCodeGun_data_ready = gScanCodeGun_data_ready | 2;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Got QR code... gScanCodeGun_data_ready = %d\n","scan_code_from_hashboard",
               (uint)gScanCodeGun_data_ready);
        snprintf(tmp1,0x800,"Got QR code... gScanCodeGun_data_ready = %d",
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
        printf("%s: Got SN code\n","scan_code_from_hashboard");
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
        printf("%s: Got QR code\n","scan_code_from_hashboard");
        builtin_strncpy(tmp1,"Got QR code",0xc);
        log_to_file(tmp1,time_stamp);
      }
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: SN data::[%s]\n","scan_code_from_hashboard",0x101b665);
    snprintf(tmp1,0x800,"SN data::[%s]",0x101b665);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: QR code data::\n","scan_code_from_hashboard");
    builtin_strncpy(tmp1,"QR code data",0xc);
    tmp1[0xc] = ':';
    tmp1[0xd] = ':';
    tmp1[0xe] = '\0';
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: factory_job::[%s].\n","scan_code_from_hashboard",&qr_code);
    snprintf(tmp1,0x800,"factory_job::[%s].",&qr_code);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: chip_die::[%s].\n","scan_code_from_hashboard",0x101b5e0);
    snprintf(tmp1,0x800,"chip_die::[%s].",0x101b5e0);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: chip_marking::[%s].\n","scan_code_from_hashboard",0x101b5f0);
    snprintf(tmp1,0x800,"chip_marking::[%s].",0x101b5f0);
    log_to_file(tmp1,time_stamp);
    chip_mbb_col = 0;
    if (qr_code.chip_ftversion[5] == 'M') {
      multiple_ft_bin_info_decompress
                (qr_code.chip_ftversion,chip_ftversion_1,chip_ftversion_2,qr_code.chip_bin,
                 chip_bin_list,(int *)0x0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: MBB chip_ftversion:FT1[%s],BIN%c,FT2[%s],BIN%c,COL[%d]\n",
             "scan_code_from_hashboard",chip_ftversion_1,(uint)(byte)chip_bin_list[0],
             chip_ftversion_2,(uint)(byte)chip_bin_list[1],chip_mbb_col);
      snprintf(tmp1,0x800,"MBB chip_ftversion:FT1[%s],BIN%c,FT2[%s],BIN%c,COL[%d]",chip_ftversion_1,
               (uint)(byte)chip_bin_list[0],chip_ftversion_2,(uint)(byte)chip_bin_list[1],
               chip_mbb_col);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chip_ftversion::[%s].\n","scan_code_from_hashboard",0x101b610);
      snprintf(tmp1,0x800,"chip_ftversion::[%s].",0x101b610);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: chip_bin::[%s].\n","scan_code_from_hashboard",0x101b600);
      snprintf(tmp1,0x800,"chip_bin::[%s].",0x101b600);
      log_to_file(tmp1,time_stamp);
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: temp_sensor_type::[%s].\n","scan_code_from_hashboard",0x101b620);
    snprintf(tmp1,0x800,"temp_sensor_type::[%s].",0x101b620);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: hashboard_ctrl_code::[%s].\n","scan_code_from_hashboard",0x101b630);
    snprintf(tmp1,0x800,"hashboard_ctrl_code::[%s].",0x101b630);
    log_to_file(tmp1,time_stamp);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: hashboard_index::[%s].\n","scan_code_from_hashboard",0x101b640);
    snprintf(tmp1,0x800,"hashboard_index::[%s].",0x101b640);
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
    printf("%s: got scan code\n","scan_code_from_hashboard");
    builtin_strncpy(tmp1,"got scan cod",0xc);
    tmp1[0xc] = 'e';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return true;
}


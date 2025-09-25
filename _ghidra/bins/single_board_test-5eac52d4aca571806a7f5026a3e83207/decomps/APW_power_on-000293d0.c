
_Bool APW_power_on(uint32_t voltage)

{
  uint32_t uVar1;
  _Bool _Var2;
  int32_t iVar3;
  uint32_t voltage_local;
  char time_stamp [48];
  char tmp1 [256];
  int32_t ret;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s\n","APW_power_on","APW_power_on");
  snprintf(tmp1,0x100,"%s","APW_power_on");
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : voltage:%d\n","APW_power_on",voltage);
  snprintf(tmp1,0x100,"voltage:%d",voltage);
  log_to_file(tmp1,time_stamp);
  uVar1 = g_apw_power_version;
  _Var2 = find_APW_power_version(g_apw_power_version);
  if (_Var2) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Read out APW versions is 0x%02x\n","APW_power_on",uVar1);
    snprintf(tmp1,0x100,"Read out APW versions is 0x%02x",uVar1);
    log_to_file(tmp1,time_stamp);
    bitmain_set_watchdog('\0');
    iVar3 = bitmain_set_voltage((double)voltage / 100.0);
    if (iVar3 < 0) {
      iVar3 = bitmain_set_voltage((double)voltage / 100.0);
      if (iVar3 < 0) {
        gHistory_Result[gPattern_test_counter].apw_power_ok = false;
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"APW set voltage");
        lcd_show(2,"error");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : APW set voltage error ret=0x%x!!!\n","APW_power_on",iVar3);
        snprintf(tmp1,0x100,"APW set voltage error ret=0x%x!!!",iVar3);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : APW set voltage ok, voltage is %02f\n","APW_power_on",
             SUB84((double)voltage / 100.0,0),(int)((ulonglong)((double)voltage / 100.0) >> 0x20));
      snprintf(tmp1,0x100,"APW set voltage ok, voltage is %02f",tmp1,(double)voltage / 100.0);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : APW set voltage ok, voltage is %02f\n","APW_power_on",
             SUB84((double)voltage / 100.0,0),(int)((ulonglong)((double)voltage / 100.0) >> 0x20));
      snprintf(tmp1,0x100,"APW set voltage ok, voltage is %02f",tmp1,(double)voltage / 100.0);
      log_to_file(tmp1,time_stamp);
    }
    iVar3 = bitmain_power_on();
    if (iVar3 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : APW power on ok\n","APW_power_on");
      builtin_strncpy(tmp1,"APW power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar3 = bitmain_power_on();
      if (iVar3 != 0) {
        gHistory_Result[gPattern_test_counter].apw_power_ok = false;
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"APW Power on");
        lcd_show(2,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : APW power on fail\n","APW_power_on");
        builtin_strncpy(tmp1,"APW power on fai",0x10);
        tmp1[0x10] = 'l';
        tmp1[0x11] = '\0';
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : APW power on ok\n","APW_power_on");
      builtin_strncpy(tmp1,"APW power on ok",0x10);
      log_to_file(tmp1,time_stamp);
    }
    _Var2 = true;
  }
  else {
    gHistory_Result[gPattern_test_counter].apw_power_ok = false;
    gStart_show_on_lcd = false;
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"APW version");
    lcd_show(2,"error");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Can\'t match APW version: %d\n","APW_power_on",uVar1);
    snprintf(tmp1,0x100,"Can\'t match APW version: %d",uVar1);
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}


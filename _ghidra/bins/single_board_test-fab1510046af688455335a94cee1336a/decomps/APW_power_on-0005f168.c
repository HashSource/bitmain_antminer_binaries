
_Bool APW_power_on(int power_version,uint32_t voltage)

{
  _Bool _Var1;
  int iVar2;
  int32_t iVar3;
  uint32_t voltage_local;
  int power_version_local;
  char time_stamp [48];
  char tmp1 [2048];
  int32_t ret;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: %s\n","APW_power_on","APW_power_on");
  snprintf(tmp1,0x800,"%s","APW_power_on");
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: bitmain_power_version: %d\n","APW_power_on",power_version);
  snprintf(tmp1,0x800,"bitmain_power_version: %d",power_version);
  log_to_file(tmp1,time_stamp);
  _Var1 = find_APW_power_version(power_version);
  if (_Var1) {
    gHistory_Result[gPattern_test_counter].power_version = power_version;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Read out APW versions is 0x%02x\n","APW_power_on",power_version);
    snprintf(tmp1,0x800,"Read out APW versions is 0x%02x",power_version);
    log_to_file(tmp1,time_stamp);
    ret = power_version;
  }
  else {
    ret = bitmain_power_version();
    _Var1 = find_APW_power_version(ret);
    if (!_Var1) {
      gHistory_Result[gPattern_test_counter].apw_power_ok = false;
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"APW version");
      lcd_show(2,"error");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Can\'t match APW version: %d\n","APW_power_on",ret);
      snprintf(tmp1,0x800,"Can\'t match APW version: %d",ret);
      log_to_file(tmp1,time_stamp);
      return false;
    }
    gHistory_Result[gPattern_test_counter].power_version = ret;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Read out APW versions is 0x%02x\n","APW_power_on",ret);
    snprintf(tmp1,0x800,"Read out APW versions is 0x%02x",ret);
    log_to_file(tmp1,time_stamp);
  }
  switch(ret) {
  case 100:
  case 0x65:
  case 0x66:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
    bitmain_set_watchdog('\0');
  }
  iVar2 = strcmp((Local_Config_Information->Hash_Board).Board_Name,"NBT2006-36");
  if (iVar2 == 0) {
    _Var1 = init_dac((Local_Config_Information->Hash_Board).Board_Name,(uint8_t)gChain);
    if (!_Var1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Init DAC");
      lcd_show(2,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: DAC init fail !!!\n","APW_power_on");
      builtin_strncpy(tmp1,"DAC init fail !!",0x10);
      tmp1[0x10] = '!';
      tmp1[0x11] = '\0';
      log_to_file(tmp1,time_stamp);
      return false;
    }
    _Var1 = set_dac_voltage((Local_Config_Information->Hash_Board).Board_Name,(uint8_t)gChain,
                            (double)((float)voltage / 100.0));
    if (!_Var1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Set DAC");
      lcd_show(2,"voltage");
      lcd_show(2,"fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Set DAC voltage fail !!!\n","APW_power_on");
      builtin_strncpy(tmp1,"Set DAC voltage fail !!!",0x18);
      tmp1[0x18] = '\0';
      log_to_file(tmp1,time_stamp);
      return false;
    }
  }
  else {
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
        printf("%s: APW set voltage error ret=0x%x!!!\n","APW_power_on",iVar3);
        snprintf(tmp1,0x800,"APW set voltage error ret=0x%x!!!",iVar3);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: APW set voltage ok, voltage is %02f\n","APW_power_on",
             SUB84((double)voltage / 100.0,0),(int)((ulonglong)((double)voltage / 100.0) >> 0x20));
      snprintf(tmp1,0x800,"APW set voltage ok, voltage is %02f",tmp1,(double)voltage / 100.0);
      log_to_file(tmp1,time_stamp);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: APW set voltage ok, voltage is %02f\n","APW_power_on",
             SUB84((double)voltage / 100.0,0),(int)((ulonglong)((double)voltage / 100.0) >> 0x20));
      snprintf(tmp1,0x800,"APW set voltage ok, voltage is %02f",tmp1,(double)voltage / 100.0);
      log_to_file(tmp1,time_stamp);
    }
  }
  iVar3 = bitmain_power_on();
  if (iVar3 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: APW power on ok\n","APW_power_on");
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
      printf("%s: APW power on fail\n","APW_power_on");
      builtin_strncpy(tmp1,"APW power on fai",0x10);
      tmp1[0x10] = 'l';
      tmp1[0x11] = '\0';
      log_to_file(tmp1,time_stamp);
      return false;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: APW power on ok\n","APW_power_on");
    builtin_strncpy(tmp1,"APW power on ok",0x10);
    log_to_file(tmp1,time_stamp);
  }
  usleep(200000);
  return true;
}


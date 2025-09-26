
/* WARNING: Unknown calling convention */

_Bool prepare_platform_environment(void)

{
  int32_t iVar1;
  _Bool _Var2;
  char time_stamp [48];
  char tmp1 [2048];
  int8_t lcd_data [64];
  uint32_t i;
  
  memset(lcd_data,0,0x40);
  lcd_data[0] = ' ';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","prepare_platform_environment");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  iVar1 = platform_init();
  if (iVar1 == 0) {
    for (i = 0; i < 0x40; i = i + 1) {
      lcd_data[i] = ' ';
    }
    iVar1 = lcd_show_result(0,lcd_data,0x40);
    if (iVar1 == 0) {
      gFan = pwm_init(PWM_CTRL_FAN,0);
      if (gFan < 0) {
        lcd_clear_result();
        lcd_show(1,"Fan init");
        lcd_show(2,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: FAN init fail!!!\n","prepare_platform_environment");
        builtin_strncpy(tmp1,"FAN init fail!!!",0x10);
        tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        _Var2 = false;
      }
      else {
        _Var2 = true;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: LCD init fail!!!\n","prepare_platform_environment");
      builtin_strncpy(tmp1,"LCD init fail!!!",0x10);
      tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: platform init fail!!!\n","prepare_platform_environment");
    builtin_strncpy(tmp1,"platform init fail!!",0x14);
    tmp1[0x14] = '!';
    tmp1[0x15] = '\0';
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}


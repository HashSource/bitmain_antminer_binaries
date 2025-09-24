
/* WARNING: Unknown calling convention */

_Bool init_pic(void)

{
  int32_t iVar1;
  int iVar2;
  _Bool _Var3;
  char time_stamp [48];
  char tmp1 [256];
  int32_t thread_ret;
  int32_t pic_version;
  
  iVar1 = open_pic((uint8_t)gChain);
  if (iVar1 < 0) {
    gHistory_Result[gPattern_test_counter].pic_ok = false;
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"open pic");
    lcd_show(2,"fail");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : open pic fail!!!\n","init_pic");
    builtin_strncpy(tmp1,"open pic fail!!!",0x10);
    tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    _Var3 = false;
  }
  else {
    iVar1 = reset_pic((uint8_t)gChain);
    if (iVar1 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : reset pic ok\n","init_pic");
      builtin_strncpy(tmp1,"reset pic ok",0xc);
      tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar1 = reset_pic((uint8_t)gChain);
      if (iVar1 != 0) {
        gHistory_Result[gPattern_test_counter].pic_ok = false;
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"reset pic");
        lcd_show(2,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : reset pic fail\n","init_pic");
        builtin_strncpy(tmp1,"reset pic fa",0xc);
        tmp1[0xc] = 'i';
        tmp1[0xd] = 'l';
        tmp1[0xe] = '\0';
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : reset pic ok\n","init_pic");
      builtin_strncpy(tmp1,"reset pic ok",0xc);
      tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
    }
    iVar1 = jump_from_loader_to_app((uint8_t)gChain);
    if (iVar1 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : jump from loader to app ok\n","init_pic");
      builtin_strncpy(tmp1,"jump from loader to app ok",0x1b);
      log_to_file(tmp1,time_stamp);
    }
    else {
      iVar1 = jump_from_loader_to_app((uint8_t)gChain);
      if (iVar1 != 0) {
        gHistory_Result[gPattern_test_counter].pic_ok = false;
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Pic jump to");
        lcd_show(2,"App mode");
        lcd_show(3,"fail");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : pic jump from loader to app fail\n","init_pic");
        builtin_strncpy(tmp1,"pic jump from loader to app fail",0x20);
        tmp1[0x20] = '\0';
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : jump from loader to app ok\n","init_pic");
      builtin_strncpy(tmp1,"jump from loader to app ok",0x1b);
      log_to_file(tmp1,time_stamp);
    }
    usleep(300000);
    iVar1 = get_pic_version((uint8_t)gChain);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : PIC version: 0x%02x\n","init_pic",iVar1);
    snprintf(tmp1,0x100,"PIC version: 0x%02x",iVar1);
    log_to_file(tmp1,time_stamp);
    usleep(200000);
    gStart_heart_beat = true;
    iVar2 = pthread_create(&pic_heart_beat_id,(pthread_attr_t *)0x0,(__start_routine *)0x2aafd,
                           (void *)0x0);
    if (iVar2 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Creat pic heart beat function ok\n","init_pic");
      builtin_strncpy(tmp1,"Creat pic heart beat function ok",0x20);
      tmp1[0x20] = '\0';
      log_to_file(tmp1,time_stamp);
      usleep(500000);
      _Var3 = true;
    }
    else {
      gStart_heart_beat = false;
      pthread_join(pic_heart_beat_id,(void **)0x0);
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Pic heart beat");
      lcd_show(2,"Creat  fail");
      lcd_show(3,"Start again");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Pic heart beat thread creat fail\n","init_pic");
      builtin_strncpy(tmp1,"Pic heart beat thread creat fail",0x20);
      tmp1[0x20] = '\0';
      log_to_file(tmp1,time_stamp);
      _Var3 = false;
    }
  }
  return _Var3;
}


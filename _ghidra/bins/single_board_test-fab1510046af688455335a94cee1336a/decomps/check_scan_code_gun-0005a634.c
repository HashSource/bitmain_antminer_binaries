
/* WARNING: Unknown calling convention */

_Bool check_scan_code_gun(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [2048];
  bitmain_sys_capability_t info;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","check_scan_code_gun");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  get_system_capability(&info);
  if (info.board_num == 0) {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(2,"No Scan code gun");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Don\'t detect hashboard or scan code gun\n","check_scan_code_gun");
    builtin_strncpy(tmp1,"Don\'t detect hashboard or scan code gun",0x28);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: info.board_num = %d\n","check_scan_code_gun",info.board_num);
    snprintf(tmp1,0x800,"info.board_num = %d",info.board_num);
    log_to_file(tmp1,time_stamp);
    gCode_gun_chain = info.board[info.board_num - 1].board_id;
    if (gCode_gun_chain == 3) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: gCode_gun_chain = %d\n","check_scan_code_gun",gCode_gun_chain);
      snprintf(tmp1,0x800,"gCode_gun_chain = %d",gCode_gun_chain);
      log_to_file(tmp1,time_stamp);
      _Var1 = true;
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Scan code gun");
      lcd_show(2,"don\'t plug on");
      lcd_show(3,"J4");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Scan code gun don\'t plug on J4\n","check_scan_code_gun");
      builtin_strncpy(tmp1,"Scan code gun don\'t plug on J4",0x1f);
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  return _Var1;
}


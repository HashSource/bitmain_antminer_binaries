
/* WARNING: Unknown calling convention */

_Bool prepare_pattern(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  _Bool ret;
  
  iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1new");
  if (iVar2 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : PT1 test doesn\'t need read pattern files\n","prepare_pattern");
    builtin_strncpy(tmp1,"PT1 test doesn\'t need read pattern files",0x28);
    tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    _Var1 = true;
  }
  else if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
    _Var1 = get_works_ex2();
    iVar2 = strcmp(Local_Config_Information->Test_Process,"SWEEP");
    if (((iVar2 == 0) || (iVar2 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar2 == 0))
       && (_Var1)) {
      copy_works_from_PT2_pattern(Local_Config_Information,&pattern_info_new);
    }
    if (_Var1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : read pattern file done\n","prepare_pattern");
      builtin_strncpy(tmp1,"read pattern file done",0x17);
      log_to_file(tmp1,time_stamp);
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"Read pattern");
      lcd_show(2,"file fail");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : read pattern file fail\n","prepare_pattern");
      builtin_strncpy(tmp1,"read pattern file fail",0x17);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Hardware/SWEEP Pattern test doesn\'t need read pattern files\n","prepare_pattern");
    builtin_strncpy(tmp1,"Hardware/SWEEP Pattern test doesn\'t need read pattern files",0x3c);
    log_to_file(tmp1,time_stamp);
    _Var1 = true;
  }
  return _Var1;
}


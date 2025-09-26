
/* WARNING: Unknown calling convention */

_Bool prepare_pattern(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [2048];
  _Bool ret;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: prepare_pattern\n","prepare_pattern");
  builtin_strncpy(tmp1,"prepare_pattern",0x10);
  log_to_file(tmp1,time_stamp);
  iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1new");
  if (iVar1 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: PT1 test doesn\'t need read pattern files\n","prepare_pattern");
    builtin_strncpy(tmp1,"PT1 test doesn\'t need read pattern files",0x28);
    tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    ret = true;
  }
  else if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
    iVar1 = strncmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1362",6);
    if ((((iVar1 == 0) ||
         (iVar1 = strncmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1366",6), iVar1 == 0))
        || (iVar1 = strncmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1368",6), iVar1 == 0
           )) || (iVar1 = strncmp((Local_Config_Information->Hash_Board).Asic_Type,"BM1370",6),
                 iVar1 == 0)) {
      ret = get_works_ex2();
      iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3");
      if ((((iVar1 == 0) ||
           (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1&PT3"), iVar1 == 0)) ||
          (iVar1 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar1 == 0)) &&
         ((ret && (((Local_Config_Information->Test_Info).Test_Method.Software_Pattern != false ||
                   ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern !=
                    false)))))) {
        copy_works_from_PT2_super_pattern(Local_Config_Information,&pattern_info);
        copy_works_from_PT2_new_pattern(Local_Config_Information,&pattern_info_new);
      }
    }
    else {
      ret = get_works_ex((Local_Config_Information->Hash_Board).Asic_Type,
                         (Local_Config_Information->Hash_Board).Asic_Num,
                         (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
                         (Local_Config_Information->Hash_Board).Big_Core_Num,
                         (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
    }
    if (ret == true) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: read pattern file done\n","prepare_pattern");
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
      printf("%s: read pattern file fail\n","prepare_pattern");
      builtin_strncpy(tmp1,"read pattern file fail",0x17);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Hardware Pattern test doesn\'t need read pattern files\n","prepare_pattern");
    builtin_strncpy(tmp1,"Hardware Pattern test doesn\'t need read pattern file",0x34);
    tmp1[0x34] = 's';
    tmp1[0x35] = '\0';
    log_to_file(tmp1,time_stamp);
    ret = true;
  }
  return ret;
}


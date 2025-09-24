
/* WARNING: Unknown calling convention */

_Bool prepare_test_process(void)

{
  int iVar1;
  _Bool _Var2;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Will do DropLevel: %s\n","prepare_test_process",Local_Config_Information);
  snprintf(tmp1,0x100,"Will do DropLevel: %s",Local_Config_Information);
  log_to_file(tmp1,time_stamp);
  iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1");
  if (iVar1 == 0) {
    if ((Local_Config_Information->Hash_Board).Asic_Num == 1) {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Asic_Type);
      lcd_show(1,"Single ASIC");
      lcd_show(2,"don\'t support");
      lcd_show(3,"PT1 test");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Single ASIC don\'t support PT1 test\n","prepare_test_process");
      builtin_strncpy(tmp1,"Single ASIC don\'t support PT1 test",0x23);
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
    else {
      if ((Local_Config_Information->Test_Info).Factory_Mode != true) {
        (Local_Config_Information->Repair_Mode).Clear_EEPROM_Data = false;
      }
      display_main_page();
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Will do PT1: Only find ASIC test\n","prepare_test_process");
      builtin_strncpy(tmp1,"Will do PT1: Only find ASIC test",0x20);
      tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
      log_to_file(tmp1,time_stamp);
      _Var2 = true;
    }
  }
  else {
    iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+");
    if (iVar1 == 0) {
      if ((Local_Config_Information->Hash_Board).Asic_Num == 1) {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Asic_Type);
        lcd_show(1,"Single ASIC");
        lcd_show(2,"don\'t support");
        lcd_show(3,"PT1 test");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Single ASIC don\'t support PT1 test\n","prepare_test_process");
        builtin_strncpy(tmp1,"Single ASIC don\'t support PT1 test",0x23);
        log_to_file(tmp1,time_stamp);
        _Var2 = false;
      }
      else {
        if ((Local_Config_Information->Test_Info).Factory_Mode != true) {
          (Local_Config_Information->Repair_Mode).Clear_EEPROM_Data = false;
        }
        display_main_page();
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Will do PT1+: do PT1 and pattern\n","prepare_test_process");
        builtin_strncpy(tmp1,"Will do PT1+: do PT1 and pattern",0x20);
        tmp1._32_4_ = tmp1._32_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        _Var2 = true;
      }
    }
    else {
      iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1new");
      if (iVar1 == 0) {
        if ((Local_Config_Information->Hash_Board).Asic_Num == 1) {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Asic_Type);
          lcd_show(1,"Single ASIC");
          lcd_show(2,"don\'t support");
          lcd_show(3,"PT1 test");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Single ASIC don\'t support PT1 test\n","prepare_test_process");
          builtin_strncpy(tmp1,"Single ASIC don\'t support PT1 test",0x23);
          log_to_file(tmp1,time_stamp);
          _Var2 = false;
        }
        else {
          display_main_page();
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Will do PT1new: do PT1 and use the bar code stored in chip\n",
                 "prepare_test_process");
          builtin_strncpy(tmp1,"Will do PT1new: do PT1 and use the bar code stored in ch",0x38);
          tmp1[0x38] = 'i';
          tmp1[0x39] = 'p';
          tmp1[0x3a] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var2 = true;
        }
      }
      else {
        iVar1 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
        if (iVar1 == 0) {
          display_main_page();
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Will do Reset_Low: keep reset low then power on, modify Close_Power_Delay to keep power on\n"
                 ,"prepare_test_process");
          memcpy(tmp1,
                 "Will do Reset_Low: keep reset low then power on, modify Close_Power_Delay to keep power on"
                 ,0x5b);
          log_to_file(tmp1,time_stamp);
          _Var2 = true;
        }
        else {
          iVar1 = strcmp(Local_Config_Information->Test_Process,"PT2");
          if ((((iVar1 == 0) ||
               (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar1 == 0)) ||
              (iVar1 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar1 == 0)) ||
             (iVar1 = strcmp(Local_Config_Information->Test_Process,"DropLevel"), iVar1 == 0)) {
            if ((Local_Config_Information->Hash_Board).Asic_Num == 1) {
              display_main_page();
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : You are in single Asic Manual PT2 test mode, please make sure all the configrations are correct!\n"
                     ,"prepare_test_process");
              memcpy(tmp1,
                     "You are in single Asic Manual PT2 test mode, please make sure all the configrations are correct!"
                     ,0x61);
              log_to_file(tmp1,time_stamp);
              _Var2 = true;
            }
            else {
              display_main_page();
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : You are in Manual PT2 test mode, will use the level stored in the eeprom!\n"
                     ,"prepare_test_process");
              memcpy(tmp1,
                     "You are in Manual PT2 test mode, will use the level stored in the eeprom!",
                     0x4a);
              log_to_file(tmp1,time_stamp);
              _Var2 = true;
            }
          }
          else {
            display_main_page();
            _Var2 = false;
          }
        }
      }
    }
  }
  return _Var2;
}


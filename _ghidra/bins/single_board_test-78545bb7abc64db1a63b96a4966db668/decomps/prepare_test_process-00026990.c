
/* WARNING: Unknown calling convention */

_Bool prepare_test_process(void)

{
  _Bool _Var1;
  int iVar2;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Will do DropLevel: %s\n","prepare_test_process",Local_Config_Information);
  snprintf(tmp1,0x100,"Will do DropLevel: %s",Local_Config_Information);
  log_to_file(tmp1,time_stamp);
  iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1");
  if (iVar2 == 0) {
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
      _Var1 = false;
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
      _Var1 = true;
    }
  }
  else {
    iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1+");
    if (iVar2 == 0) {
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
        _Var1 = false;
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
        _Var1 = true;
      }
    }
    else {
      iVar2 = strcmp(Local_Config_Information->Test_Process,"PT1new");
      if (iVar2 == 0) {
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
          _Var1 = false;
        }
        else {
          if ((Local_Config_Information->Repair_Mode).Enable_Repair != false) {
            (Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun = true;
          }
          display_main_page();
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Will do PT1new: do PT1 and scan bar code and store chip info\n",
                 "prepare_test_process");
          builtin_strncpy(tmp1,"Will do PT1new: do PT1 and scan bar code and store chip info",0x3c);
          tmp1[0x3c] = '\0';
          log_to_file(tmp1,time_stamp);
          _Var1 = true;
        }
      }
      else {
        iVar2 = strcmp(Local_Config_Information->Test_Process,"Reset_Low");
        if (iVar2 == 0) {
          display_main_page();
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Will do Reset_Low: keep reset low then power on, modify Close_Power_Delay to keep power on\n"
                 ,"prepare_test_process");
          memcpy(tmp1,
                 "Will do Reset_Low: keep reset low then power on, modify Close_Power_Delay to keep power on"
                 ,0x5b);
          log_to_file(tmp1,time_stamp);
          _Var1 = true;
        }
        else {
          iVar2 = strcmp(Local_Config_Information->Test_Process,"PT2");
          if ((((iVar2 == 0) ||
               (iVar2 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar2 == 0)) ||
              (iVar2 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar2 == 0)) ||
             (iVar2 = strcmp(Local_Config_Information->Test_Process,"DropLevel"), iVar2 == 0)) {
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
              _Var1 = true;
            }
            else {
              if ((Local_Config_Information->Test_Info).Factory_Mode == false) {
                display_main_page();
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : You are in Manual PT2 test mode, please make sure all the configrations are correct!\n"
                       ,"prepare_test_process");
                memcpy(tmp1,
                       "You are in Manual PT2 test mode, please make sure all the configrations are correct!"
                       ,0x55);
                log_to_file(tmp1,time_stamp);
              }
              else {
                lcd_clear_result();
                lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                lcd_show(1,"connect internet");
                lcd_show(2,"please  wait");
                _Var1 = prepare_MES_system_handshake_information(0);
                if (!_Var1) {
                  lcd_clear_result();
                  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                  lcd_show(1,"Prepare all");
                  lcd_show(2,"config handshake");
                  lcd_show(3,"fail");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : Prepare all config handshake fail\n","prepare_test_process");
                  builtin_strncpy(tmp1,"Prepare all config handshake fail",0x22);
                  log_to_file(tmp1,time_stamp);
                  return false;
                }
                _Var1 = download_MES_system_Config_file();
                if (!_Var1) {
                  return false;
                }
                _Var1 = check_whether_MES_system_response_is_correct();
                if (!_Var1) {
                  return false;
                }
                _Var1 = save_MES_system_config_information(0);
                if (!_Var1) {
                  return false;
                }
                _Var1 = init_MES_system_config_information();
                if (!_Var1) {
                  return false;
                }
                _Var1 = parse_MES_system_config_information(0);
                if (!_Var1) {
                  lcd_clear_result();
                  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                  lcd_show(1,"parse MES all");
                  lcd_show(2,"config infor");
                  lcd_show(3,"fail");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : parse MES all config infor fail\n","prepare_test_process");
                  builtin_strncpy(tmp1,"parse MES all config infor fail",0x20);
                  log_to_file(tmp1,time_stamp);
                  return false;
                }
                print_MES_system_information();
                display_main_page();
              }
              _Var1 = true;
            }
          }
          else {
            display_main_page();
            _Var1 = false;
          }
        }
      }
    }
  }
  return _Var1;
}


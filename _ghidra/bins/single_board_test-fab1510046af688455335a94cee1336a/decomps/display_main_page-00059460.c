
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void display_main_page(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [2048];
  char lcd_data [16];
  
  lcd_clear_result();
  iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1");
  if (iVar1 == 0) {
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(2,"Only find ASIC");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Only find ASIC\n","display_main_page");
    builtin_strncpy(tmp1,"Only find AS",0xc);
    tmp1[0xc] = 'I';
    tmp1[0xd] = 'C';
    tmp1[0xe] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1new");
    if (iVar1 == 0) {
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      if ((Local_Config_Information->Repair_Mode).Enable_Repair == false) {
        lcd_show(1,"PT1 scan QR");
        lcd_show(2,"Only find ASIC");
        lcd_show(3,"save chip info");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Only find ASIC and save chip info\n","display_main_page");
        builtin_strncpy(tmp1,"Only find ASIC and save chip info",0x22);
        log_to_file(tmp1,time_stamp);
      }
      else {
        lcd_show(1,"PT1");
        lcd_show(2,"Repair mode");
        lcd_show(3,"Only find ASIC");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Only find ASIC and save chip info\n","display_main_page");
        builtin_strncpy(tmp1,"Only find ASIC and save chip info",0x22);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+");
      if (iVar1 == 0) {
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"Find ASIC");
        memset(lcd_data,0,0x10);
        sprintf(lcd_data,"%d pattern test",
                (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
        lcd_show(2,lcd_data);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: do PT1+ test\n","display_main_page");
        builtin_strncpy(tmp1,"do PT1+ test",0xc);
        tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
      }
      else {
        iVar1 = strcmp(Local_Config_Information->Test_Process,"SWEEP");
        if (iVar1 == 0) {
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"SWEEP Mode");
          lcd_show(2,"Press");
          lcd_show(3,"Start Key");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: SWEEP mode, press test button to start\n","display_main_page");
          builtin_strncpy(tmp1,"SWEEP mode, press test button to start",0x27);
          log_to_file(tmp1,time_stamp);
        }
        else {
          iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3");
          if (iVar1 == 0) {
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"PT3 Mode");
            lcd_show(2,"Press");
            lcd_show(3,"Start Key");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: PT3 mode, press test button to start\n","display_main_page");
            builtin_strncpy(tmp1,"PT3 mode, press test button to start",0x24);
            tmp1._36_4_ = tmp1._36_4_ & 0xffffff00;
            log_to_file(tmp1,time_stamp);
          }
          else {
            iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1&PT3");
            if (iVar1 == 0) {
              lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
              lcd_show(1,"PT1&PT3 Mode");
              lcd_show(2,"Press");
              lcd_show(3,"Start Key");
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: PT1&PT3 mode, press test button to start\n","display_main_page");
              builtin_strncpy(tmp1,"PT1&PT3 mode, press test button to start",0x28);
              tmp1._40_4_ = tmp1._40_4_ & 0xffffff00;
              log_to_file(tmp1,time_stamp);
            }
            else {
              iVar1 = strcmp(Local_Config_Information->Test_Process,"PT2");
              if (iVar1 == 0) {
                if ((Local_Config_Information->Hash_Board).Asic_Num == 1) {
                  lcd_show(0,(Local_Config_Information->Hash_Board).Asic_Type);
                  memset(lcd_data,0,0x10);
                  sprintf(lcd_data,"IC:%2d  P:%d",(Local_Config_Information->Hash_Board).Asic_Num,
                          (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
                  lcd_show(1,lcd_data);
                  memset(lcd_data,0,0x10);
                  sprintf(lcd_data,"FREQ:%d L:%d",
                          (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Frequence
                          ,(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Level);
                  lcd_show(2,lcd_data);
                  lcd_show(3,"Vol: set power");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Single ASIC pattern test\n","display_main_page");
                  builtin_strncpy(tmp1,"Single ASIC pattern test",0x18);
                  tmp1._24_4_ = tmp1._24_4_ & 0xffffff00;
                  log_to_file(tmp1,time_stamp);
                }
                else if ((Local_Config_Information->Test_Info).Factory_Mode == false) {
                  if ((Local_Config_Information->Test_Info).Bypass_Scan_Code_Gun == false) {
                    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                    lcd_show(1,"Manual Mode:PT2");
                    lcd_show(2,"Please Scan code");
                    lcd_show(3,"first");
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: Manual Test Mode:PT2, Please Scan code first\n","display_main_page")
                    ;
                    builtin_strncpy(tmp1,"Manual Test Mode:PT2, Please Scan code first",0x2c);
                    tmp1[0x2c] = '\0';
                    log_to_file(tmp1,time_stamp);
                  }
                  else {
                    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                    memset(lcd_data,0,0x10);
                    sprintf(lcd_data,"IC:%2d  P:%d",(Local_Config_Information->Hash_Board).Asic_Num,
                            (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
                    lcd_show(1,lcd_data);
                    memset(lcd_data,0,0x10);
                    sprintf(lcd_data,"FREQ:%d L:%d",
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].
                            Frequence,
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Level);
                    lcd_show(2,lcd_data);
                    memset(lcd_data,0,0x10);
                    sprintf(lcd_data,"Voltage: %d",
                            (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage
                           );
                    lcd_show(3,lcd_data);
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s: Manual Mode:PT2, does not use scan code gun\n","display_main_page");
                    builtin_strncpy(tmp1,"Manual Mode:PT2, does not use scan code gun",0x2c);
                    log_to_file(tmp1,time_stamp);
                  }
                }
                else {
                  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                  lcd_show(1,"Factory Mode:PT2");
                  lcd_show(2,"Press");
                  lcd_show(3,"Start Key");
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s: Factory Mode:PT2, press test button to start\n","display_main_page");
                  builtin_strncpy(tmp1,"Factory Mode:PT2, press test button to start",0x2c);
                  tmp1[0x2c] = '\0';
                  log_to_file(tmp1,time_stamp);
                }
              }
              else {
                lcd_clear_result();
                lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
                lcd_show(1,"Test Process");
                lcd_show(2,"error");
              }
            }
          }
        }
      }
    }
  }
  return;
}


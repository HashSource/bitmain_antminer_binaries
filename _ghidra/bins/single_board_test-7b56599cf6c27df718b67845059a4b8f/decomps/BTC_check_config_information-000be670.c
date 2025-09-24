
_Bool BTC_check_config_information(char *asic_type)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  _Bool _Var4;
  char *pcVar5;
  char *asic_type_local;
  char time_stamp [48];
  char tmp1 [256];
  char lcd_data [16];
  uint8_t i;
  
  iVar1 = strcmp(asic_type,"BM1368");
  if (iVar1 == 0) {
    iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1");
    if (((((iVar1 == 0) ||
          (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1new"), iVar1 == 0)) ||
         (iVar1 = strcmp(Local_Config_Information->Test_Process,"PT1+"), iVar1 == 0)) ||
        ((iVar1 = strcmp(Local_Config_Information->Test_Process,"PT2"), iVar1 == 0 ||
         (iVar1 = strcmp(Local_Config_Information->Test_Process,"Reset_Low"), iVar1 == 0)))) ||
       ((iVar1 = strcmp(Local_Config_Information->Test_Process,"PT3"), iVar1 == 0 ||
        ((iVar1 = strcmp(Local_Config_Information->Test_Process,"SWEEP"), iVar1 == 0 ||
         (iVar1 = strcmp(Local_Config_Information->Test_Process,"DropLevel"), iVar1 == 0)))))) {
      i = (Local_Config_Information->Test_Info).Test_Method.Software_Pattern != false;
      if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern != false) {
        i = i + '\x01';
      }
      if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern != false) {
        i = i + '\x01';
      }
      if (i == '\x01') {
        if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern != false) {
          if ((Local_Config_Information->Test_Info).Test_Method.Midstate_Number != 0x10) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"midstate number");
            lcd_show(2,"error");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : In software pattern mode, midstate number is %d, error\n",
                   "BTC_check_config_information",
                   (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
            snprintf(tmp1,0x100,"In software pattern mode, midstate number is %d, error",
                     (Local_Config_Information->Test_Info).Test_Method.Midstate_Number);
            log_to_file(tmp1,time_stamp);
          }
          if (((Local_Config_Information->Test_Info).Test_Method.Midstate_Number == 0x10) &&
             (((Local_Config_Information->Test_Info).Test_Standard.Pattern_Number & 3) != 0)) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"Pattern Number");
            lcd_show(2,"midstate number");
            lcd_show(3,"error");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : When BM1368 test 16 midstate, Pattern_Number %% 2 must be equal 0. Now Pattern_Number: %d\n"
                   ,"BTC_check_config_information",
                   (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
            snprintf(tmp1,0x100,
                     "When BM1368 test 16 midstate, Pattern_Number %% 2 must be equal 0. Now Pattern_Number: %d"
                     ,(Local_Config_Information->Test_Info).Test_Standard.Pattern_Number);
            log_to_file(tmp1,time_stamp);
            return false;
          }
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern != false) {
          (Local_Config_Information->Test_Info).Test_Method.Midstate_Number = 1;
          gMax_Nonce = 0x376400;
          gTimeout_Clock = 0x14d;
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern != false) {
          (Local_Config_Information->Test_Info).Test_Method.Midstate_Number = 0x10;
        }
        (Local_Config_Information->Hash_Board).Big_Core_Num = 0x50;
        (Local_Config_Information->Hash_Board).Small_Core_Num = 0x4fc;
        (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core = 0x10;
        if ((Local_Config_Information->Hash_Board).Asic_Num < 0x81) {
          if ((Local_Config_Information->Hash_Board).Asic_Num < 0x41) {
            if ((Local_Config_Information->Hash_Board).Asic_Num < 0x21) {
              lcd_clear_result();
              lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
              lcd_show(1,"Asic_Num < 32");
              lcd_show(3,"error");
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : ERROR: Asic_Num == %d\n","BTC_check_config_information",
                     (Local_Config_Information->Hash_Board).Asic_Num);
              snprintf(tmp1,0x100,"ERROR: Asic_Num == %d",
                       (Local_Config_Information->Hash_Board).Asic_Num);
              log_to_file(tmp1,time_stamp);
              return false;
            }
            gAddress_interval = 4;
          }
          else {
            gAddress_interval = 2;
          }
        }
        else {
          gAddress_interval = 1;
        }
        gEEPROM_length = 0x100;
        _Var4 = true;
      }
      else {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"test method");
        lcd_show(2,"conflict");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
          pcVar3 = "false";
        }
        else {
          pcVar3 = "true";
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
          pcVar2 = "false";
        }
        else {
          pcVar2 = "true";
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
          pcVar5 = "false";
        }
        else {
          pcVar5 = "true";
        }
        printf("%s : test method conflict. Software_Pattern: %s, Hardware_Pattern: %s, Autogen_Pattern: %s\n"
               ,"BTC_check_config_information",pcVar3,pcVar2,pcVar5);
        if ((Local_Config_Information->Test_Info).Test_Method.Software_Pattern == false) {
          pcVar3 = "false";
        }
        else {
          pcVar3 = "true";
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Hardware_Pattern == false) {
          pcVar2 = "false";
        }
        else {
          pcVar2 = "true";
        }
        if ((Local_Config_Information->Test_Info).Test_Method.Autogen_Pattern == false) {
          pcVar5 = "false";
        }
        else {
          pcVar5 = "true";
        }
        snprintf(tmp1,0x100,
                 "test method conflict. Software_Pattern: %s, Hardware_Pattern: %s, Autogen_Pattern: %s"
                 ,pcVar3,pcVar2,pcVar5);
        log_to_file(tmp1,time_stamp);
        _Var4 = false;
      }
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"test process");
      lcd_show(2,"error");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : test process (%s) error.\n","BTC_check_config_information",
             Local_Config_Information);
      snprintf(tmp1,0x100,"test process (%s) error.",Local_Config_Information);
      log_to_file(tmp1,time_stamp);
      _Var4 = false;
    }
  }
  else {
    memset(lcd_data,0,0x10);
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(1,"Don\'t support");
    strcpy(lcd_data,asic_type);
    lcd_show(2,lcd_data);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Don\'t support %s. asic should be BM1368\n","BTC_check_config_information",
           asic_type);
    snprintf(tmp1,0x100,"Don\'t support %s. asic should be BM1368",asic_type);
    log_to_file(tmp1,time_stamp);
    _Var4 = false;
  }
  return _Var4;
}


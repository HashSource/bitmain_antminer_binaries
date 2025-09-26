
_Bool check_sn_qr_code_legality(hashboard_sn *sn,hashboard_qr_code *qr_code)

{
  _Bool _Var1;
  size_t sVar2;
  hashboard_qr_code *qr_code_local;
  hashboard_sn *sn_local;
  char time_stamp [48];
  char tmp1 [256];
  
  sVar2 = strlen(sn->board_sn);
  if (sVar2 == 0x11) {
    sVar2 = strlen(qr_code->chip_die);
    if (sVar2 == 2) {
      sVar2 = strlen(qr_code->chip_marking);
      if (sVar2 < 0xe) {
        _Var1 = check_is_multiple_ft_version(qr_code->chip_ftversion);
        if (!_Var1) {
          sVar2 = strlen(qr_code->chip_bin);
          if (sVar2 != 4) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"chip bin");
            lcd_show(2,"is not correct");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : chip bin isn\'t correct, chip bin: %s\n","check_sn_qr_code_legality",
                   qr_code->chip_bin);
            snprintf(tmp1,0x100,"chip bin isn\'t correct, chip bin: %s",qr_code->chip_bin);
            log_to_file(tmp1,time_stamp);
            return false;
          }
          sVar2 = strlen(qr_code->chip_ftversion);
          if (sVar2 != 9) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"ft version");
            lcd_show(2,"is not correct");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : ft version isn\'t correct, ft version: %s\n","check_sn_qr_code_legality",
                   qr_code->chip_ftversion);
            snprintf(tmp1,0x100,"ft version isn\'t correct, ft version: %s",qr_code->chip_ftversion)
            ;
            log_to_file(tmp1,time_stamp);
            return false;
          }
        }
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
          _Var1 = check_pic_sensor_type(qr_code->temp_sensor_type);
          if (!_Var1) {
            return false;
          }
          strcpy((Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor.Pic_Sensor_Model,
                 qr_code->temp_sensor_type);
        }
        _Var1 = true;
      }
      else {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"chip marking");
        lcd_show(2,"is not correct");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : chip marking isn\'t correct, chip marking: %s\n","check_sn_qr_code_legality",
               qr_code->chip_marking);
        snprintf(tmp1,0x100,"chip marking isn\'t correct, chip marking: %s",qr_code->chip_marking);
        log_to_file(tmp1,time_stamp);
        _Var1 = false;
      }
    }
    else {
      lcd_clear_result();
      lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
      lcd_show(1,"chip die");
      lcd_show(2,"is not correct");
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : chip die isn\'t correct, chip die: %s\n","check_sn_qr_code_legality",
             qr_code->chip_die);
      snprintf(tmp1,0x100,"chip die isn\'t correct, chip die: %s",qr_code->chip_die);
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
  }
  else {
    lcd_clear_result();
    lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
    lcd_show(2,"SN isn\'t correct");
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : SN isn\'t correct, sn: %s\n","check_sn_qr_code_legality",sn->board_sn);
    snprintf(tmp1,0x100,"SN isn\'t correct, sn: %s",sn->board_sn);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}


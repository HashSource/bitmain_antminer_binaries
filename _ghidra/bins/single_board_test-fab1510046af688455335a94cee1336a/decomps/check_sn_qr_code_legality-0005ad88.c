
_Bool check_sn_qr_code_legality(hashboard_sn *sn,hashboard_qr_code *qr_code)

{
  _Bool _Var1;
  size_t sVar2;
  hashboard_qr_code *qr_code_local;
  hashboard_sn *sn_local;
  char time_stamp [48];
  char tmp1 [2048];
  
  sVar2 = strlen(sn->board_sn);
  if (sVar2 == 0x11) {
    sVar2 = strlen(qr_code->chip_die);
    if (sVar2 == 2) {
      sVar2 = strlen(qr_code->chip_marking);
      if (sVar2 < 0xe) {
        if ((qr_code->ft_bin_list).ft_bin_cnt == 0) {
          sVar2 = strlen(qr_code->chip_bin);
          if (sVar2 != 4) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"chip bin");
            lcd_show(2,"is not correct");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: chip bin isn\'t correct, chip bin: %s\n","check_sn_qr_code_legality",
                   qr_code->chip_bin);
            snprintf(tmp1,0x800,"chip bin isn\'t correct, chip bin: %s",qr_code->chip_bin);
            log_to_file(tmp1,time_stamp);
            return false;
          }
        }
        else {
          sVar2 = strlen(qr_code->chip_bin);
          if (sVar2 != 5) {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"chip bin");
            lcd_show(2,"is not correct");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: chip bin isn\'t correct, chip bin: %s\n","check_sn_qr_code_legality",
                   qr_code->chip_bin);
            snprintf(tmp1,0x800,"chip bin isn\'t correct, chip bin: %s",qr_code->chip_bin);
            log_to_file(tmp1,time_stamp);
            return false;
          }
        }
        sVar2 = strlen(qr_code->chip_ftversion);
        if (sVar2 == 9) {
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false
             ) {
            _Var1 = check_asic_sensor_type(qr_code->temp_sensor_type);
            if (!_Var1) {
              return false;
            }
            strcpy((Local_Config_Information->Hash_Board).Sensor_Info.Asic_Sensor.Asic_Sensor_Model,
                   qr_code->temp_sensor_type);
          }
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false)
          {
            _Var1 = check_pic_sensor_type(qr_code->temp_sensor_type);
            if (!_Var1) {
              return false;
            }
            strcpy((Local_Config_Information->Hash_Board).Sensor_Info.Pic_Sensor.Pic_Sensor_Model,
                   qr_code->temp_sensor_type);
          }
          sVar2 = strlen(qr_code->hashboard_ctrl_code);
          if (sVar2 == 7) {
            _Var1 = true;
          }
          else {
            lcd_clear_result();
            lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
            lcd_show(1,"hashboard");
            lcd_show(1,"ctrl code");
            lcd_show(2,"is not correct");
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: hashboard ctrl code isn\'t correct, hashboard ctrl code: %s\n",
                   "check_sn_qr_code_legality",qr_code->hashboard_ctrl_code);
            snprintf(tmp1,0x800,"hashboard ctrl code isn\'t correct, hashboard ctrl code: %s",
                     qr_code->hashboard_ctrl_code);
            log_to_file(tmp1,time_stamp);
            _Var1 = false;
          }
        }
        else {
          lcd_clear_result();
          lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
          lcd_show(1,"ft version");
          lcd_show(2,"is not correct");
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: ft version isn\'t correct, ft version: %s\n","check_sn_qr_code_legality",
                 qr_code->chip_ftversion);
          snprintf(tmp1,0x800,"ft version isn\'t correct, ft version: %s",qr_code->chip_ftversion);
          log_to_file(tmp1,time_stamp);
          _Var1 = false;
        }
      }
      else {
        lcd_clear_result();
        lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
        lcd_show(1,"chip marking");
        lcd_show(2,"is not correct");
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: chip marking isn\'t correct, chip marking: %s\n","check_sn_qr_code_legality",
               qr_code->chip_marking);
        snprintf(tmp1,0x800,"chip marking isn\'t correct, chip marking: %s",qr_code->chip_marking);
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
      printf("%s: chip die isn\'t correct, chip die: %s\n","check_sn_qr_code_legality",
             qr_code->chip_die);
      snprintf(tmp1,0x800,"chip die isn\'t correct, chip die: %s",qr_code->chip_die);
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
    printf("%s: SN isn\'t correct, sn: %s\n","check_sn_qr_code_legality",sn->board_sn);
    snprintf(tmp1,0x800,"SN isn\'t correct, sn: %s",sn->board_sn);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  return _Var1;
}


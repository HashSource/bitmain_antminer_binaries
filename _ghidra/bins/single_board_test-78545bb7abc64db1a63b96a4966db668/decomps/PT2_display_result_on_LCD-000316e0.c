
int PT2_display_result_on_LCD(uint32_t test_loop_index)

{
  uint uVar1;
  bool bVar2;
  uint32_t test_loop_index_local;
  uint32_t bad_asic_addr [4];
  char lcd_data [16];
  uint8_t ok_history;
  uint32_t test_result;
  uint8_t j;
  uint8_t i;
  uint8_t bad_asic_num;
  _Bool temp;
  
  bVar2 = true;
  bad_asic_num = '\0';
  j = '\0';
  bad_asic_addr[0] = 0;
  bad_asic_addr[1] = 0;
  bad_asic_addr[2] = 0;
  bad_asic_addr[3] = 0;
  test_result = 0;
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
  if (gHistory_Result[test_loop_index].test_standard == '\0') {
    lcd_show(1,"Pattern: OK");
    bVar2 = gHistory_Result[test_loop_index].eeprom_ok == false;
    if (bVar2) {
      lcd_show(2,"EEPROM:  NG");
      test_result = 0x400;
    }
    else {
      lcd_show(2,"EEPROM:  OK");
    }
    temp = !bVar2;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false)
    {
      if (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false) {
        lcd_show(3,"Ctr_Sensor:NG");
        temp = false;
        test_result = test_result | 0x200;
      }
      else {
        lcd_show(3,"Ctr_Sensor:OK");
      }
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) {
      if (gHistory_Result[test_loop_index].switch_sensor_all_ok == false) {
        lcd_show(3,"Ctr_Sensor:NG");
        temp = false;
        test_result = test_result | 0x200;
      }
      else {
        lcd_show(3,"Ctr_Sensor:OK");
      }
    }
    if (temp) {
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"Level:  %d",gHistory_Result[test_loop_index].level);
      lcd_show(0,lcd_data);
    }
  }
  else if (gHistory_Result[test_loop_index].test_standard == '\x01') {
    lcd_show(1,"Pattern: OK");
    for (i = '\0'; (uint)i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + '\x01') {
      if ((gHistory_Result[test_loop_index].bad_asic_list[i] != true) &&
         (bad_asic_num = bad_asic_num + '\x01', j < 4)) {
        uVar1 = (uint)j;
        j = j + '\x01';
        bad_asic_addr[uVar1] = (uint)i;
      }
    }
    if (bad_asic_num != '\0') {
      memset(lcd_data,0,0x10);
      if (bad_asic_num == '\x01') {
        sprintf(lcd_data,"B_A: %d",bad_asic_addr[0]);
      }
      else if (bad_asic_num == '\x02') {
        sprintf(lcd_data,"B_A: %d %d",bad_asic_addr[0],bad_asic_addr[1]);
      }
      else if (bad_asic_num == '\x03') {
        sprintf(lcd_data,"B_A: %d %d %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2]);
      }
      else {
        sprintf(lcd_data,"B_A: %d %d %d %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2],
                bad_asic_addr[3]);
      }
      lcd_show(3,lcd_data);
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false
           ) {
          if (gHistory_Result[test_loop_index].eeprom_ok == false) {
            lcd_show(2,"EEPROM:  NG");
            bVar2 = false;
            test_result = 0x400;
          }
          else {
            lcd_show(2,"EEPROM:  OK");
          }
        }
        else if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
                (gHistory_Result[test_loop_index].switch_sensor_all_ok == false)) {
          if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
             (gHistory_Result[test_loop_index].switch_sensor_all_ok == true)) {
            if ((gHistory_Result[test_loop_index].eeprom_ok == true) ||
               (gHistory_Result[test_loop_index].switch_sensor_all_ok == false)) {
              lcd_show(2,"EE: NG   C_S: NG");
              bVar2 = false;
              test_result = 0x400;
            }
            else {
              lcd_show(2,"EE: NG   C_S: OK");
              bVar2 = false;
              test_result = 0x400;
            }
          }
          else {
            lcd_show(2,"EE: OK   C_S: NG");
            bVar2 = false;
            test_result = 0x200;
          }
        }
        else {
          lcd_show(2,"EE: OK   C_S: OK");
        }
      }
      else if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
              (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false)) {
        if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
           (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == true)) {
          if ((gHistory_Result[test_loop_index].eeprom_ok == true) ||
             (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false)) {
            lcd_show(2,"EE: NG   C_S: NG");
            bVar2 = false;
            test_result = 0x400;
          }
          else {
            lcd_show(2,"EE: NG   C_S: OK");
            bVar2 = false;
            test_result = 0x400;
          }
        }
        else {
          lcd_show(2,"EE: OK   C_S: NG");
          bVar2 = false;
          test_result = 0x200;
        }
      }
      else {
        lcd_show(2,"EE: OK   C_S: OK");
      }
    }
    else if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
            (gHistory_Result[test_loop_index].pic_sensor_all_OK == false)) {
      if ((gHistory_Result[test_loop_index].eeprom_ok == false) ||
         (gHistory_Result[test_loop_index].pic_sensor_all_OK == true)) {
        if ((gHistory_Result[test_loop_index].eeprom_ok == true) ||
           (gHistory_Result[test_loop_index].pic_sensor_all_OK == false)) {
          lcd_show(2,"EE: NG   P_S: NG");
          bVar2 = false;
          test_result = 0x400;
        }
        else {
          lcd_show(2,"EE: NG   P_S: OK");
          bVar2 = false;
          test_result = 0x400;
        }
      }
      else {
        lcd_show(2,"EE: OK   P_S: NG");
        bVar2 = false;
        test_result = 0x200;
      }
    }
    else {
      lcd_show(2,"EE: OK   P_S: OK");
    }
    if (bVar2) {
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"Level:  %d",gHistory_Result[test_loop_index].level + 100);
      lcd_show(0,lcd_data);
    }
    if (bad_asic_num != '\0') {
      test_result = test_result | (gHistory_Result[test_loop_index].level + 100) * 0x100 | 0x40;
    }
  }
  else if (gHistory_Result[test_loop_index].test_standard == 0xf0) {
    if (gHistory_Result[test_loop_index].eeprom_ok == false) {
      lcd_show(1,"EEPROM:  NG");
      test_result = 0x400;
    }
    else {
      lcd_show(1,"EEPROM:  OK");
    }
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
       ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != true)) {
      if (gHistory_Result[test_loop_index].pic_sensor_all_OK == false) {
        lcd_show(1,"PIC Sensor: NG");
        test_result = test_result | 0x200;
      }
      else {
        lcd_show(1,"PIC Sensor: OK");
      }
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard != false)
    {
      if (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false) {
        if (gHistory_Result[test_loop_index].eeprom_ok == false) {
          lcd_show(1,"EROM:NG CS:NG");
        }
        else {
          lcd_show(1,"EROM:OK CS:NG");
        }
        test_result = test_result | 0x200;
      }
      else if (gHistory_Result[test_loop_index].eeprom_ok == false) {
        lcd_show(1,"EROM:NG CS:OK");
      }
      else {
        lcd_show(1,"EROM:OK CS:OK");
      }
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) {
      if (gHistory_Result[test_loop_index].switch_sensor_all_ok == false) {
        if (gHistory_Result[test_loop_index].eeprom_ok == false) {
          lcd_show(1,"EROM:NG CS:NG");
        }
        else {
          lcd_show(1,"EROM:OK CS:NG");
        }
        test_result = test_result | 0x200;
      }
      else if (gHistory_Result[test_loop_index].eeprom_ok == false) {
        lcd_show(1,"EROM:NG CS:OK");
      }
      else {
        lcd_show(1,"EROM:OK CS:OK");
      }
    }
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == true) ||
       ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic == false)) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != true) {
        if (gHistory_Result[test_loop_index].switch_sensor_all_ok == false) {
          lcd_show(1,"switch Sensor:  NG");
          test_result = test_result | 0x200;
        }
        else {
          lcd_show(1,"switch Sensor:  OK");
        }
        if ((gHistory_Result[test_loop_index].switch_sensor_all_ok == false) ||
           (gHistory_Result[test_loop_index].asic_sensor_all_OK == false)) {
          if (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false) {
            if (gHistory_Result[test_loop_index].asic_sensor_all_OK == false) {
              lcd_show(1,"P_S: NG  A_S: NG");
              test_result = test_result | 0x200;
            }
            else {
              lcd_show(1,"P_S: NG  A_S: OK");
              test_result = test_result | 0x200;
            }
          }
          else {
            lcd_show(1,"P_S: OK  A_S: NG");
            test_result = test_result | 0x200;
          }
        }
        else {
          lcd_show(1,"P_S: OK  A_S: OK");
        }
      }
    }
    else {
      if (gHistory_Result[test_loop_index].asic_sensor_all_OK == false) {
        lcd_show(1,"ASIC Sensor:  NG");
        test_result = test_result | 0x200;
      }
      else {
        lcd_show(1,"ASIC Sensor:  OK");
      }
      if ((gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false) ||
         (gHistory_Result[test_loop_index].asic_sensor_all_OK == false)) {
        if (gHistory_Result[test_loop_index].ctrlboard_sensor_all_OK == false) {
          if (gHistory_Result[test_loop_index].asic_sensor_all_OK == false) {
            lcd_show(1,"P_S: NG  A_S: NG");
            test_result = test_result | 0x200;
          }
          else {
            lcd_show(1,"P_S: NG  A_S: OK");
            test_result = test_result | 0x200;
          }
        }
        else {
          lcd_show(1,"P_S: OK  A_S: NG");
          test_result = test_result | 0x200;
        }
      }
      else {
        lcd_show(1,"P_S: OK  A_S: OK");
      }
    }
    if (((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) &&
       ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Asic != false)) {
      if ((gHistory_Result[test_loop_index].pic_sensor_all_OK == false) ||
         (gHistory_Result[test_loop_index].asic_sensor_all_OK == false)) {
        if (gHistory_Result[test_loop_index].pic_sensor_all_OK == false) {
          if (gHistory_Result[test_loop_index].asic_sensor_all_OK == false) {
            lcd_show(1,"P_S: NG  A_S: NG");
            test_result = test_result | 0x200;
          }
          else {
            lcd_show(1,"P_S: NG  A_S: OK");
            test_result = test_result | 0x200;
          }
        }
        else {
          lcd_show(1,"P_S: OK  A_S: NG");
          test_result = test_result | 0x200;
        }
      }
      else {
        lcd_show(1,"P_S: OK  A_S: OK");
      }
    }
    for (i = '\0'; (uint)i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + '\x01') {
      if ((gHistory_Result[test_loop_index].bad_asic_list[i] != true) &&
         (bad_asic_num = bad_asic_num + '\x01', j < 4)) {
        uVar1 = (uint)j;
        j = j + '\x01';
        bad_asic_addr[uVar1] = (uint)i;
      }
    }
    if (bad_asic_num != '\0') {
      memset(lcd_data,0,0x10);
      sprintf(lcd_data,"B_A:  %d  pcs",(uint)bad_asic_num);
      lcd_show(2,lcd_data);
      memset(lcd_data,0,0x10);
      if (bad_asic_num == '\x01') {
        sprintf(lcd_data,"%d",bad_asic_addr[0]);
      }
      else if (bad_asic_num == '\x02') {
        sprintf(lcd_data,"%d  %d",bad_asic_addr[0],bad_asic_addr[1]);
      }
      else if (bad_asic_num == '\x03') {
        sprintf(lcd_data,"%d  %d  %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2]);
      }
      else {
        sprintf(lcd_data,"%d %d %d %d",bad_asic_addr[0],bad_asic_addr[1],bad_asic_addr[2],
                bad_asic_addr[3]);
      }
      lcd_show(3,lcd_data);
    }
    test_result = test_result | 0x80;
  }
  else if (gHistory_Result[test_loop_index].test_standard == 0xff) {
    if (gFind_dummy_data != false) {
      lcd_show(1,"Find Dummy Data");
    }
    test_result = 8;
  }
  return test_result;
}


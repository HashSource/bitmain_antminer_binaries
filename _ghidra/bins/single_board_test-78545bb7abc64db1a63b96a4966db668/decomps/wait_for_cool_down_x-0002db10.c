
_Bool wait_for_cool_down_x(uint32_t max_wait_time)

{
  uint8_t data_length;
  bool bVar1;
  int8_t iVar2;
  int8_t iVar3;
  uint32_t max_wait_time_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t switch_sensor_num;
  uint32_t wait_time;
  uint8_t i;
  _Bool result;
  
  wait_time = 0;
  data_length = (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num;
  do {
    bVar1 = true;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false
           ) {
          for (i = '\0';
              i < (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num;
              i = i + '\x01') {
            if (gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] != true) {
              bVar1 = false;
            }
          }
        }
      }
      else {
        for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
          if (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] != true) {
            bVar1 = false;
          }
        }
      }
    }
    else {
      for (i = '\0'; i < gPic_sensor_num; i = i + '\x01') {
        if (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] != true) {
          bVar1 = false;
        }
      }
    }
    if (bVar1) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
            false) {
          if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch !=
              false) {
            iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,data_length);
            iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,data_length);
            if ((((int)iVar2 - (int)iVar3 <
                  (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
                (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                       sensor_local_temperature_from_switch,data_length),
                iVar2 < '\x1f')) &&
               (iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                      sensor_local_temperature_from_switch,data_length), iVar2 < ':'
               )) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Hashboard cool down, begin test ...\n","wait_for_cool_down_x");
              builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
              log_to_file(tmp1,time_stamp);
              gRead_Pic_Temperature_time_interval = 0x14;
              return true;
            }
          }
        }
        else {
          iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard,
                                (uint8_t)gCtrlBoard_sensor_num);
          iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard,
                                (uint8_t)gCtrlBoard_sensor_num);
          if ((((int)iVar2 - (int)iVar3 <
                (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
              (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                     sensor_local_temperature_from_ctrlboard,
                                     (uint8_t)gCtrlBoard_sensor_num), iVar2 < '\x1f')) &&
             (iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_ctrlboard,
                                    (uint8_t)gCtrlBoard_sensor_num), iVar2 < ':')) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Hashboard cool down, begin test ...\n","wait_for_cool_down_x");
            builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
            log_to_file(tmp1,time_stamp);
            gRead_Pic_Temperature_time_interval = 0x14;
            return true;
          }
        }
      }
      else {
        iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                              sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num);
        iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                              sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num);
        if ((((int)iVar2 - (int)iVar3 <
              (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
            (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                   sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num),
            iVar2 < '\x1f')) &&
           (iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num),
           iVar2 < ':')) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Hashboard cool down, begin test ...\n","wait_for_cool_down_x");
          builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
          log_to_file(tmp1,time_stamp);
          gRead_Pic_Temperature_time_interval = 0x14;
          return true;
        }
      }
    }
    sleep(1);
    wait_time = wait_time + 1;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Waiting for Hashboard cool down for %d seconds ...\n","wait_for_cool_down_x",
           wait_time);
    snprintf(tmp1,0x100,"Waiting for Hashboard cool down for %d seconds ...",wait_time);
    log_to_file(tmp1,time_stamp);
    if (max_wait_time < wait_time) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Wait for Hashboard cool down for %d seconds, break\n","wait_for_cool_down_x",
             wait_time);
      snprintf(tmp1,0x100,"Wait for Hashboard cool down for %d seconds, break",wait_time);
      log_to_file(tmp1,time_stamp);
      return false;
    }
  } while( true );
}


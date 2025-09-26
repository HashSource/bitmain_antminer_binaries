
_Bool wait_for_cool_down_x(uint32_t max_wait_time)

{
  bool bVar1;
  int8_t iVar2;
  int8_t iVar3;
  uint32_t max_wait_time_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t wait_time;
  uint8_t i;
  _Bool result;
  
  wait_time = 0;
  do {
    bVar1 = true;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic == false) {
      if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard ==
          false) {
        if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false
           ) {
          for (i = '\0'; i < 2; i = i + '\x01') {
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
                                  sensor_local_temperature_from_switch,'\x02');
            iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,'\x02');
            if (((uint)((int)iVar2 - (int)iVar3) <
                 (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
               (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                      sensor_local_temperature_from_ctrlboard,'\x02'), iVar2 < '$'))
            {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_switch,'\x02');
              iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_switch,'\x02');
              printf("%s: Hashboard cool down, begin test ... max %d min %d\n",
                     "wait_for_cool_down_x",(int)iVar2,(int)iVar3);
              iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_switch,'\x02');
              iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_switch,'\x02');
              snprintf(tmp1,0x800,"Hashboard cool down, begin test ... max %d min %d",(int)iVar2,
                       (int)iVar3);
              log_to_file(tmp1,time_stamp);
              gRead_Pic_Temperature_time_interval = 0x14;
              return true;
            }
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,'\x02');
            iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,'\x02');
            printf("%s: Hashboard cool down, begin test ... max %d min %d\n","wait_for_cool_down_x",
                   (int)iVar2,(int)iVar3);
            iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,'\x02');
            iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_switch,'\x02');
            snprintf(tmp1,0x800,"Hashboard cool down, begin test ... max %d min %d",(int)iVar2,
                     (int)iVar3);
            log_to_file(tmp1,time_stamp);
          }
        }
        else {
          iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard,
                                (uint8_t)gCtrlBoard_sensor_num);
          iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_ctrlboard,
                                (uint8_t)gCtrlBoard_sensor_num);
          if (((uint)((int)iVar2 - (int)iVar3) <
               (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
             (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                    sensor_local_temperature_from_ctrlboard,
                                    (uint8_t)gCtrlBoard_sensor_num), iVar2 < '$')) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: Hashboard cool down, begin test ...\n","wait_for_cool_down_x");
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
        if (((uint)((int)iVar2 - (int)iVar3) <
             (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
           (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                  sensor_local_temperature_from_pic,(uint8_t)gPic_sensor_num),
           iVar2 < '$')) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Hashboard cool down, begin test ...\n","wait_for_cool_down_x");
          builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
          log_to_file(tmp1,time_stamp);
          gRead_Pic_Temperature_time_interval = 0x14;
          return true;
        }
      }
    }
    sleep(1);
    wait_time = wait_time + 1;
    if (wait_time % 10 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Waiting for Hashboard cool down for %d seconds ...\n","wait_for_cool_down_x",
             wait_time);
      snprintf(tmp1,0x800,"Waiting for Hashboard cool down for %d seconds ...",wait_time);
      log_to_file(tmp1,time_stamp);
    }
  } while (wait_time <= max_wait_time);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Wait for Hashboard cool down for %d seconds, break\n","wait_for_cool_down_x",wait_time
        );
  snprintf(tmp1,0x800,"Wait for Hashboard cool down for %d seconds, break",wait_time);
  log_to_file(tmp1,time_stamp);
  return false;
}


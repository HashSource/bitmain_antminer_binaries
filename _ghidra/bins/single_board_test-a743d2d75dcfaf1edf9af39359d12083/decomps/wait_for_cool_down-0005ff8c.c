
_Bool wait_for_cool_down(uint8_t pic_sensor_number,uint32_t max_wait_time)

{
  bool bVar1;
  int8_t iVar2;
  int8_t iVar3;
  uint32_t max_wait_time_local;
  uint8_t pic_sensor_number_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t wait_time;
  uint8_t i;
  _Bool result;
  
  wait_time = 0;
  do {
    bVar1 = true;
    for (i = '\0'; i < pic_sensor_number; i = i + '\x01') {
      if (gHistory_Result[gPattern_test_counter].pic_sensor_OK[i] != true) {
        bVar1 = false;
      }
    }
    if (bVar1) {
      iVar2 = get_max_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic
                            ,pic_sensor_number);
      iVar3 = get_min_value(gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_pic
                            ,pic_sensor_number);
      if (((uint)((int)iVar2 - (int)iVar3) <
           (Local_Config_Information->Test_Info).Temperature.Start_Temp_Gap_Pic) &&
         (iVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                                sensor_local_temperature_from_pic,pic_sensor_number), iVar2 < '$'))
      {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: Hashboard cool down, begin test ...\n","wait_for_cool_down");
        builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
        log_to_file(tmp1,time_stamp);
        gRead_Pic_Temperature_time_interval = 0x14;
        return true;
      }
    }
    sleep(1);
    wait_time = wait_time + 1;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Waiting for Hashboard cool down for %d seconds ...\n","wait_for_cool_down",wait_time
          );
    snprintf(tmp1,0x800,"Waiting for Hashboard cool down for %d seconds ...",wait_time);
    log_to_file(tmp1,time_stamp);
    if (max_wait_time < wait_time) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: Wait for Hashboard cool down for %d seconds, break\n","wait_for_cool_down",
             wait_time);
      snprintf(tmp1,0x800,"Wait for Hashboard cool down for %d seconds, break",wait_time);
      log_to_file(tmp1,time_stamp);
      return false;
    }
  } while( true );
}


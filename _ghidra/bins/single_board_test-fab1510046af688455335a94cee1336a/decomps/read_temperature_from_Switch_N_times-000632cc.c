
void read_temperature_from_Switch_N_times(uint8_t N)

{
  byte bVar1;
  byte bVar2;
  int32_t iVar3;
  uint8_t N_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t min_temp;
  uint8_t max_temp;
  int temp;
  int j;
  int chip_temp_index;
  int i_1;
  _Bool result;
  int retry;
  int i;
  
  result = true;
  set_chain_reg_connect_left_diode_to_temp((uint8_t)gChain);
  i = 0;
  do {
    if (0xb < i) {
      bVar1 = get_max_value(gHistory_Result[gPattern_test_counter].
                            sensor_local_temperature_from_switch,'\a');
      bVar2 = get_min_value(gHistory_Result[gPattern_test_counter].
                            sensor_local_temperature_from_switch,'\a');
      if (10 < (int)((uint)bVar1 - (uint)bVar2)) {
        for (i_1 = 0; i_1 < 7; i_1 = i_1 + 1) {
          if (((int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i_1]
               == (uint)bVar1) ||
             ((int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i_1]
              == (uint)bVar2)) {
            gHistory_Result[gPattern_test_counter].switch_sensor_OK[i_1] = false;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: chip temp sensor err index i %d is false max%d min%d\n",
                   "read_temperature_from_Switch_N_times",i_1,(uint)bVar1,(uint)bVar2);
            snprintf(tmp1,0x800,"chip temp sensor err index i %d is false max%d min%d",i_1,
                     (uint)bVar1,(uint)bVar2);
            log_to_file(tmp1,time_stamp);
          }
        }
      }
      for (chip_temp_index = 7; chip_temp_index < 0xc; chip_temp_index = chip_temp_index + 1) {
        if (('d' < gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                   [chip_temp_index]) ||
           (gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
            [chip_temp_index] < '\0')) {
          gHistory_Result[gPattern_test_counter].switch_sensor_OK[chip_temp_index] = false;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: chip temp sensor err index %d temp %d\n",
                 "read_temperature_from_Switch_N_times",chip_temp_index,
                 (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                      [chip_temp_index]);
          snprintf(tmp1,0x800,"chip temp sensor err index %d temp %d",chip_temp_index,
                   (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                        [chip_temp_index]);
          log_to_file(tmp1,time_stamp);
        }
      }
      for (i = 0; i < 0xc; i = i + 1) {
        result = (gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] & result) != 0;
      }
      if (result != false) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: All SWITCH sensor read out data\n","read_temperature_from_Switch_N_times");
        builtin_strncpy(tmp1,"All SWITCH sensor read out data",0x20);
        log_to_file(tmp1,time_stamp);
        gHistory_Result[gPattern_test_counter].switch_sensor_all_OK = true;
      }
      return;
    }
    retry = 0;
    do {
      sleep(retry);
      iVar3 = read_sensor_on_switch(gChain,i);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: index %d read %d retry %d\n","read_temperature_from_Switch_N_times",i,iVar3,retry)
      ;
      snprintf(tmp1,0x800,"index %d read %d retry %d",i,iVar3,retry);
      log_to_file(tmp1,time_stamp);
      retry = retry + 1;
      if ((0 < iVar3) && (iVar3 < 0x65)) break;
    } while (retry < (int)(uint)N);
    if ((iVar3 < 1) || (99 < iVar3)) {
      if (iVar3 == -10) {
        gHistory_Result[gPattern_test_counter].switch_OK = false;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s:  switch_OK is false\n","read_temperature_from_Switch_N_times");
        builtin_strncpy(tmp1," switch_OK is false",0x14);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] = true;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: index %d read %d switch_sensor_OK\n","read_temperature_from_Switch_N_times",i,
             iVar3);
      snprintf(tmp1,0x800,"index %d read %d switch_sensor_OK",i,iVar3);
      log_to_file(tmp1,time_stamp);
      gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i] = (int8_t)iVar3
      ;
      gHistory_Result[gPattern_test_counter].switch_OK = true;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s:  index %d %d the real temp read from switch is %d\n",
           "read_temperature_from_Switch_N_times",i,
           (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i],iVar3
          );
    snprintf(tmp1,0x800," index %d %d the real temp read from switch is %d",i,
             (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i],
             iVar3);
    log_to_file(tmp1,time_stamp);
    i = i + 1;
  } while( true );
}


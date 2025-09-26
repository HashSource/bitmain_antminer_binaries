
/* WARNING: Type propagation algorithm not settling */

void * read_temperature_from_CtrlBoard(void *arg)

{
  byte sesnor_id_00;
  _Bool _Var1;
  int32_t iVar2;
  int32_t iVar3;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int speed [4];
  uint8_t gCtrlBoard_sensor_addr [2];
  int8_t data [2];
  int32_t temp_1;
  int32_t ret_1;
  _Bool power_on_ctrl;
  uint8_t sensor_dev_addr;
  uint8_t switch_dev_addr;
  uint8_t sesnor_id;
  int32_t ret;
  int i_1;
  _Bool temp;
  int read_fail_cnt;
  uint8_t i;
  
  data[0] = -1;
  data[1] = -1;
  read_fail_cnt = 0;
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","read_temperature_from_CtrlBoard","read_temperature_from_CtrlBoard");
  snprintf(tmp1,0x100,"Start %s","read_temperature_from_CtrlBoard");
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != true) {
    for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
      gCtrlBoard_sensor_addr[i] = gCtrlBoard_sensor_i2c_addr + gCtrlBoard_sensor_low_3_bits_addr[i];
    }
    iVar2 = tsensor_open(gChain,gCtrlBoard_sensor_addr,(uint8_t)gCtrlBoard_sensor_num);
    if (iVar2 < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s: chain %d tsensor_open failed\n\n","read_temperature_from_CtrlBoard",
             "read_temperature_from_CtrlBoard",gChain);
      snprintf(tmp1,0x100,"%s: chain %d tsensor_open failed\n","read_temperature_from_CtrlBoard",
               gChain);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : WARNING CAN NOT OPEN TEMP SENSOR ...\n","read_temperature_from_CtrlBoard");
      builtin_strncpy(tmp1,"WARNING CAN NOT OPEN TEMP SENSOR ...",0x24);
      tmp1[0x24] = '\0';
      log_to_file(tmp1,time_stamp);
      err_exit("sensor err");
      return (void *)0x0;
    }
  }
  while( true ) {
    if (gStart_read_temp == false) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s stop\n","read_temperature_from_CtrlBoard","read_temperature_from_CtrlBoard");
      snprintf(tmp1,0x100,"%s stop","read_temperature_from_CtrlBoard");
      log_to_file(tmp1,time_stamp);
      return (void *)0x0;
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        memset(data,-1,2);
        iVar2 = tsensor_read(gChain,gCtrlBoard_sensor_addr[i],gCtrlBoard_temperature_reg_addr,
                             (uint8_t *)data,2);
        if (iVar2 == 2) {
          if ((data[0] == -1) || (data[0] == '\0')) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read CtrlBoard sensor fail,addr: %d,data[0]:%d,data[1]:%d\n",
                   "read_temperature_from_CtrlBoard",(uint)gCtrlBoard_sensor_addr[i],(int)data[0],
                   (int)data[1]);
            snprintf(tmp1,0x100,"Read CtrlBoard sensor fail,addr: %d,data[0]:%d,data[1]:%d",
                     (uint)gCtrlBoard_sensor_addr[i],(int)data[0],(int)data[1]);
            log_to_file(tmp1,time_stamp);
            gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] = false;
            read_fail_cnt = read_fail_cnt + 1;
          }
          else {
            gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] = true;
            gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_ctrlboard[i] =
                 data[0];
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read CtrlBoard sensor fail,addr: %d\n","read_temperature_from_CtrlBoard",
                 (uint)gCtrlBoard_sensor_addr[i]);
          snprintf(tmp1,0x100,"Read CtrlBoard sensor fail,addr: %d",(uint)gCtrlBoard_sensor_addr[i])
          ;
          log_to_file(tmp1,time_stamp);
          gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] = false;
          read_fail_cnt = read_fail_cnt + 1;
        }
      }
    }
    else {
      for (i = '\0'; i < (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num
          ; i = i + '\x01') {
        memset(data,0,2);
        sesnor_id_00 = (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                       switch_sensor_info[i].channel;
        if (((Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.switch_sensor_info[i].
             power_supply_ctrlboard == true) || (is_power_on == true)) {
          iVar2 = pca_switch_read((uint8_t)gChain,sesnor_id_00,
                                  (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.
                                           switch_sensor.switch_addr,
                                  (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.
                                           switch_sensor.switch_sensor_info[i].sensor_addr,data,
                                  data + 1);
          if (iVar2 == 0) {
            if ((data[0] == '\0') || (data[0] == -1)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Read switch sensor fail temp 0,sesnor_id: %d\n",
                     "read_temperature_from_CtrlBoard",(uint)sesnor_id_00);
              snprintf(tmp1,0x100,"Read switch sensor fail temp 0,sesnor_id: %d",(uint)sesnor_id_00)
              ;
              log_to_file(tmp1,time_stamp);
            }
            else {
              gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] = true;
              gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[i] =
                   data[0];
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read switch sensor fail,sesnor_id: %d\n","read_temperature_from_CtrlBoard",
                   (uint)sesnor_id_00);
            snprintf(tmp1,0x100,"Read switch sensor fail,sesnor_id: %d",(uint)sesnor_id_00);
            log_to_file(tmp1,time_stamp);
            read_fail_cnt = read_fail_cnt + 1;
          }
        }
        else {
          gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] = true;
        }
      }
    }
    temp = true;
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        temp = (gHistory_Result[gPattern_test_counter].ctrlboard_sensor_OK[i] & temp) != 0;
      }
    }
    else {
      for (i = '\0'; i < (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num
          ; i = i + '\x01') {
        temp = (gHistory_Result[gPattern_test_counter].switch_sensor_OK[i] & temp) != 0;
      }
    }
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch == false) {
      if (temp == false) {
        gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK = false;
      }
      else {
        gHistory_Result[gPattern_test_counter].ctrlboard_sensor_all_OK = true;
      }
    }
    else if (temp == false) {
      gHistory_Result[gPattern_test_counter].switch_sensor_all_ok = false;
    }
    else {
      gHistory_Result[gPattern_test_counter].switch_sensor_all_ok = true;
    }
    if (((gStart_receive != false) && (gHeating != true)) && (gCooling != true)) {
      iVar2 = get_ctrlboard_temp_max();
      set_pwm_by_temp(iVar2);
    }
    gTemp_first_read_flag = true;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    iVar2 = get_ctrlboard_temp_max();
    iVar3 = get_ctrlboard_temp_min();
    printf("%s : Temp max:%d,min:%d\n","read_temperature_from_CtrlBoard",iVar2,iVar3);
    iVar2 = get_ctrlboard_temp_max();
    iVar3 = get_ctrlboard_temp_min();
    snprintf(tmp1,0x100,"Temp max:%d,min:%d",iVar2,iVar3);
    log_to_file(tmp1,time_stamp);
    for (i_1 = 0; i_1 < 4; i_1 = i_1 + 1) {
      iVar2 = fan_get_realtime_speed(i_1);
      speed[i_1] = iVar2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fan:[%d][%d][%d][%d]\n","read_temperature_from_CtrlBoard",speed[0],speed[1],
           speed[2],speed[3]);
    snprintf(tmp1,0x100,"fan:[%d][%d][%d][%d]",speed[0],speed[1],speed[2],speed[3]);
    log_to_file(tmp1,time_stamp);
    if (0 < read_fail_cnt) break;
    iVar2 = get_ctrlboard_temp_max();
    iVar3 = get_ctrlboard_temp_min();
    _Var1 = board_temp_protect_check((int8_t)iVar2,(int8_t)iVar3);
    if (!_Var1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : WARNING TEMP OUT OF PROTECT...\n","read_temperature_from_CtrlBoard");
      builtin_strncpy(tmp1,"WARNING TEMP OUT OF PROTECT...",0x1f);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar2 = get_ctrlboard_temp_max();
      iVar3 = get_ctrlboard_temp_min();
      printf("%s : WARNING temp[0]:%d,temp[1]:%d\n","read_temperature_from_CtrlBoard",iVar2,iVar3);
      iVar2 = get_ctrlboard_temp_max();
      iVar3 = get_ctrlboard_temp_min();
      snprintf(tmp1,0x100,"WARNING temp[0]:%d,temp[1]:%d",iVar2,iVar3);
      log_to_file(tmp1,time_stamp);
      err_exit("temp high");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    get_all_fan_speed();
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : WARNING READ TEMP SENSOR ERR...\n","read_temperature_from_CtrlBoard");
  builtin_strncpy(tmp1,"WARNING READ TEMP SENSOR ERR...",0x20);
  log_to_file(tmp1,time_stamp);
  err_exit("sensor err");
                    /* WARNING: Subroutine does not return */
  exit(1);
}


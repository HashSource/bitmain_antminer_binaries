
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool temp_sensor_check(void)

{
  byte sesnor_id_00;
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int8_t asic_temp;
  int8_t pcb_temp;
  uint8_t gCtrlBoard_sensor_addr [2];
  uint8_t data [2];
  uint8_t sensor_dev_addr;
  uint8_t switch_dev_addr;
  uint8_t sesnor_id;
  int TESTC_CNT_1;
  int TESTC_CNT;
  int32_t ret;
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  pcb_temp = '\0';
  asic_temp = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","temp_sensor_check","temp_sensor_check");
  snprintf(tmp1,0x100,"Start %s","temp_sensor_check");
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_CtrlBoard == false) {
    if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Switch != false) {
      for (j = '\0'; j < 5; j = j + '\x01') {
        for (i = '\0';
            i < (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.sensor_num;
            i = i + '\x01') {
          pcb_temp = '\0';
          asic_temp = '\0';
          sesnor_id_00 = (Local_Config_Information->Hash_Board).Sensor_Info.switch_sensor.
                         switch_sensor_info[i].channel;
          iVar1 = pca_switch_read((uint8_t)gChain,sesnor_id_00,
                                  (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.
                                           switch_sensor.switch_addr,
                                  (uint8_t)(Local_Config_Information->Hash_Board).Sensor_Info.
                                           switch_sensor.switch_sensor_info[i].sensor_addr,&pcb_temp
                                  ,&asic_temp);
          if (iVar1 != 0) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read switch sensor fail,sesnor_id: %d, ret = %d\n","temp_sensor_check",
                   (uint)sesnor_id_00,iVar1);
            snprintf(tmp1,0x100,"Read switch sensor fail,sesnor_id: %d, ret = %d",(uint)sesnor_id_00
                     ,iVar1);
            log_to_file(tmp1,time_stamp);
            return false;
          }
          if (pcb_temp == '\0') {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read switch sensor fail temp 0,sesnor_id: %d\n","temp_sensor_check",
                   (uint)sesnor_id_00);
            snprintf(tmp1,0x100,"Read switch sensor fail temp 0,sesnor_id: %d",(uint)sesnor_id_00);
            log_to_file(tmp1,time_stamp);
            return false;
          }
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sensor[%d],local temp:[%d], remote temp:[%d]\n","temp_sensor_check",(uint)i,
                 (int)pcb_temp,(int)asic_temp);
          snprintf(tmp1,0x100,"sensor[%d],local temp:[%d], remote temp:[%d]",(uint)i,(int)pcb_temp,
                   (int)asic_temp);
          log_to_file(tmp1,time_stamp);
          usleep(5000);
        }
      }
    }
  }
  else {
    for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
      gCtrlBoard_sensor_addr[i] = gCtrlBoard_sensor_i2c_addr + gCtrlBoard_sensor_low_3_bits_addr[i];
    }
    iVar1 = tsensor_open(gChain,gCtrlBoard_sensor_addr,(uint8_t)gCtrlBoard_sensor_num);
    if (iVar1 < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s: chain %d tsensor_open failed\n\n","temp_sensor_check","temp_sensor_check",
             gChain);
      snprintf(tmp1,0x100,"%s: chain %d tsensor_open failed\n","temp_sensor_check",gChain);
      log_to_file(tmp1,time_stamp);
      return false;
    }
    for (j = '\0'; j < 5; j = j + '\x01') {
      for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
        memset(data,0,2);
        iVar1 = tsensor_read(gChain,gCtrlBoard_sensor_addr[i],gCtrlBoard_temperature_reg_addr,data,2
                            );
        if (iVar1 != 2) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read CtrlBoard sensor fail,addr: %d\n","temp_sensor_check",
                 (uint)gCtrlBoard_sensor_addr[i]);
          snprintf(tmp1,0x100,"Read CtrlBoard sensor fail,addr: %d",(uint)gCtrlBoard_sensor_addr[i])
          ;
          log_to_file(tmp1,time_stamp);
          return false;
        }
        if (data[0] == '\0') {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read CtrlBoard sensor fail,temp is 0,pls makesure env temp.\n",
                 "temp_sensor_check");
          builtin_strncpy(tmp1,"Read CtrlBoard sensor fail,temp is 0,pls makesure env temp.",0x3c);
          log_to_file(tmp1,time_stamp);
          return false;
        }
        if ((j + 1) % 10 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sensor[%d],temp:[%d]\n","temp_sensor_check",(uint)i,(uint)data[0]);
          snprintf(tmp1,0x100,"sensor[%d],temp:[%d]",(uint)i,(uint)data[0]);
          log_to_file(tmp1,time_stamp);
        }
        usleep(5000);
      }
    }
  }
  return true;
}


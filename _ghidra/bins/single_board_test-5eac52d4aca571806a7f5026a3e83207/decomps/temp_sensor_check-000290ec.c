
/* WARNING: Unknown calling convention */

_Bool temp_sensor_check(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t gCtrlBoard_sensor_addr [4];
  int8_t data [2];
  int k;
  int TESTC_CNT;
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  gCtrlBoard_sensor_addr[2] = '\0';
  gCtrlBoard_sensor_addr[3] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s %d\n","temp_sensor_check","temp_sensor_check",gCtrlBoard_sensor_num);
  snprintf(tmp1,0x100,"Start %s %d","temp_sensor_check",gCtrlBoard_sensor_num);
  log_to_file(tmp1,time_stamp);
  for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
    gCtrlBoard_sensor_addr[i] = gCtrlBoard_sensor_i2c_addr + gCtrlBoard_sensor_low_3_bits_addr[i];
  }
  j = '\0';
  do {
    if (1 < j) {
      return true;
    }
    for (i = '\0'; i < gCtrlBoard_sensor_num; i = i + '\x01') {
      memset(data,0,2);
      iVar1 = pca_switch_read((uint8_t)gChain,'\x01','p','L',data,data + 1);
      if (iVar1 != 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read HashBoard sensor fail,addr: %d\n","temp_sensor_check",
               (uint)gCtrlBoard_sensor_addr[i]);
        snprintf(tmp1,0x100,"Read HashBoard sensor fail,addr: %d",(uint)gCtrlBoard_sensor_addr[i]);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      if (data[0] == '\0') {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read HashBoard sensor fail,temp is 0,pls makesure env temp.\n",
               "temp_sensor_check");
        builtin_strncpy(tmp1,"Read HashBoard sensor fail,temp is 0,pls makesure env temp.",0x3c);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : only test sensor[%d],local_temp:[%d], remote_temp:[%d]\n","temp_sensor_check",1,
             (int)data[0],(int)data[1]);
      snprintf(tmp1,0x100,"only test sensor[%d],local_temp:[%d], remote_temp:[%d]",1,(int)data[0],
               (int)data[1]);
      log_to_file(tmp1,time_stamp);
      usleep(10000);
    }
    j = j + '\x01';
  } while( true );
}


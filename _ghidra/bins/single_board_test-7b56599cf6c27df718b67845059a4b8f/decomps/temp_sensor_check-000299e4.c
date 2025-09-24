
/* WARNING: Unknown calling convention */

_Bool temp_sensor_check(void)

{
  int32_t iVar1;
  _Bool _Var2;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t gCtrlBoard_sensor_addr [2];
  uint8_t data [2];
  int TESTC_CNT;
  int32_t ret;
  _Bool temp;
  uint8_t j;
  uint8_t i;
  
  data[0] = '\0';
  data[1] = '\0';
  gCtrlBoard_sensor_addr[0] = '\0';
  gCtrlBoard_sensor_addr[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","temp_sensor_check","temp_sensor_check");
  snprintf(tmp1,0x100,"Start %s","temp_sensor_check");
  log_to_file(tmp1,time_stamp);
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
    _Var2 = false;
  }
  else {
    for (j = '\0'; j < 100; j = j + '\x01') {
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
    _Var2 = true;
  }
  return _Var2;
}


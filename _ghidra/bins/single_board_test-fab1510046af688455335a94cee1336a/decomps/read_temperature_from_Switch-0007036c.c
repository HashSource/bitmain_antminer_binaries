
void * read_temperature_from_Switch(void *arg)

{
  int32_t iVar1;
  uint uVar2;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t gCtrlBoard_sensor_addr [2];
  int8_t data [2];
  int32_t temp;
  uint8_t i;
  int index;
  uint8_t sleep_counter;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Start %s\n","read_temperature_from_Switch","read_temperature_from_Switch");
  snprintf(tmp1,0x800,"Start %s","read_temperature_from_Switch");
  log_to_file(tmp1,time_stamp);
  while (gStart_read_temp != false) {
    for (index = 0; index < 0xc; index = index + 1) {
      iVar1 = read_sensor_on_switch(gChain,index);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: index: %d  temp :%d\n","read_temperature_from_Switch",index,iVar1);
      snprintf(tmp1,0x800,"index: %d  temp :%d",index,iVar1);
      log_to_file(tmp1,time_stamp);
      if (iVar1 == 0) {
        gHistory_Result[gPattern_test_counter].switch_sensor_OK[index] = false;
      }
      else {
        gHistory_Result[gPattern_test_counter].switch_sensor_OK[index] = true;
        gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[index] =
             (int8_t)iVar1;
      }
    }
    sleep_counter = '\0';
    while ((gStart_read_temp != false &&
           (uVar2 = (uint)sleep_counter, sleep_counter = sleep_counter + '\x01',
           uVar2 < gRead_Pic_Temperature_time_interval))) {
      sleep(1);
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: %s stop\n","read_temperature_from_Switch","read_temperature_from_Switch");
  snprintf(tmp1,0x800,"%s stop","read_temperature_from_Switch");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}


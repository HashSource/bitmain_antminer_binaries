
_Bool waiting_cool_down(uint32_t max_wait_time,int8_t *temp,int8_t sensor_num,int gap)

{
  int iVar1;
  int iVar2;
  int gap_local;
  int8_t sensor_num_local;
  int8_t *temp_local;
  uint32_t max_wait_time_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  uint32_t wait_time;
  _Bool result;
  
  wait_time = 0;
  do {
    iVar1 = pf_get_max_value(temp,(int)sensor_num);
    iVar2 = pf_get_min_value(temp,(int)sensor_num);
    if ((iVar1 - iVar2 < gap) && (iVar1 = pf_get_min_value(temp,(int)sensor_num), iVar1 < 0x29)) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Hashboard cool down, begin test ...\n","waiting_cool_down");
      builtin_strncpy(tmp1,"Hashboard cool down, begin test ...",0x24);
      log_to_file(tmp1,time_stamp);
      return true;
    }
    sleep(1);
    wait_time = wait_time + 1;
    if (wait_time % 10 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Waiting for Hashboard cool down for %d seconds ...\n","waiting_cool_down",
             wait_time);
      snprintf(tmp1,0x100,"Waiting for Hashboard cool down for %d seconds ...",wait_time);
      log_to_file(tmp1,time_stamp);
    }
  } while (wait_time <= max_wait_time);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Wait for Hashboard cool down for %d seconds, break\n","waiting_cool_down",wait_time);
  snprintf(tmp1,0x100,"Wait for Hashboard cool down for %d seconds, break",wait_time);
  log_to_file(tmp1,time_stamp);
  return false;
}


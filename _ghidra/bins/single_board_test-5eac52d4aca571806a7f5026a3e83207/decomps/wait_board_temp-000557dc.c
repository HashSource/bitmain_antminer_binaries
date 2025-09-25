
int wait_board_temp(int8_t *tempval,int8_t sensor_num,int32_t target_temp)

{
  int32_t target_temp_local;
  int8_t sensor_num_local;
  int8_t *tempval_local;
  char time_stamp [48];
  char tmp1 [256];
  int k;
  int32_t temp;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : wait board temp come to %d\n","wait_board_temp",target_temp);
  snprintf(tmp1,0x100,"wait board temp come to %d",target_temp);
  log_to_file(tmp1,time_stamp);
  temp = pf_get_max_value(tempval,(int)sensor_num);
  k = 0;
  if (target_temp != 0) {
    do {
      if (target_temp + -3 <= temp) {
        return 0;
      }
      temp = pf_get_max_value(tempval,(int)sensor_num);
      sleep(1);
      k = k + 1;
      if (k % 5 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : k:%d\n","wait_board_temp",k);
        snprintf(tmp1,0x100,"k:%d",k);
        log_to_file(tmp1,time_stamp);
        print_fan_speed();
      }
    } while (k < 0x12d);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : can not warm up to target temp:%d!!!\n","wait_board_temp",target_temp);
    snprintf(tmp1,0x100,"can not warm up to target temp:%d!!!",target_temp);
    log_to_file(tmp1,time_stamp);
  }
  return 0;
}


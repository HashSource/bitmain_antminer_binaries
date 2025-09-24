
void * pic_heart_beat_func(void *arg)

{
  int32_t iVar1;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t sleep_counter;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s\n","pic_heart_beat_func","pic_heart_beat_func");
  snprintf(tmp1,0x100,"%s","pic_heart_beat_func");
  log_to_file(tmp1,time_stamp);
  while (gStart_heart_beat != false) {
    iVar1 = send_pic_heart_beat((uint8_t)gChain);
    if (iVar1 != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Pic heart beat fail\n","pic_heart_beat_func");
      builtin_strncpy(tmp1,"Pic heart beat fail",0x14);
      log_to_file(tmp1,time_stamp);
    }
    sleep_counter = '\0';
    while ((gStart_heart_beat != false && (sleep_counter < 10))) {
      sleep(1);
      sleep_counter = sleep_counter + '\x01';
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s stop\n","pic_heart_beat_func","pic_heart_beat_func");
  snprintf(tmp1,0x100,"%s stop","pic_heart_beat_func");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}


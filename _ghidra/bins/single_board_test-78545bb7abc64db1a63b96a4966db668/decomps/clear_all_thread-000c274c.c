
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_all_thread(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  gStart_receive = false;
  gStart_read_temp_from_pic = false;
  gStart_read_temp_from_asic = false;
  gStart_heart_beat = false;
  gStart_read_temp = false;
  gStart_show_on_lcd = false;
  if (send_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : send_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"send_id",8);
    log_to_file(tmp1,time_stamp);
    pthread_join(send_id,(void **)0x0);
    send_id = 0;
  }
  if (receive_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : receive_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"receive_",8);
    tmp1[8] = 'i';
    tmp1[9] = 'd';
    tmp1[10] = '\0';
    log_to_file(tmp1,time_stamp);
    pthread_join(receive_id,(void **)0x0);
    receive_id = 0;
  }
  if (show_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : show_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"show_id",8);
    log_to_file(tmp1,time_stamp);
    pthread_join(show_id,(void **)0x0);
    show_id = 0;
  }
  if (pic_heart_beat_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : pic_heart_beat_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"pic_heart_beat_i",0x10);
    tmp1[0x10] = 'd';
    tmp1[0x11] = '\0';
    log_to_file(tmp1,time_stamp);
    pthread_join(pic_heart_beat_id,(void **)0x0);
    pic_heart_beat_id = 0;
  }
  if (read_temp_from_pic_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : read_temp_from_pic_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"read_temp_from_pic_i",0x14);
    tmp1[0x14] = 'd';
    tmp1[0x15] = '\0';
    log_to_file(tmp1,time_stamp);
    pthread_join(read_temp_from_pic_id,(void **)0x0);
    read_temp_from_pic_id = 0;
  }
  if (read_temp_from_asic_id != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : read_temp_from_asic_id\n","clear_all_thread");
    builtin_strncpy(tmp1,"read_temp_from_asic_",0x14);
    tmp1[0x14] = 'i';
    tmp1[0x15] = 'd';
    tmp1[0x16] = '\0';
    log_to_file(tmp1,time_stamp);
    pthread_join(read_temp_from_asic_id,(void **)0x0);
    read_temp_from_asic_id = 0;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : clear all thread.\n","clear_all_thread");
  builtin_strncpy(tmp1,"clear all thread",0x10);
  tmp1[0x10] = '.';
  tmp1[0x11] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}


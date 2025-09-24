
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_threads(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : stop threads enter\n","stop_threads");
  builtin_strncpy(tmp1,"stop threads ent",0x10);
  tmp1[0x10] = 'e';
  tmp1[0x11] = 'r';
  tmp1[0x12] = '\0';
  log_to_file(tmp1,time_stamp);
  g_rt.read_temp = 0;
  g_rt.recv_nonce = 0;
  g_pwm_enable = false;
  if (g_power_handle != 0) {
    pthread_cancel(g_power_handle);
  }
  sleep(5);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : stop threads end\n","stop_threads");
  builtin_strncpy(tmp1,"stop threads end",0x10);
  tmp1._16_2_ = tmp1._16_2_ & 0xff00;
  log_to_file(tmp1,time_stamp);
  return;
}


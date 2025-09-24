
/* WARNING: Unknown calling convention */

int start_temp_thread(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int ret;
  
  g_rt.read_temp = 1;
  iVar1 = pthread_create(&g_temp_handle,(pthread_attr_t *)0x0,(__start_routine *)0x57559,&g_rt);
  if (iVar1 == 0) {
    while (g_rt.tempval[0] == '\0') {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : can not read senor temp\n","start_temp_thread");
      builtin_strncpy(tmp1,"can not read senor temp",0x18);
      log_to_file(tmp1,time_stamp);
      sleep(1);
    }
    iVar1 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : create read temp thread failed\n","start_temp_thread");
    builtin_strncpy(tmp1,"create read temp thread fail",0x1c);
    tmp1[0x1c] = 'e';
    tmp1[0x1d] = 'd';
    tmp1[0x1e] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return iVar1;
}



/* WARNING: Unknown calling convention */

int32_t create_power_heart_beat_thread(void)

{
  int iVar1;
  int32_t iVar2;
  char time_stamp [48];
  char tmp1 [256];
  int ret;
  
  iVar1 = pthread_create(&g_power_handle,(pthread_attr_t *)0x0,(__start_routine *)0x5c905,
                         (void *)0x0);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : create send work thread failed\n","create_power_heart_beat_thread");
    builtin_strncpy(tmp1,"create send work thread fail",0x1c);
    tmp1[0x1c] = 'e';
    tmp1[0x1d] = 'd';
    tmp1[0x1e] = '\0';
    log_to_file(tmp1,time_stamp);
    iVar2 = -1;
  }
  return iVar2;
}



_Bool set_time_based_notify_ntime(char *ntime)

{
  uint uVar1;
  _Bool _Var2;
  char *ntime_local;
  char time_stamp [48];
  char tmp1 [2048];
  timeval stime;
  uint32_t ntime_value;
  
  uVar1 = strtol(ntime,(char **)0x0,0x10);
  if ((set_time_based_notify_ntime::set_os_time == true) || (uVar1 == 0)) {
    _Var2 = false;
  }
  else {
    stime.tv_sec = 0;
    stime.tv_usec = 0;
    gettimeofday((timeval *)&stime,(__timezone_ptr_t)0x0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ntime_value:%d\n","set_time_based_notify_ntime",uVar1);
    snprintf(tmp1,0x800,"ntime_value:%d",uVar1);
    log_to_file(tmp1,time_stamp);
    if ((uint)stime.tv_sec < uVar1) {
      stime.tv_sec = uVar1;
      settimeofday((timeval *)&stime,(timezone *)0x0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: settime notify.ntime successfuly, ntimeValue:%d\n","set_time_based_notify_ntime",
             uVar1);
      snprintf(tmp1,0x800,"settime notify.ntime successfuly, ntimeValue:%d",uVar1);
      log_to_file(tmp1,time_stamp);
      set_time_based_notify_ntime::set_os_time = true;
      _Var2 = true;
    }
    else {
      _Var2 = false;
    }
  }
  return _Var2;
}


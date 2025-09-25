
int get_time_from_web(char *url)

{
  char *__haystack;
  char *__haystack_00;
  uint uVar1;
  int iVar2;
  char *url_local;
  char time_stamp [48];
  char real_date [100];
  char tmp1 [256];
  timeval stime;
  uint32_t time_seconds;
  char *date_response_start;
  char *response;
  char *date_response_end;
  
  __haystack = http_get(url,false,true);
  if (__haystack == (char *)0x0) {
    iVar2 = -1;
  }
  else {
    __haystack_00 = strstr(__haystack,"Date:");
    date_response_end = (char *)0x0;
    if (__haystack_00 != (char *)0x0) {
      date_response_end = strstr(__haystack_00,"\r\n");
    }
    memset(real_date,0,100);
    if (date_response_end != (char *)0x0) {
      memcpy(real_date,__haystack_00,(int)date_response_end - (int)__haystack_00);
    }
    uVar1 = get_abs_seconds(real_date + 0xb);
    stime.tv_sec = 0;
    stime.tv_usec = 0;
    gettimeofday((timeval *)&stime,(__timezone_ptr_t)0x0);
    if ((uint)stime.tv_sec < uVar1) {
      stime.tv_sec = uVar1;
      settimeofday((timeval *)&stime,(timezone *)0x0);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : set time successfuly, time_seconds:%d\n","get_time_from_web",uVar1);
      snprintf(tmp1,0x100,"set time successfuly, time_seconds:%d",uVar1);
      log_to_file(tmp1,time_stamp);
    }
    free(__haystack);
    iVar2 = 0;
  }
  return iVar2;
}


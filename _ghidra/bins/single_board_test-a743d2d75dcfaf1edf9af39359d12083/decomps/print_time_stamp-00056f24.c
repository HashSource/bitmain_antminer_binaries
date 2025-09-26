
void print_time_stamp(char *datetime,int len)

{
  int iVar1;
  int len_local;
  char *datetime_local;
  time_t tmp_time;
  tm tm1;
  timeval tv;
  int ms;
  
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  tmp_time = tv.tv_sec;
  iVar1 = tv.tv_usec / 1000;
  localtime_r(&tmp_time,(tm *)&tm1);
  snprintf(datetime,len,"[%d-%02d-%02d %02d:%02d:%02d.%03d]",tm1.tm_year + 0x76c,tm1.tm_mon + 1,
           tm1.tm_mday,tm1.tm_hour,tm1.tm_min,tm1.tm_sec,iVar1);
  return;
}


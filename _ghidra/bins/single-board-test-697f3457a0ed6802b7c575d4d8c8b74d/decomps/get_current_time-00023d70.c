
void get_current_time(char *dtime)

{
  int iVar1;
  tm *ptVar2;
  char *dtime_local;
  time_t tmp_time;
  timeval tv;
  char datetime [64];
  tm *tm;
  int ms;
  
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  tmp_time = tv.tv_sec;
  iVar1 = tv.tv_usec / 1000;
  ptVar2 = localtime(&tmp_time);
  snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar2->tm_year + 0x76c,
           ptVar2->tm_mon + 1,ptVar2->tm_mday,ptVar2->tm_hour,ptVar2->tm_min,ptVar2->tm_sec,iVar1);
  strcpy(dtime,datetime);
  return;
}



void get_timestamp(char *f,size_t fsiz,timeval *tv)

{
  timeval *tv_local;
  size_t fsiz_local;
  char *f_local;
  time_t tmp_time;
  tm *tm;
  int ms;
  
  tmp_time = tv->tv_sec;
  ms = tv->tv_usec / 1000;
  tm = (tm *)localtime(&tmp_time);
  snprintf(f,fsiz,"[%02d:%02d:%02d.%03d]",((tm *)tm)->tm_hour,((tm *)tm)->tm_min,((tm *)tm)->tm_sec,
           ms);
  return;
}


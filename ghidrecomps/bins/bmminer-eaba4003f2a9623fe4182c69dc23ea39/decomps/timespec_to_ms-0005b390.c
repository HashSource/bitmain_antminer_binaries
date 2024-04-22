
int timespec_to_ms(timespec *ts)

{
  timespec *ts_local;
  
  return ts->tv_sec * 1000 + ts->tv_nsec / 1000000;
}


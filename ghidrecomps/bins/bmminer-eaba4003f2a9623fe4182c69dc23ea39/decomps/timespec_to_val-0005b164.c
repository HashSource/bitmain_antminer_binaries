
void timespec_to_val(timeval *val,timespec *spec)

{
  timespec *spec_local;
  timeval *val_local;
  
  val->tv_sec = spec->tv_sec;
  val->tv_usec = spec->tv_nsec / 1000;
  return;
}


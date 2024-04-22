
void timeval_to_spec(timespec *spec,timeval *val)

{
  timeval *val_local;
  timespec *spec_local;
  
  spec->tv_sec = val->tv_sec;
  spec->tv_nsec = val->tv_usec * 1000;
  return;
}


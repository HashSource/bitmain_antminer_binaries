
void cgtime(timeval *tv)

{
  timeval *tv_local;
  
  gettimeofday((timeval *)tv,(__timezone_ptr_t)0x0);
  return;
}


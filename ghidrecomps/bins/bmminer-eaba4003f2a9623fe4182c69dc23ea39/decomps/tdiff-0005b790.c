
double tdiff(timeval *end,timeval *start)

{
  timeval *start_local;
  timeval *end_local;
  
  return (double)(longlong)(end->tv_sec - start->tv_sec) +
         (double)(longlong)(end->tv_usec - start->tv_usec) / DAT_0005b7d8;
}


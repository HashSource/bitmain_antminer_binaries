
double us_tdiff(timeval *end,timeval *start)

{
  double dVar1;
  timeval *start_local;
  timeval *end_local;
  
  dVar1 = DAT_0005b728;
  if (end->tv_sec - start->tv_sec < 0x3d) {
    dVar1 = (double)(longlong)
                    ((end->tv_sec - start->tv_sec) * 1000000 + (end->tv_usec - start->tv_usec));
  }
  return dVar1;
}


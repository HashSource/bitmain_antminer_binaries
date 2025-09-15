
int ms_tdiff(timeval *end,timeval *start)

{
  int iVar1;
  timeval *start_local;
  timeval *end_local;
  
  if (end->tv_sec - start->tv_sec < 0xe11) {
    iVar1 = (end->tv_sec - start->tv_sec) * 1000 + (end->tv_usec - start->tv_usec) / 1000;
  }
  else {
    iVar1 = 3600000;
  }
  return iVar1;
}


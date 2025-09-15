
void addtime(timeval *a,timeval *b)

{
  timeval *b_local;
  timeval *a_local;
  
  b->tv_sec = a->tv_sec + b->tv_sec;
  b->tv_usec = a->tv_usec + b->tv_usec;
  if (999999 < b->tv_usec) {
    b->tv_sec = b->tv_sec + 1;
    b->tv_usec = b->tv_usec + -1000000;
  }
  return;
}


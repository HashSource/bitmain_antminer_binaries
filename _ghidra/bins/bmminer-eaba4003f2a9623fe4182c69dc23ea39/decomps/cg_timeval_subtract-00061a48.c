
int cg_timeval_subtract(timeval *result,timeval *x,timeval *y)

{
  int iVar1;
  timeval *y_local;
  timeval *x_local;
  timeval *result_local;
  int nsec;
  
  if (y->tv_sec < x->tv_sec) {
    iVar1 = -1;
  }
  else if ((x->tv_sec == y->tv_sec) && (y->tv_usec < x->tv_usec)) {
    iVar1 = -1;
  }
  else {
    result->tv_sec = y->tv_sec - x->tv_sec;
    result->tv_usec = y->tv_usec - x->tv_usec;
    if (result->tv_usec < 0) {
      result->tv_sec = result->tv_sec + -1;
      result->tv_usec = result->tv_usec + 1000000;
    }
    iVar1 = 0;
  }
  return iVar1;
}


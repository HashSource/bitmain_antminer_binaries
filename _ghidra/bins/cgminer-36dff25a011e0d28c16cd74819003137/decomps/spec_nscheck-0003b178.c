
void spec_nscheck(timespec *ts)

{
  timespec *ts_local;
  
  while (999999999 < ts->tv_nsec) {
    ts->tv_nsec = ts->tv_nsec + -1000000000;
    ts->tv_sec = ts->tv_sec + 1;
  }
  while (ts->tv_nsec < 0) {
    ts->tv_nsec = ts->tv_nsec + 1000000000;
    ts->tv_sec = ts->tv_sec + -1;
  }
  return;
}

